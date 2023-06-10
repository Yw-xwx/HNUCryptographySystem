#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QIcon>
#include <QMessageBox>
#include <QCryptographicHash>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void newConnect();
    void myReceive();
private:
    QTcpServer server;
    QTcpSocket *socket = new QTcpSocket;
    QLabel *situation = new QLabel("等待客户端连接",this);
    QLineEdit *text_receive = new QLineEdit("",this);
    QPushButton *btn_send = new QPushButton("发送公开密钥Yb",this);
    QPushButton *btn_x = new QPushButton("Xb",this);
    QLineEdit *text_x = new QLineEdit("",this);
    QPushButton *btn_cal = new QPushButton("计算",this);
    QPushButton *btn_y = new QPushButton("Yb",this);
    QLineEdit *text_y = new QLineEdit("",this);
    QHBoxLayout *layout_x = new QHBoxLayout;
    QHBoxLayout *layout_y = new QHBoxLayout;
    QVBoxLayout *layout_main = new QVBoxLayout;
    int calculate_y(int a,int b,int n);
    QString solve(QString message,int b,int n);
};

#endif // MAINWINDOW_H
