#include "mainwindow.h"
#include "affline.h"
#include "stream_rc4.h"
#include "stream_jk.h"
#include "des.h"
#include "rsa.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("综合加解密服务系统");
    setWindowIcon(QIcon(":/safe.jpg"));
    setMaximumSize(1440,960);
    setMinimumSize(1320,800);
    QPalette p = this->palette();
    QPixmap pix(":/hello.jpg");
    p.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(p);
    QFont f("宋体",20);
    title->setStyleSheet("border-radius: 20px; font-size: 40pt; font-family: KaiTi ; color: #6633ff; background-color: transparent;");
    title->setFont(f);
    layout_title->addStretch();
    layout_title->addWidget(title);
    layout_title->addStretch();
    centralWidget = new QStackedWidget(this);
    btn_dh->setStyleSheet(qss_btn);
    btn_des->setStyleSheet(qss_btn);
    btn_rsa->setStyleSheet(qss_btn);
    btn_affline->setStyleSheet(qss_btn);
    btn_stream_rc4->setStyleSheet(qss_btn);
    btn_stream_jk->setStyleSheet(qss_btn);
    btn_dh->setFixedSize(300,100);
    btn_des->setFixedSize(150,75);
    btn_rsa->setFixedSize(150,75);
    btn_stream_rc4->setFixedSize(200,75);
    btn_stream_jk->setFixedSize(200,75);
    btn_affline->setFixedSize(150,75);
    layout_choice->addWidget(btn_affline);
    layout_choice->addWidget(btn_stream_rc4);
    layout_choice->addWidget(btn_stream_jk);
    layout_choice->addWidget(btn_des);
    layout_choice->addWidget(btn_rsa);
    layout_dh->addStretch();
    layout_dh->addWidget(btn_dh);
    layout_dh->addStretch();
    mainLayout->addStretch();
    mainLayout->addLayout(layout_title);
    mainLayout->addStretch();
    mainLayout->addLayout(layout_choice);
    mainLayout->addStretch();
    mainLayout->addLayout(layout_dh);
    mainLayout->addStretch();
    //创建两个子界面,并且把界面A、B的切换界面信号和stackwidget的设置界面索引函数相关联
    Widget_affline *widget_affline = new Widget_affline;
    connect(widget_affline, &Widget_affline::switchPage, centralWidget, &QStackedWidget::setCurrentIndex);
    Widget_stream_rc4 *widget_stream_rc4 = new Widget_stream_rc4;
    connect(widget_stream_rc4, &Widget_stream_rc4::switchPage, centralWidget, &QStackedWidget::setCurrentIndex);
    Widget_stream_jk *widget_stream_jk = new Widget_stream_jk;
    connect(widget_stream_jk, &Widget_stream_jk::switchPage, centralWidget, &QStackedWidget::setCurrentIndex);
    Widget_des *widget_des = new Widget_des;
    connect(widget_des,&Widget_des::switchPage,centralWidget,&QStackedWidget::setCurrentIndex);
    Widget_rsa *widget_rsa = new Widget_rsa;
    connect(widget_rsa,&Widget_des::switchPage,centralWidget,&QStackedWidget::setCurrentIndex);
    Widget_dh *widget_dh = new Widget_dh;
    connect(widget_dh,&Widget_dh::switchPage,centralWidget,&QStackedWidget::setCurrentIndex);
    //将界面（QWidget）添加到 QStackedWidget 并设置初始界面
    centralWidget->addWidget(widgetStart);
    centralWidget->addWidget(widget_affline);
    centralWidget->addWidget(widget_stream_rc4);
    centralWidget->addWidget(widget_stream_jk);
    centralWidget->addWidget(widget_des);
    centralWidget->addWidget(widget_rsa);
    centralWidget->addWidget(widget_dh);
    centralWidget->setCurrentIndex(0);
    //设置 MainWindow 的 Central Widget
    setCentralWidget(centralWidget);
    //给初始界面的按钮们的点击信号,关联到设置当前界面
    connect(btn_affline, &QPushButton::clicked, [=](){centralWidget->setCurrentIndex(1);});
    connect(btn_stream_rc4, &QPushButton::clicked, [=](){centralWidget->setCurrentIndex(2);});
    connect(btn_stream_jk, &QPushButton::clicked, [=](){centralWidget->setCurrentIndex(3);});
    connect(btn_des,&QPushButton::clicked,[=](){centralWidget->setCurrentIndex(4);});
    connect(btn_rsa,&QPushButton::clicked,[=](){centralWidget->setCurrentIndex(5);});
    connect(btn_dh,&QPushButton::clicked,[=](){centralWidget->setCurrentIndex(6);});
}

MainWindow::~MainWindow()
{
    delete btn_affline;
    btn_affline = nullptr;
    delete btn_stream_rc4;
    btn_stream_rc4 = nullptr;
    delete btn_stream_jk;
    btn_stream_jk = nullptr;
    delete btn_des;
    btn_des = nullptr;
    delete btn_rsa;
    btn_rsa = nullptr;
    delete  title;
    title = nullptr;
    delete  btn_dh;
    btn_dh = nullptr;
    delete layout_dh;
    layout_dh = nullptr;
    delete layout_choice;
    layout_choice = nullptr;
    delete layout_title;
    layout_title = nullptr;
    delete mainLayout;
    mainLayout=nullptr;
    delete widgetStart;
    widgetStart = nullptr;
    delete centralWidget;
    centralWidget = nullptr;
}

Widget_base::Widget_base(QWidget* parent):QWidget(parent)
{
    btn_back->setStyleSheet(qss_btn_top);
    btn_encryption->setStyleSheet(qss_btn_top);
    btn_decryption->setStyleSheet(qss_btn_top);
    btn_key->setStyleSheet(qss_btn_left);
    btn_key2->setStyleSheet(qss_btn_left);
    btn_plain->setStyleSheet(qss_btn_left);
    btn_cipher->setStyleSheet(qss_btn_left);
    //返回、加密、解密的水平布局
    btn_back->setFixedSize(150,80);
    btn_encryption->setFixedSize(150,80);
    btn_decryption->setFixedSize(150,80);
    layout_back->addStretch(1);
    layout_back->addWidget(btn_back);
    layout_back->addStretch(6);
    layout_back->addWidget(btn_encryption);
    layout_back->addStretch(1);
    layout_back->addWidget(btn_decryption);
    layout_back->addStretch(1);
    //密钥的水平布局
    btn_key->setFocusPolicy(Qt::NoFocus);
    btn_key2->setFocusPolicy(Qt::NoFocus);
    btn_key->setFixedSize(100,50);
    btn_key2->setFixedSize(100,50);
    text_key->setStyleSheet(qss_text);
    text_key2->setStyleSheet(qss_text);
    text_plain->setStyleSheet(qss_text);
    text_cipher->setStyleSheet(qss_text);
    text_key->setPlaceholderText("请输入整数k1");
    text_key->setFixedSize(250,50);
    text_key2->setPlaceholderText("请输入整数k2");
    text_key2->setFixedSize(250,50);
    layout_key->addWidget(btn_key);
    layout_key->addWidget(text_key);
    layout_key->addWidget(btn_key2);
    layout_key->addWidget(text_key2);
    layout_key->setSpacing(50);
    //明文的水平布局
    btn_plain->setFocusPolicy(Qt::NoFocus);
    btn_plain->setFixedSize(100,50);
    text_plain->setPlaceholderText("这里是待加密的明文/解密得到的明文");
    text_plain->setFixedSize(600,50);
    layout_plain->addWidget(btn_plain);
    layout_plain->addWidget(text_plain);
    layout_plain->setSpacing(50);
    //密文的水平布局
    btn_cipher->setFocusPolicy(Qt::NoFocus);
    btn_cipher->setFixedSize(100,50);
    text_cipher->setPlaceholderText("这里是加密得到的密文/待解密的密文");
    text_cipher->setFixedSize(600,50);
    layout_cipher->addWidget(btn_cipher);
    layout_cipher->addWidget(text_cipher);
    layout_cipher->setSpacing(50);
    layout_back->setGeometry(QRect(0,10,1000,100));
    layout_key->setGeometry(QRect(20,200,1000,100));
    layout_plain->setGeometry(QRect(50,400,500,100));
    layout_cipher->setGeometry(QRect(50,600,500,100));
    //总体的垂直布局layout_main,以及返回按钮
    layout_main->addLayout(layout_back);
    layout_main->addLayout(layout_key);
    layout_main->addLayout(layout_rsa);
    layout_main->addLayout(layout_plain);
    layout_main->addLayout(layout_cipher);
    layout_main->setSpacing(100);
    connect(btn_back, &QPushButton::clicked, [=]()
    {
        emit switchPage(0);
        text_key->clear();
        text_key2->clear();
        text_plain->clear();
        text_cipher->clear();
        text_e->clear();
        text_fai->clear();
    });
}

Widget_affline::Widget_affline(QWidget* parent): Widget_base(parent)
{
    text_e->hide();
    text_fai->hide();
    btn_e->hide();
    btn_fai->hide();
    btn_judge_gcd->hide();
    btn_key->setText("密钥k1");
    connect(btn_encryption,&QPushButton::clicked,[=]()
    {
        affline_object->plain_text = text_plain->text();
        affline_object->k1 = text_key->text().toInt();
        affline_object->k2 = text_key2->text().toInt();
        affline_object->cipher_text = affline_object->encryption(affline_object->k1,affline_object->k2);
        if(affline_object->cipher_text == "error")
            QMessageBox::warning(this,"错误!","你输入的k1和模数26并不互素,请重新选择k1");
        else
        {
            text_cipher->setText(affline_object->cipher_text);
            QMessageBox::information(this,"成功!",QString("加密完成,密文是:%1").arg(text_cipher->text()));
        }
    });
    connect(btn_decryption,&QPushButton::clicked,[=]()
    {
        Affline *affline_object = new Affline;
        affline_object->cipher_text = text_cipher->text();
        affline_object->k1 = text_key->text().toInt();
        affline_object->k2 = text_key2->text().toInt();
        int reverse_k1 = affline_object->eula(affline_object->k1,26);
        affline_object->plain_text = affline_object->decryption(reverse_k1,affline_object->k2);
        text_plain->setText(affline_object->plain_text);
        QMessageBox::information(this,"成功!",QString("解密完成,明文是:%1").arg(text_plain->text()));
    });
}

Widget_stream_rc4::Widget_stream_rc4(QWidget *parent) : Widget_base(parent)
{
    text_e->hide();
    text_fai->hide();
    btn_e->hide();
    btn_fai->hide();
    btn_judge_gcd->hide();
    text_key->setPlaceholderText("请输入种子密钥key");
    btn_key2->hide();
    text_key2->hide();
    connect(btn_encryption,&QPushButton::clicked,[=]()
    {
        QString key = text_key->text();//读取种子密钥
        QString plain_text = text_plain->text();//读取明文
        Stream stream_object(key.toUtf8().constData());//新建流密码对象
        QString cipher_text = stream_object.encrypt(plain_text);//调用函数加密,返回密文
        text_cipher->setText(cipher_text);//输出密文到文本框
        QMessageBox::information(this,"成功!",QString("加密完成,密文是:%1").arg(text_cipher->text()));
    });
    connect(btn_decryption,&QPushButton::clicked,[=]()
    {
        QString key = text_key->text();
        QString cipher_text = text_cipher->text();
        Stream stream_object(key.toUtf8().constData());
        QString plain_text = stream_object.decrypt(cipher_text);
        text_plain->setText(plain_text);
        QMessageBox::information(this,"成功!",QString("解密完成,明文是:%1").arg(text_plain->text()));
    });
}

Widget_stream_jk::Widget_stream_jk(QWidget *parent) : Widget_base(parent)
{
    text_e->hide();
    text_fai->hide();
    btn_e->hide();
    btn_fai->hide();
    btn_judge_gcd->hide();
    text_key->setPlaceholderText("请输入种子密钥key");
    btn_key2->hide();
    text_key2->hide();
    connect(btn_encryption,&QPushButton::clicked,[=]()
    {
        QString key = text_key->text();//读取种子密钥
        QString plain_text = text_plain->text();//读取明文
        QString cipher_text = work_init(plain_text, key);
        text_cipher->setText(cipher_text);//输出密文到文本框
        QMessageBox::information(this,"成功!",QString("加密完成,密文是:%1").arg(text_cipher->text()));
    });
    connect(btn_decryption,&QPushButton::clicked,[=]()
    {
        QString key = text_key->text();
        QString cipher_text = text_cipher->text();
        QString plain_text = work_init(cipher_text, key);
        text_plain->setText(plain_text);
        QMessageBox::information(this,"成功!",QString("解密完成,明文是:%1").arg(text_plain->text()));
    });
}

Widget_des::Widget_des(QWidget* parent):Widget_base(parent)
{//密钥k---AABB09182736CCDD//明文-----123456ABCD132536//密文-----C0B7A8D05F3A829C
    text_e->hide();
    text_fai->hide();
    btn_e->hide();
    btn_fai->hide();
    btn_judge_gcd->hide();
    text_key->setPlaceholderText("请输入密钥k");
    text_key2->hide();
    btn_key2->hide();
    connect(btn_encryption,&QPushButton::clicked,[=]()
    {
        std::string key = text_key->text().toStdString();
        std::string plainText = text_plain->text().toStdString();
        Des temp;
        QString cipher = QString::fromStdString(temp.encryption(plainText,key));
        text_cipher->setText(cipher);
        QMessageBox::information(this,"成功!",QString("加密完成,密文是:%1").arg(text_cipher->text()));
    });
    connect(btn_decryption,&QPushButton::clicked,[=]()
    {
        std::string key = text_key->text().toStdString();
        std::string cipherText = text_cipher->text().toStdString();
        Des temp;
        QString plain = QString::fromStdString(temp.decryption(cipherText,key));
        text_plain->setText(plain);
        QMessageBox::information(this,"成功!",QString("解密完成,明文是:%1").arg(text_plain->text()));
    });
}

Widget_rsa::Widget_rsa(QWidget *parent):Widget_base(parent)
{
    btn_key->setText("素数p");
    text_key->setPlaceholderText("输入素数p");
    btn_key2->setText("素数q");
    text_key2->setPlaceholderText("输入素数q");
    text_e->setPlaceholderText("注意e要和φ(n)互素");
    text_fai->setPlaceholderText("φ(n)=(p-1)(q-1)");
    layout_rsa->addWidget(btn_e);
    layout_rsa->addWidget(text_e);
    layout_rsa->addWidget(btn_fai);
    layout_rsa->addWidget(text_fai);
    layout_rsa->addWidget(btn_judge_gcd);
    layout_rsa->setSpacing(50);
    btn_e->setFixedSize(100,50);
    btn_fai->setFixedSize(100,50);
    text_e->setFixedSize(200,50);
    text_fai->setFixedSize(200,50);
    btn_judge_gcd->setFixedSize(250,100);
    btn_e->setStyleSheet(qss_btn_left);
    btn_judge_gcd->setStyleSheet("border-radius: 10px; font-size: 20pt; font-family: Microsoft Yahei ; color: red; background-color: white;");
    btn_fai->setStyleSheet(qss_btn_left);
    text_e->setStyleSheet(qss_text);
    text_fai->setStyleSheet(qss_text);
    layout_key->setGeometry(QRect(50,130,1000,100));
    layout_rsa->setGeometry(QRect(50,250,1000,100));
    btn_e->setFocusPolicy(Qt::NoFocus);
    btn_fai->setFocusPolicy(Qt::NoFocus);
    btn_judge_gcd->setFocusPolicy(Qt::NoFocus);
    connect(btn_judge_gcd,&QPushButton::clicked,this,[=]()
    {
        r->p = text_key->text().toInt();
        r->q = text_key2->text().toInt();
        if(r->api_prime(r->p) && r->api_prime(r->q))
        {
            r->fai = (r->p-1)*(r->q-1);
            r->e = text_e->text().toInt();
            text_fai->setText(QString::number(r->fai));
            if(r->gcd(r->e,r->fai) != 1)
                QMessageBox::warning(this,"错误!","你选择的e和φ(n)并不互素,请重新选择e");
            else
            {
                QMessageBox::StandardButton reply = QMessageBox::question(this,"互素!","是否要继续计算e在模φ(n)下的逆元d?",QMessageBox::Yes|QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                    r->d = r->eula(r->e,r->fai);
                    QMessageBox::information(this,"成功!", QString("公钥对是:(%1,%2)\n私钥对是:(%3,%2)").arg(r->e).arg(r->fai).arg(r->d));
                }
            }
        }
        else
            QMessageBox::warning(this,"错误!",QString("你输入的p=%1、q=%2,请检查是否为素数后重新输入!").arg(r->p).arg(r->q));
    });
    connect(btn_encryption,&QPushButton::clicked,this,[=]()
    {
        text_cipher->setText(r->solve(text_plain->text(),r->e,r->p*r->q));
        QMessageBox::information(this,"成功!",QString("加密完成,密文是:%1").arg(text_cipher->text()));
    });
    connect(btn_decryption,&QPushButton::clicked,this,[=]()
    {
        text_plain->setText(r->solve(text_cipher->text(),r->d,r->p*r->q));
        QMessageBox::information(this,"成功!",QString("解密完成,明文是:%1").arg(text_plain->text()));
    });
}

/*注意:在DH协议中,原有的按钮等大多数用作了其他用途,不再是变量名所代表的含义,特此说明:
第一排:
    返回按钮-----仍用于返回主界面;
    加密按钮-----用于请求连接服务器;
    解密按钮-----用于密钥交换;
后续排:
    密钥key的按钮、输入框----用于客户端选择的整数Xa;
    密钥key2的按钮----点击即计算Xa对应的Ya;(文本框隐藏)
    明文按钮、输入框-----用于指示Ya和显示Ya;
    密文按钮、输入框-----用于指示会话密钥K和显示会话密钥K.
*/
Widget_dh::Widget_dh(QWidget* parent):Widget_base(parent)
{
    text_e->hide();
    text_fai->hide();
    btn_e->hide();
    btn_fai->hide();
    btn_judge_gcd->hide();
    btn_encryption->setText("请求通信");
    btn_decryption->setText("发送公开密钥Ya");
    btn_decryption->setFixedWidth(300);
    btn_key->setText("Xa");
    text_key->setPlaceholderText("请输入客户端选择的随机数Xa");
    btn_key2->setText("计算Ya");
    text_key2->hide();
    btn_key2->setFixedSize(100,100);
    btn_plain->setText("Ya");
    btn_cipher->setText("K");
    text_plain->setPlaceholderText("这里是客户端计算出的公开密钥Ya");
    text_cipher->setPlaceholderText("这里是客户端计算得出的共享会话密钥K");
    text_ip->setPlaceholderText("请输入要连接的服务器IP地址");
    text_port->setPlaceholderText("请输入要连接的服务器端口号");
    text_ip->setFixedSize(300,50);
    text_port->setFixedSize(300,50);
    btn_ip->setFixedSize(120,80);
    btn_port->setFixedSize(180,80);
    layout_connect->addWidget(btn_ip);
    layout_connect->addWidget(text_ip);
    layout_connect->addWidget(btn_port);
    layout_connect->addWidget(text_port);
    layout_connect->setSpacing(50);
    layout_connect->setGeometry(QRect(100,66,1000,200));
    layout_key->setGeometry(QRect(74,240,1000,100));
    layout_plain->setGeometry(QRect(100,400,500,100));
    layout_cipher->setGeometry(QRect(100,600,500,100));
    btn_ip->setStyleSheet("border-radius: 10px; font-size: 20pt; font-family: KaiTi ; color: black; background-color:white;");
    btn_port->setStyleSheet("border-radius: 10px; font-size: 20pt; font-family: KaiTi ; color: black; background-color:white;");
    btn_ip->setFocusPolicy(Qt::NoFocus);
    btn_port->setFocusPolicy(Qt::NoFocus);
    connect(btn_key2,&QPushButton::clicked,this,[=]()
    {//由X计算Y
        int x = text_key->text().toInt();
        text_plain->setText(QString::number(this->api_power(5,x,97)));//Y显示在原明文框里,number函数是把整数转成QString
    });
    connect(btn_encryption,&QPushButton::clicked,this,[=]()
    {//建立连接
        QString ip = text_ip->text();
        int port = text_port->text().toInt();
        socket->connectToHost(QHostAddress(ip),port);
    });
    connect(socket,SIGNAL(connected()),this,SLOT(myConnect()));
    connect(btn_decryption,&QPushButton::clicked,this,[=]()
    {//发送数据
        //先用SHA-1对消息Ya摘要
        QByteArray send = "";
        send.append(text_plain->text());
        send.append(QChar(20320));
        QCryptographicHash hash(QCryptographicHash::Sha1);
        hash.addData(text_plain->text().toUtf8());
        QString str_hash = hash.result().toHex();
        //接下来用RSA签名,公钥e=13,私钥d=937
        this->p = 43;
        this->q = 59;
        this->e = 13;
        this->fai = (this->p-1)*(this->q-1);
        this->d = this->eula(this->e,this->fai);
        QString str_signed = this->solve(str_hash,this->d,this->p*this->q);
        send.append(str_signed);
        socket->write(send);
    });
}

Widget_base::~Widget_base()
{
    delete btn_key;
    btn_key=nullptr;
    delete btn_key2;
    btn_key2=nullptr;
    delete btn_plain;
    btn_plain=nullptr;
    delete btn_cipher;
    btn_cipher=nullptr;
    delete btn_back;
    btn_back=nullptr;
    delete btn_encryption;
    btn_encryption=nullptr;
    delete btn_decryption;
    btn_decryption=nullptr;
    delete btn_e;
    btn_e=nullptr;
    delete btn_fai;
    btn_fai=nullptr;
    delete btn_judge_gcd;
    btn_judge_gcd=nullptr;
    delete text_key;
    text_key=nullptr;
    delete text_key2;
    text_key2=nullptr;
    delete text_plain;
    text_plain=nullptr;
    delete text_cipher;
    text_cipher=nullptr;
    delete text_e;
    text_e=nullptr;
    delete text_fai;
    text_fai=nullptr;
    delete layout_key;
    layout_key=nullptr;
    delete layout_cipher;
    layout_cipher=nullptr;
    delete layout_plain;
    layout_plain=nullptr;
    delete layout_back;
    layout_back=nullptr;
    delete layout_rsa;
    layout_rsa=nullptr;
    delete layout_main;
    layout_main=nullptr;
}
Widget_affline::~Widget_affline()
{
    delete affline_object;
    affline_object = nullptr;
}
Widget_stream_rc4::~Widget_stream_rc4(){}
Widget_stream_jk::~Widget_stream_jk(){}
Widget_des::~Widget_des(){}
Widget_dh::~Widget_dh()
{
    socket->deleteLater();
    delete text_ip;
    text_ip = nullptr;
    delete text_port;
    text_port = nullptr;
    delete  btn_ip;
    btn_ip = nullptr;
    delete btn_port;
    btn_port = nullptr;
    delete layout_connect;
    layout_connect = nullptr;
}
Widget_rsa::~Widget_rsa()
{
    delete r;
    r = nullptr;
}

void Widget_dh::myConnect()
{
    qInfo() << "连接成功\n";
    connect(socket,SIGNAL(readyRead()),this,SLOT(myReceive()));
}

void Widget_dh::myReceive()
{
    QByteArray array = socket->readAll();
    QString str = "";
    str.append(array);
    int K = this->api_power(str.toInt(),text_key->text().toInt(),97);
    text_cipher->setText("最终的会话密钥K="+QString::number(K));
}
