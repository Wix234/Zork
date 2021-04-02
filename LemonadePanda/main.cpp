#include "mainwindow.h"
#include "main.h"

#include <QApplication>

list <room> rooms;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}






