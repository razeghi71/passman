#include "aes_crypto.h"
#include "cryptopp/filters.h"

AESCrypto::AESCrypto(string key) : Encryption(key)
{
    while ( key.length() != AES::DEFAULT_KEYLENGTH)
        key+="0";

    this->key = key;
}

string AESCrypto::encrypt(string message)
{
    encryptor = CTR_Mode<AES>::Encryption((unsigned char *)key.data(),key.size(),(unsigned char *)"0");

    std::string cipher;
    StringSource ss1( message , true,
            new StreamTransformationFilter( encryptor,
                new StringSink( cipher )
            ) // StreamTransformationFilter
        ); // StringSource
    return cipher;
}

string AESCrypto::decrypt(string cipher)
{
    decryptor = CTR_Mode<AES>::Decryption((unsigned char *)key.data(),key.size(),(unsigned char *)"0");

    std::string plain;
    StringSource ss1( cipher, true,
            new StreamTransformationFilter( decryptor,
                new StringSink( plain )
            ) // StreamTransformationFilter
        ); // StringSource
    return plain;
}
