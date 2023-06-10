#include "affline.h"
#include <QDebug>

int Affline::gcd(int m,int k1)//互素
{
    if(k1 != 0)
        return this->gcd(k1,m%k1);
    else
        return m;
}

QString Affline::encryption(int k1,int k2)//加密
{
    if(gcd(26,k1) != 1)
        return "error";
    this->plain_text = this->plain_text.toUpper();//当前对象的明文字符串全部变成大写
    QByteArray byte_array = this->plain_text.toUtf8();
    int len = this->plain_text.size();
    QString temp_string;
    for(int i = 0;i<len;i++)
    {
       int temp = byte_array[i] - 'A';
       temp = (k1*temp + k2)%26;
       temp_string += (temp+'A');
    }
    this->cipher_text = temp_string;
    return this->cipher_text;
}

QString Affline::decryption(int k1, int k2)//解密
{
    this->cipher_text = this->cipher_text.toUpper();
    QByteArray byte_array = this->cipher_text.toUtf8();
    int len = this->cipher_text.size();
    QString temp_string;
    for(int i = 0;i<len;i++)
    {
       int temp = byte_array[i] - 'A';
       temp = (k1*(temp - k2))%26;
       while(temp < 0)
           temp += 26;
       temp_string += (temp+'A');
    }
    this->plain_text = temp_string;
    return this->plain_text;
}

void Affline::exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
    }
    else
    {
        exgcd(b, a%b ,y,x);
        y -= a/b * x;
    }
}

int Affline::eula(int x,int n)//计算x在模26下的逆元
{
    if (x == 1 || x == n-1)
        return x;
    int y,z;
    this->exgcd(x,n,y,z);
    return (y%n+n)%n;
}
