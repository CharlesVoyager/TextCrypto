# TextCrypto
Text Cryptography Tool

"TextCrypto" includes a DLL(TextCryptoDll.dll) and a test AP (TextCryptoAp.exe). The software architecture is as below.
 
TextCryptoDll.dll provides the following two APIs that can be easily used for encrypting the text and decrypting the text.

bool desEncrypt(const char *plainText, char *outValue, int maxLength, const char *key, const char *iv);
bool desDecrypt(const char *cipherText, char *outValue, int maxLength, const char *key, const char *iv);

TextCryptoAp.exe provides a dialog based Windows application by calling TextCryptoDll.dll to encrypt the text and decryp the text.

Compiling
=========
- Visual Studio 2017

Using it
========
- Compile TextCryptoDll. The filename is TextCryptoDll.dll.
- Compile TextCryptoAp. The filename is TextCryptoAp.exe.
- The binary DLL and executable file will be generated in the .\x64\Release (or .\x64\Debug) folder. Run TextCrypto.exe and then enter the text in the Plaintext edit control. Click "Encode" button to encrypt the text. The cipher text will be displayed in the Ciphertext edit control.