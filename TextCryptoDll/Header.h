#pragma once
#include <string>

#ifdef TEXTCRYPTODLL_EXPORTS
#define TEXTCRYPTODLL_API __declspec(dllexport)
#else
#define TEXTCRYPTODLL_API __declspec(dllimport)
#endif

//#region EncryptProxy
/*
	Assume the size of the input plainText is nPlainTextLength.
	Then, the application should allocate the buffer size for storing the cipher text by following the formula below.

	maxLength: ((nPlainTextLength + 8 + 3) / 3) * 4;	// Plaintext ---> PKCS#5 padding ---> DES CBC Encode ---> Base64 encode
	key: Can be NULL. If it is null pointer, the default key will be used.
	iv: Can be NULL. If it is null pointer, the default iv will be used.
*/
extern "C" TEXTCRYPTODLL_API bool desEncrypt(const char *plainText, char *outValue, int maxLength, const char *key, const char *iv);
/*
	maxLength: Because the size of the decoded text won't exceed the size of the cipher text, allocate the output buffer size same as cipher text.
	key: Can be NULL. If it is null pointer, the default key will be used.
	iv: Can be NULL. If it is null pointer, the default iv will be used.
*/
extern "C" TEXTCRYPTODLL_API bool desDecrypt(const char *cipherText, char *outValue, int maxLength, const char *key, const char *iv);