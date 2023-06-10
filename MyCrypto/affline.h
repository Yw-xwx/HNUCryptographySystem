#ifndef AFFLINE_H
#define AFFLINE_H
#include "MyCrypto_global.h"
#include <QMessageBox>
#include <QString>

class MYCRYPTO_EXPORT Affline
{//仿射加密要求k1和26互素
//加密时y=k1*x+k2 (mod 26)
//解密时x=k1^-1*(y-k2) (mod 26)
public:
    int k1,k2;//在槽函数中用来传递参数给en\decryption函数
    QString plain_text;
    QString cipher_text;
    int gcd(int a,int b);
    void exgcd(int a,int b,int &x,int &y);
    int eula(int k,int n);//欧拉函数求逆元
    QString encryption(int k1,int k2);
    QString decryption(int k1,int k2);
};

#endif // AFFLINE_H
