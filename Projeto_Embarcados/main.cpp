#include "mainwindow.h"
#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QApplication>
//#include "server.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setStyleSheet("background-image:url(://Projeto_Embarcados/icons/interface_1.png)");
    w.show();

    return a.exec();

}
