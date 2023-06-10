#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("服务器端");
    setWindowIcon(QIcon(":/window.jpg"));
    setMinimumSize(1000,750);
    setMaximumSize(1000,750);
    QFont f("宋体",24);
    situation->setFont(f);
    text_receive->setPlaceholderText("接收的数据");
    situation->setGeometry(350,20,500,100);//situation是连接状态,在顶部
    btn_x->setGeometry(100,150,50,50);
    text_x->setGeometry(180,150,200,50);
    btn_cal->setGeometry(500,150,200,50);
    btn_y->setGeometry(100,300,50,50);
    text_y->setGeometry(180,300,200,50);
    btn_send->setGeometry(500,300,200,50);//发送按钮
    text_receive->setGeometry(100,500,600,200);//接收框
    text_x->setPlaceholderText("输入服务器选择的Xb");
    text_y->setPlaceholderText("计算对应的Yb");
    layout_x->addWidget(btn_x);
    layout_x->addWidget(text_x);
    layout_y->addWidget(btn_y);
    layout_y->addWidget(text_y);
    layout_main->addWidget(situation);
    layout_main->addWidget(text_receive);
    layout_main->addLayout(layout_x);
    layout_main->addLayout(layout_y);
    server.listen(QHostAddress::Any,8888);
    connect(&server,SIGNAL(newConnection()),this,SLOT(newConnect()));//检测新连接
    connect(btn_cal,&QPushButton::clicked,this,[=]()//点击计算
    {
        int temp = text_x->text().toInt();
        text_y->setText(QString::number(calculate_y(5,temp,97)));
    });
    connect(btn_send,&QPushButton::clicked,this,[=]()//点击发送公开密钥Yb
    {
        QByteArray array = "";
        array.append(text_y->text());
        socket->write(array);
        qInfo() << "已成功发送Yb:" << text_y->text().toInt();
    });
}

void MainWindow::newConnect()
{
    this->situation->setText("发现新客户端连接");
    if(server.hasPendingConnections())//连接建立就准备接收数据
    {
        socket = server.nextPendingConnection();
        connect(socket,SIGNAL(readyRead()),this,SLOT(myReceive()));
    }
}

void MainWindow::myReceive()//数据接收函数
{
    QByteArray array = socket->readAll();
    QString str_receive = QString::fromUtf8(array);
    QString str_signature = "",str_plain = "";//接收到的数据"明文你哈希的签名值",用"你"分隔
    int i = 0;
    while(true)
    {
        if(str_receive[i].unicode() != 20320)
            str_plain += str_receive[i++];
        else
            break;
    }
    i++;//跳过间隔符
    int len = str_receive.length();
    for(;i<len;i++)
        str_signature += str_receive[i];//传输的数字签名
    QString str_verification = solve(str_signature,13,43*59);//解开签名得到的验证哈希值
    QString str_hash;
    QCryptographicHash hash(QCryptographicHash::Sha1);
    hash.addData(str_plain.toUtf8());
    str_hash = hash.result().toHex();//明文哈希得到的哈希值
    if(str_hash != str_verification)
        QMessageBox::warning(this,"错误!","消息被篡改,哈希值匹配失败");
    else
    {
        QMessageBox::information(this,"成功!",QString("完整性和来源验证通过\n客户端发送的Ya=%1").arg(str_plain.toInt()));
        int K = this->calculate_y(str_plain.toInt(),text_x->text().toInt(),97);
        text_receive->setText(QString("最终的会话密钥K=%1").arg(K));
    }
}

int MainWindow::calculate_y(int a,int x,int n)//快速幂计算
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

QString MainWindow::solve(QString message,int power,int n)//message^power mod n
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

MainWindow::~MainWindow()
{
    socket->deleteLater();
    delete situation;
    situation = nullptr;
    delete text_receive;
    text_receive = nullptr;
    delete btn_send;
    btn_send = nullptr;
    delete btn_x;
    btn_x = nullptr;
    delete text_x;
    text_x= nullptr;
    delete btn_cal;
    btn_cal= nullptr;
    delete btn_y;
    btn_y= nullptr;
    delete text_y;
    text_y = nullptr;
    delete layout_x;
    layout_x = nullptr;
    delete layout_y;
    layout_y = nullptr;
    delete layout_main;
    layout_main = nullptr;
}
