#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Aici se deschide fereastra de sign up
void MainWindow::on_pushButton_clicked()
{
    Dialog_login *fereastra2;
    fereastra2 = new Dialog_login(this);
    fereastra2->setModal(true);
    fereastra2->show();
}
//Aici se deschide fereastra de login
void MainWindow::on_pushButton_2_clicked()
{
    Dialog_signUp *fereastra1;
    fereastra1 = new Dialog_signUp(this);
    fereastra1->setModal(true);
    fereastra1->show();
}
//Se inchide fereastra la apasarea butonului exit
void MainWindow::on_pushButton_5_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    Dialog_invest *fereastra;
    fereastra = new Dialog_invest(this);
    fereastra->setModal(true);
    fereastra->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    Dialog_contact *fereastra;
    fereastra = new Dialog_contact(this);
    fereastra->setModal(true);
    fereastra->show();
}
