#ifndef STREAM_JK_H
#define STREAM_JK_H

#include <bitset>
#include <string>
#include <QString>
#include <QChar>

// LFSR模板类
template <int size>
class LFSR {
public:
    LFSR(const QString& seed) : lfsr_(seed.toStdString()), key_(seed) {}
    void shift()
    {
        //bool feedback = lfsr_[0] ^ lfsr_[2] ^ lfsr_[3] ^ lfsr_[5] ^ lfsr_[size - 1];

        bool feedback = lfsr_[0];
        for (int i = 0; i < size; ++i) {
            if (key_[i]=='1')
               feedback ^= lfsr_[i];
        }

        lfsr_ >>= 1;
        lfsr_[size - 1] = feedback;
    }
    bool lfsr_output() const {return lfsr_[0];}
    void set_seed(const QString& seed){lfsr_ = std::bitset<size>(seed.toStdString());}
private:
    std::bitset<size> lfsr_;
    const QString& key_;
};

// JK触发器类
class JK_FlipFlop {
public:
    bool jk_output(bool j, bool k)
    {
        bool keybit;
        if (j == false && k == false)//00保持不变
            keybit = current_status_ ? true : false;
        else if (j == false && k == true)
            keybit = false;
        else if (j == true && k == false)
            keybit = true;
        else if (j == true && k == true)//11翻转
            keybit = current_status_ ? false : true;
        current_status_ = keybit;
        return keybit;
    }
    void set_initial_state(bool state) {current_status_ = state;}
private:
    bool current_status_;
};

QString work_init(QString plaintext, QString key);
// 流密码加密函数
template <int size1, int size2>
QString encrypt(const QString& plaintext, LFSR<size1>& lfsr1, LFSR<size2>& lfsr2, JK_FlipFlop& jk);
// 流密码解密函数与加密过程相同
template <int size1, int size2>
QString decrypt(const QString& ciphertext, LFSR<size1>& lfsr1, LFSR<size2>& lfsr2, JK_FlipFlop& jk);

#endif // STREAM_JK_H
