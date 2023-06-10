#ifndef STREAM_H
#define STREAM_H
#include <cstring>
#include <QString>
#include "MyCrypto_global.h"

class MYCRYPTO_EXPORT Stream{
public:
    Stream(const char *key) {init(key); }
    ~Stream() {memset(S, 0, sizeof(S));}
    QString encrypt(const QString &plainText);
    QString decrypt(const QString &cipherText) {        return encrypt(cipherText);}
private:
    unsigned char S[256];
    unsigned char T[256];
    int i, j;
    void init(const char *key);
    int getKeyByte();
};

#endif // STREAM_H
