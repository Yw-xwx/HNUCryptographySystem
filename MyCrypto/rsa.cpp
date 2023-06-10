#include "rsa.h"

bool Rsa::judge_prime(int n)
{
    int sqrt_n = sqrt(n);
    for(int i = 2;i<=sqrt_n;i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int Rsa::calculate_y(int a,int x,int n)
{//a^x mod n
    if(x == 1)
        return a%n;
    if(x&1)
        return a*calculate_y(a,x-1,n)%n;
    else
    {
        int temp = calculate_y(a,x/2,n)%n;
        return temp*temp%n;
    }
}
//加密、解密之前都要记录原来的消息位数,进来多少位就要输出多少位
//每个分组,算完之后的位数不到分组长度,要补充前导0
//事先遇到有前导0的数据,正常分组,去掉前导0再计算,最后再补足前导0到分组长度
QString Rsa::solve(QString message,int power,int n)//message^power mod n
{
    QString result = "";
    int len = message.length();
    for(int i = 0;i<len;i++)
    {
        int temp = message.at(i).unicode();
        temp = calculate_y(temp,power,n);
        result += QChar(temp);
    }
    return result;
}
