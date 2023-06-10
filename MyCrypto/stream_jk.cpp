#include "stream_jk.h"

// 流密码加密函数
template <int size1, int size2>
QString encrypt(const QString& plaintext, LFSR<size1>& lfsr1, LFSR<size2>& lfsr2, JK_FlipFlop& jk)
{
    QString ciphertext = "";
    for (QChar c : plaintext) {
        std::bitset<8> plaintextByte(c.toLatin1());
        std::bitset<8> cipherByte;
        for (int i = 0; i < 8; ++i) {
            bool keybit = jk.jk_output(lfsr1.lfsr_output(), lfsr2.lfsr_output());
            cipherByte[i] = keybit ^ plaintextByte[i];
            lfsr1.shift();
            lfsr2.shift();
        }

        ciphertext += static_cast<QChar>(static_cast<ushort>(cipherByte.to_ulong()));
    }
    return ciphertext;
}

// 流密码解密函数-与加密过程相同
template <int size1, int size2>
QString decrypt(const QString& ciphertext, LFSR<size1>& lfsr1, LFSR<size2>& lfsr2, JK_FlipFlop& jk)
{
    return encrypt(ciphertext, lfsr1, lfsr2, jk);
}

QString work_init(QString plaintext, QString key)
{
    QString binary_key = "";
    for (QChar c : key) {
        std::bitset<8> binaryChar(c.toLatin1());
        binary_key += QString::fromStdString(binaryChar.to_string());
    }
    QString lfsr1_seed = binary_key.mid(0, 16);
    QString lfsr2_seed = binary_key.mid(16, 15);
    bool jk_initial_state = binary_key[binary_key.size() - 1] == '1';

    LFSR<16> lfsr1(lfsr1_seed);
    LFSR<15> lfsr2(lfsr2_seed);
    JK_FlipFlop jk;
    // 设置JK触发器的初始状态
    jk.set_initial_state(jk_initial_state);
    QString ciphertext = encrypt(plaintext, lfsr1, lfsr2, jk);
    return ciphertext;
}
