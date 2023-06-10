#include "stream_rc4.h"

void swap(unsigned char &x,unsigned char &y)//交换
{
    unsigned char temp = x;
    x = y;
    y = temp;
}

QString Stream::encrypt(const QString &plainText)//加密
{
       QString cipherText = "";
       int plainSize = plainText.size();
       for (int i = 0; i < plainSize; ++i) {
           cipherText += plainText.at(i).toLatin1() ^ static_cast<char>(getKeyByte() & 0xFF);
       }
       return cipherText;
}

void Stream::init(const char *key)//初始化
{
        int keyLen = strlen(key);
        for (unsigned int i = 0; i < 256; ++i)
        {
            S[i] = (char)i;
            T[i] = key[i % keyLen];
        }
        int j = 0;
        for (int i = 0; i < 256; ++i)
        {
            j = (j + S[i] + T[i]) % 256;
            swap(S[i], S[j]);
        }
        i = 0;
        j = 0;
}

int Stream::getKeyByte()//获取密钥
{
       i = (i + 1) % 256;
       j = (j + S[i]) % 256;
       swap(S[i], S[j]);
       return S[(S[i] + S[j]) % 256];
}
