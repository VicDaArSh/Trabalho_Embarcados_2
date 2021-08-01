#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Server;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_Start_clicked();

    void on_left_button_clicked();

    void on_right_button_clicked();


private:
    Ui::MainWindow *ui;
    Server *mServer;
};
#endif // MAINWINDOW_H
