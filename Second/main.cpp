#include <QApplication>
#include <mainwindow.h>

// main.cpp
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
