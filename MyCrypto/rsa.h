#ifndef RSA_H
#define RSA_H
#include "affline.h"
#include <QtMath>
#include "MyCrypto_global.h"
//输入p,q,e、检查pq是否素数、e和eula_n的互素性、求e mod eula_n的逆元d
class MYCRYPTO_EXPORT Rsa:public Affline
{
public:
    QString solve(QString message,int b,int n);
    int p,q,e,d,fai;
    int api_power(int a,int b,int n){ return this->calculate_y(a,b,n);};//提供一个接口
    int api_prime(int n){return judge_prime(n);};
private:
    bool judge_prime(int n);
    int calculate_y(int a,int b,int n);
};

#endif // RSA_H
