#include "mainwindow.h"

#include <QApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setStyleSheet("background-image:url(://Projeto_Embarcados/icons/interface_1.png)");
    w.show();

    return a.exec();

}

/* #include "mainwindow.h"
#include <QApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
*/
