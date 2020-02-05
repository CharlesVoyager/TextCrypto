#pragma once
#include <string>

/*
Purposes: Static link OpenSSL v1.0.2 library to perform DES-CBC encryption and decryption.
*/
namespace EncryptProxy
{
	std::string DesCbcEncrypt(std::string source, std::string inputKey, std::string inputIv);
	std::string DesCbcDecrypt(std::string source, std::string inputKey, std::string inputIv);
}