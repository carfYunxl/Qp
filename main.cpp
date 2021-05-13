#include "mywindow.h"
#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myWindow w;
    w.show();
    //    mainwindow w2;
//    w2.show();
    return a.exec();
}
