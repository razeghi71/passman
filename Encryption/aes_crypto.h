#ifndef AESCRYPTO_H
#define AESCRYPTO_H

#include "encryption.h"
#include "cryptopp/aes.h"
#include "cryptopp/modes.h"
#include "cryptopp/zlib.h"
#include <string>

using namespace CryptoPP;
using namespace std;

class AESCrypto : public Encryption
{
    CTR_Mode<AES>::Encryption encryptor;
    CTR_Mode<AES>::Decryption decryptor;
    string key;
public:
    AESCrypto(string key);

    string encrypt(string message);
    string decrypt(string cypher);
};

#endif // AESCRYPTO_H
