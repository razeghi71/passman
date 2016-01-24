#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
using namespace std;

class Encryption
{
    string key;
public:
    Encryption(string key);
    virtual string encrypt(string message) = 0;
    virtual string decrypt(string cypher) = 0;
};

#endif // ENCRYPTION_H
