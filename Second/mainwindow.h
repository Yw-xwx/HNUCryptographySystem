#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QIcon>
#include <QPixmap>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QMessageBox>
#include <QCryptographicHash>
#include "rsa.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget *widgetStart = new QWidget(this);
    QPushButton *btn_affline = new QPushButton("仿射加密");
    QPushButton *btn_stream_rc4 = new QPushButton("RC4加密");
    QPushButton *btn_stream_jk = new QPushButton("LFSR-JK加密");
    QPushButton *btn_des = new QPushButton("DES加密");
    QPushButton *btn_rsa = new QPushButton("RSA加密");
    QHBoxLayout *layout_title = new QHBoxLayout;
    QLabel *title = new QLabel("欢迎来到综合加解密服务系统",this);
    QHBoxLayout *layout_choice = new QHBoxLayout;
    QPushButton *btn_dh = new QPushButton("DH协议增强设计");
    QHBoxLayout *layout_dh = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout(widgetStart);
    QString qss_btn = "border-radius: 20px; font-size: 15pt; font-family: Microsoft Yahei ; color: white; background-color: black;";
private:
    QStackedWidget *centralWidget;
};

class Widget_base: public QWidget{
    Q_OBJECT
public:
    Widget_base(QWidget *parent = nullptr);
    ~Widget_base();
    QHBoxLayout *layout_key = new QHBoxLayout;
    QHBoxLayout *layout_cipher = new QHBoxLayout;
    QHBoxLayout *layout_plain = new QHBoxLayout;
    QHBoxLayout *layout_back = new QHBoxLayout;
    QHBoxLayout *layout_rsa = new QHBoxLayout;
    QVBoxLayout *layout_main = new QVBoxLayout;
    QPushButton *btn_key = new QPushButton("密钥",this);
    QPushButton *btn_key2 = new QPushButton("密钥k2",this);
    QPushButton *btn_plain = new QPushButton("明文",this);
    QPushButton *btn_cipher = new QPushButton("密文",this);
    QPushButton *btn_back = new QPushButton("返回",this);
    QPushButton *btn_encryption = new QPushButton("加密",this);
    QPushButton *btn_decryption = new QPushButton("解密",this);
    QPushButton *btn_e = new QPushButton("输入e/d",this);
    QPushButton *btn_fai = new QPushButton("n",this);
    QPushButton *btn_judge_gcd = new QPushButton("计算φ(n)并判断\ne是否与之互素",this);
    QLineEdit *text_key = new QLineEdit("",this);
    QLineEdit *text_key2 = new QLineEdit("",this);
    QLineEdit *text_plain = new QLineEdit("",this);
    QLineEdit *text_cipher = new QLineEdit("",this);
    QLineEdit *text_e = new QLineEdit("",this);
    QLineEdit *text_fai = new QLineEdit("",this);
    QString qss_btn_top = "border-radius: 10px; font-size: 20pt; font-family: Microsoft Yahei ; color: white; background-color: black;";
    QString qss_btn_left = "border-radius: 10px; font-size: 16pt; font-family: Microsoft Yahei ; color: black; background-color:#ffffff77;";
    QString qss_text = "QLineEdit { "
                       "border: 1px solid gray; "
                       "border-radius: 10px;"
                       "}"
                       ;
signals:
    void switchPage(int pageIndex);
};

class Widget_affline : public Widget_base {
    Q_OBJECT
public:
    Widget_affline(QWidget *parent = nullptr);
    ~Widget_affline();
    Affline *affline_object = new Affline;
};

class Widget_stream_rc4 : public Widget_base {
    Q_OBJECT
public:
    Widget_stream_rc4(QWidget *parent = nullptr);
    ~Widget_stream_rc4();
};

class Widget_stream_jk : public Widget_base {
    Q_OBJECT
public:
    Widget_stream_jk(QWidget *parent = nullptr);
    ~Widget_stream_jk();
};

class Widget_des:public Widget_base{
    Q_OBJECT
public:
    Widget_des(QWidget *parent = nullptr);
    ~Widget_des();
};

class Widget_rsa:public Widget_base{
    Q_OBJECT
public:
    Widget_rsa(QWidget *parent = nullptr);
    ~Widget_rsa();
    Rsa *r = new Rsa;
};
/*注意,DH协议的用例参考书本:
选择素数p=97,原根g=5;A选择X=36,B选择X=58;A计算Y=50,B计算Y=44;最终交换生成K=75
增强设计中,采用RSA签名增强:保密素数p=43,q=59,n=2537,保密eula(n)=42*58=2436
公开公钥{e=13,n}     (e要和n互素 );保密私钥{d=e^-1,n}  (d = e^-1 mod eula(n))*/
class Widget_dh:public Widget_base,public Rsa {
    Q_OBJECT
public:
    Widget_dh(QWidget *parent = nullptr);
    ~Widget_dh();
    QTcpSocket *socket = new QTcpSocket;
    QLineEdit *text_ip = new QLineEdit("",this);
    QLineEdit *text_port = new QLineEdit("",this);
    QPushButton *btn_ip = new QPushButton("目标IP",this);
    QPushButton *btn_port = new QPushButton("目标端口号",this);
    QHBoxLayout *layout_connect = new QHBoxLayout;
private slots:
    void myConnect();
    void myReceive();
};

#endif // MAINWINDOW_H
