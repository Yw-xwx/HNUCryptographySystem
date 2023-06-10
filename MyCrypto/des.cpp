#include "des.h"
#include <QDebug>

string Des::encryption(string plainText,string key)
{
    // 输入明文plainText（十六进制），密钥Key（十六进制）
    string M = hexToTwo(plainText);
    string K = hexToTwo(key);
    //处理密钥，生成16个子密钥
    //利用规则交换表（8*7）将K转换成 K0 ;  K0(56位) = C0(28位) + D0(28位)
    string KKK = exchange(K, ExchangeRules, ExchangeRules_SIZE);
    //利用移位表转换得C1D1----C16D16,存入K_arr
    int i = 0;
    string K_arr[Key_SIZE+1];
    K_arr[0] = KKK;
    for(i=1; i<=Key_SIZE; i++)
        K_arr[i] = spiltShift(K_arr[i-1], ShiftTable[i-1]);
    //Kn（48位）= PC-2（8*6）处理 CnDn得16个子密钥，存入Key_arr
    string Key_arr[Key_SIZE];
    for(i=0; i<Key_SIZE; i++)
        Key_arr[i] = exchange(K_arr[i+1], PC_2, PC_2_SIZE);
    //用子密钥对明文加密
    //通过IP（8*8）处理M得L0（32位）  R0（32位
    string IP_M = exchange(M, IP, IP_SIZE);
    //Ln= R(n-1); Rn= L(n-1) + f(R(n- 1); Kn)迭代16次
    string L[Key_SIZE+1];
    string R[Key_SIZE+1];
    L[0] = IP_M.substr(0, M.length()/2);
    R[0] = IP_M.substr(M.length()/2);
    string it = "";
    for(i=1; i<=Key_SIZE; i++)
    {
        //将R0通过扩展置换E（8*6）从32位扩展到48位
        it = exchange(R[i-1], E, E_SIZE);
        //R0（48位）与 K1异或得E0（48位）
        it = XOR(it, Key_arr[i-1]);
        //将E0（48位）通过S盒转换成32位
        it = SBoxWork(it, SBox);
        //P盒（8*4）置换，得P0
        it = exchange(it, P, P_SIZE);
        //P0与L0进行异或，得J0
        it = XOR(it, L[i-1]);
        //左右交换位置，即R1 = J0; L1 = R0
        L[i] = R[i-1];
        R[i] = it;
    }
    /* 对R16 L16进行一次IP-1（8*8）排序得密文 */
    string res = "";
    res += R[16];
    res += L[16];
    string finalRes = Bin2Hex(exchange(res, IP_1, IP_1_SIZE));
    return finalRes;
}

string Des::decryption(string cipherText,string key)
{
    string M = hexToTwo(cipherText);
    string K = hexToTwo(key);
    //处理密钥，生成16个子密钥
    /* 利用规则交换表（8*7）将K转换成 K0 ; K0(56位) = C0(28位) + D0(28位) */
    string KKK = exchange(K, ExchangeRules, ExchangeRules_SIZE);
    /* 利用移位表转换得C1D1----C16D16,存入K_arr */
    int i = 0;
    string K_arr[Key_SIZE+1];
    K_arr[0] = KKK;
    for(i=1; i<=Key_SIZE; i++)
        K_arr[i] = spiltShift(K_arr[i-1], ShiftTable[i-1]);
    /* Kn（48位）= PC-2（8*6）处理 CnDn得16个子密钥，存入Key_arr */
    string Key_arr[Key_SIZE];
    for(i=0; i<Key_SIZE; i++)
        Key_arr[i] = exchange(K_arr[i+1], PC_2, PC_2_SIZE);
    //用子密钥对明文加密
    /* 通过IP（8*8）处理M得L0（32位）  R0（32位） */
    string IP_M = exchange(M, IP, IP_SIZE);
    /* Ln= R(n-1); Rn= L(n-1) + f(R(n- 1); Kn)迭代16次 */
    string L[Key_SIZE+1];
    string R[Key_SIZE+1];
    L[0] = IP_M.substr(0, M.length()/2);
    R[0] = IP_M.substr(M.length()/2);
    string it = "";
    for(i=1; i<=Key_SIZE; i++)
    {
        //将R0通过扩展置换E（8*6）从32位扩展到48位
        it = exchange(R[i-1], E, E_SIZE);
        //R0（48位）与 K1异或得E0（48位）
        it = XOR(it, Key_arr[16-i]);
        //将E0（48位）通过S盒转换成32位
        it = SBoxWork(it, SBox);
        //P盒（8*4）置换，得P0
        it = exchange(it, P, P_SIZE);
        //P0与L0进行异或，得J0
        it = XOR(it, L[i-1]);
        //左右交换位置，即R1 = J0; L1 = R0
        L[i] = R[i-1];
        R[i] = it;
    }
    /* 对R16 L16进行一次IP-1（8*8）排序得密文 */
    string res = "";
    res += R[16];
    res += L[16];
    string finalRes = Bin2Hex(exchange(res, IP_1, IP_1_SIZE));
    return finalRes;
}

//int转四位string  +  int十进制转string二进制
string Des::int2BinString(int n)
{
    bitset<4> bit(n);
    return bit.to_string();
}
//string十六进制转string二进制
string Des::hexToTwo(string str)
{
    string twoBin = "";
    int i;
    for(i=0; i<16; i++)
    {
        if(str[i]>='0'&&str[i]<='9')
            twoBin.append(int2BinString(str[i]));
        else if(str[i]>='A'&&str[i]<='Z')
            twoBin.append(int2BinString(str[i]-'A'+10));
        else if(str[i]>='a'&&str[i]<='z')
            twoBin.append(int2BinString(str[i]-'a'+10));

    }
    return twoBin;
}
//string二进制转int十进制
int Des::binToDec(string bin)
{
    int sum = 0;
    for(int i=0; i<bin.size(); i++)
    {
        if(bin[i]=='0' || bin[i]=='1')
        {
            sum += (bin[i]-'0') * pow(2, bin.size()-i-1);
        }
        else
        {
            qInfo()<<"非法二进制字符！"<<'\n';
            return 0;
        }
    }
    return sum;
}

//01字符转十进制
int Des::str2Dec(string str)
{
    bitset<64> bst(str);
    return (int)bst.to_ulong();
}
//64位密文转十六进制
//Bin2Hex转换表
const static string Bin_Hex[16]
{
    "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"
};
string Des::Bin2Hex(string strBin)
{
    string hex;
    int a = strBin.length()/4;
    string trans;
    for(int i = 0; i < a; i++)
    {
        trans.clear();
        trans = strBin.substr(i*4, 4);
        hex += Bin_Hex[str2Dec(trans)];
    }
    return hex;
}

//利用交换表进行置换
string Des::exchange(string str, int rule[], int x)
{
    string exchangedStr = "";
    int i, temp;
    for(i=0; i<x; i++)
    {
        temp = rule[i]-1;
        exchangedStr.append(1, str[temp]);
    }
    return exchangedStr;
}

//依据移位表进行移位
string Des::circleMove(string str, int j)
{

    string targetString = "";
    targetString.append(str.substr(j));
    targetString.append(str.substr(0, j));
    return targetString;
}
//左右两部分移位
string Des::spiltShift(string str, int j)
{
    string targetStr = "";
    string leftString = str.substr(0, str.length()/2);
    string rightString = str.substr(str.length()/2);
    targetStr.append(circleMove(leftString, j));
    targetStr.append(circleMove(rightString, j));
    return targetStr;
}
//string 异或
string Des::XOR(string str1, string str2)
{
    string targetString = "";
    for(int j=0; j<str1.length(); j++)
        targetString += ((str1[j] - '0') ^ (str2[j] - '0')) + '0';
    return targetString;
}
//S盒工作
string Des::SBoxWork(string str, int SBox[][4][16])
{
    string targetString = "";
    string temp = "";
    string x = "", y = "";
    int col = 0, row = 0;
    for(int i=0; i<str.size()/6; i++)
    {
        temp = str.substr(6*i, 6);
        x = temp.substr(0, 1)+temp.substr(5, 1);
        y = temp.substr(1, 4);
        row = binToDec(x);
        col = binToDec(y);
        targetString.append(int2BinString(SBox[i][row][col]));
    }
    return targetString;
}
