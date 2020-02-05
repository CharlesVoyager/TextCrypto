#include "stdafx.h"
#include "DesLib.h"
#include <vector>
#include <openssl/des.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

#if (_WIN64 || _WIN32)
#if _MSC_VER>=1900
_ACRTIMP_ALT FILE* __cdecl __acrt_iob_func(unsigned);
#ifdef __cplusplus
extern "C"
#endif
FILE* __cdecl __iob_func(unsigned i) {
	return __acrt_iob_func(i);
}
#endif /* _MSC_VER>=1900 */
#endif

namespace EncryptProxy
{
	namespace {
		struct BIOFreeAll { void operator()(BIO* p) { BIO_free_all(p); } };
	}

	std::string Base64Encode(const std::vector<unsigned char>& binary)
	{
		std::unique_ptr<BIO, BIOFreeAll> b64(BIO_new(BIO_f_base64()));
		BIO_set_flags(b64.get(), BIO_FLAGS_BASE64_NO_NL);
		BIO* sink = BIO_new(BIO_s_mem());
		BIO_push(b64.get(), sink);
		BIO_write(b64.get(), binary.data(), binary.size());
		BIO_flush(b64.get());
		const char* encoded;
		const long len = BIO_get_mem_data(sink, &encoded);
		return std::string(encoded, len);
	}

	// Assumes no newlines or extra characters in encoded string
	std::vector<unsigned char> Base64Decode(const char* encoded)
	{
		std::unique_ptr<BIO, BIOFreeAll> b64(BIO_new(BIO_f_base64()));
		BIO_set_flags(b64.get(), BIO_FLAGS_BASE64_NO_NL);
		BIO* source = BIO_new_mem_buf(encoded, -1); // read-only source
		BIO_push(b64.get(), source);
		const int maxlen = strlen(encoded) / 4 * 3 + 1;
		std::vector<unsigned char> decoded(maxlen);
		const int len = BIO_read(b64.get(), decoded.data(), maxlen);
		decoded.resize(len);
		return decoded;
	}

	std::string DesCbcEncrypt(std::string source, std::string inputKey, std::string inputIv)
	{
		int nPlainTextLength = source.length();
		int nBufferSize = nPlainTextLength + 9;						// extra space for PKCS#5 padding and null byte

		unsigned char *in = NULL;
		unsigned char *out = NULL;
		try
		{
			in = new unsigned char[nBufferSize];	// plain text
			out = new unsigned char[nBufferSize];	// cipher text
		}
		catch (std::bad_alloc& ba)
		{
			return "ERROR: bad_alloc caught";	//bad_alloc caught
		}

		int len;
		DES_cblock key;		//"19891202"
		DES_cblock ivsetup;	//"20030922"

		DES_key_schedule ks;
		DES_cblock ivec;

		// assign key
		for (int i = 0; i < DES_KEY_SZ; i++)	// DES_KEY_SZ should be 8
			key[i] = inputKey.at(i);

		// assign iv
		for (int i = 0; i < DES_KEY_SZ; i++)	// DES_KEY_SZ should be 8
			ivsetup[i] = inputIv.at(i);

		memset(in, 0, nBufferSize);
		memset(out, 0, nBufferSize);

		DES_set_key_unchecked(&key, &ks);

		strcpy((char *)in, source.c_str());
		len = strlen((char *)in);

		// Add PKCS#5 padding
		for (int i = len; i < len + (8 - (len % 8)); i++)
			in[i] = 8 - (len % 8);

		memcpy(ivec, ivsetup, sizeof(ivsetup));
		DES_ncbc_encrypt(in, out, strlen((char *)in), &ks, &ivec, DES_ENCRYPT);	//NOTE: the output buffer length must the same as input buffer.

		// base64 encode
		const std::vector<unsigned char>binary((char *)out, (char *)out + strlen((char *)in));	// NOTE: Don't use strlen((char *)out) to compute the length of out buffer (cipher text) because cipher text may include 0.
		const std::string encoded_base64 = Base64Encode(binary);

		// clear buffer
		if (in) delete[] in;
		if (out) delete[] out;

		return encoded_base64;
	}

	std::string DesCbcDecrypt(std::string source, std::string inputKey, std::string inputIv)
	{
		DES_cblock key;		//"19891202"
		DES_cblock ivsetup;	//"20030922"

		DES_key_schedule ks;
		DES_cblock ivec;

		// assign key
		for (int i = 0; i < DES_KEY_SZ; i++)	// DES_KEY_SZ should be 8
			key[i] = inputKey.at(i);

		// assign iv
		for (int i = 0; i < DES_KEY_SZ; i++)	// DES_KEY_SZ should be 8
			ivsetup[i] = inputIv.at(i);

		DES_set_key_unchecked(&key, &ks);

		const std::string encoded_base64 = source;

		// Decode Base64
		std::vector<unsigned char> in_cipher = Base64Decode(encoded_base64.c_str());
		if (in_cipher.size() == 0) return "";							// in case that the input parameter is empty
		std::vector<unsigned char> back_plaintext(in_cipher.size(), 0);	// create the same size as in_cipher with value 0

		memcpy(ivec, ivsetup, sizeof(ivsetup));
		DES_ncbc_encrypt(&in_cipher[0], &back_plaintext[0], in_cipher.size(), &ks, &ivec, DES_DECRYPT);

		// Removed PKCS#5 padding
		int len = back_plaintext.size();
		std::string strDecodeDES((char *)&back_plaintext[0], 0, len - back_plaintext[len - 1]);

		return strDecodeDES;
	}
}