// TextCryptoDll.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "Header.h"
#include "DesLib.h"

using namespace std;
using namespace EncryptProxy;

/*
std::string DesCbcEncrypt(std::string source, std::string inputKey, std::string inputIv);
std::string DesCbcDecrypt(std::string source, std::string inputKey, std::string inputIv);
*/

TEXTCRYPTODLL_API bool desEncrypt(const char *plainText, char *outValue, int maxLength, const char *key, const char *iv)
{
	string source(plainText);
	string inputKey(key);
	string inputIv(iv);
	string cipherText = DesCbcEncrypt(source, inputKey, inputIv);

	if (maxLength >= cipherText.length())
		strcpy(outValue, cipherText.c_str());
	else
		strcpy(outValue, cipherText.substr(0, maxLength).c_str());

	return true;
}

TEXTCRYPTODLL_API bool desDecrypt(const char *cipherText, char *outValue, int maxLength, const char *key, const char *iv)
{
	string source(cipherText);
	string inputKey(key);
	string inputIv(iv);

	string plainText = DesCbcDecrypt(source, inputKey, inputIv);

	if (maxLength >= plainText.length())
		strcpy(outValue, plainText.c_str());
	else
		strcpy(outValue, plainText.substr(0, maxLength).c_str());
	return true;
}