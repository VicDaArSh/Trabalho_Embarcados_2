#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include "server.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mServer = new Server(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_Start_clicked()
{
    if(!mServer->listen(QHostAddress::Any,23))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started";
    }
}


void MainWindow::on_left_button_clicked()
{
    QByteArray Message = "Left";
    mServer->sendMessage(Message);

}

void MainWindow::on_right_button_clicked()
{
    QByteArray Message = "Right";
    mServer->sendMessage(Message);
    //QMessageBox::information(this,"my ass","my booty");
}


/*

{
    ui->setupUi(this);
    QPixmap img(":/Images/Images/Braco_pos_2.png");
    ui->label_1->setPixmap(img.scaled(400,400,Qt::KeepAspectRatio));

    mServer = new Server(this);
}


*/
