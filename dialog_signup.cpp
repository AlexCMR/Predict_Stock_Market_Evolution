#include "dialog_signup.h"
#include "ui_dialog_signup.h"
#include "variabile.h"

Dialog_signUp::Dialog_signUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_signUp)
{
    ui->setupUi(this);
}

Dialog_signUp::~Dialog_signUp()
{
    delete ui;
}

void Dialog_signUp::on_pushButton_clicked()
{
    QString user = ui->lineEdit_user->text();
    QString pass = ui->lineEdit_pass->text();
    QFile userF("User.txt") , passF("shadow2.txt") ;
    bool foundU = false, foundP = false ;
    QString readUser , readPass ;
    userF.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream userStream(&userF);
    while (!userStream.atEnd())
    {
        readUser = userStream.readLine();

        if ( user == readUser  )
        {
            foundU = true;
            break;
        }
    }
    userF.close();
    passF.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream passStream(&passF);
    while(!passStream.atEnd())
    {
        passStream >> readPass;
        if( pass ==  readPass && pass!="")
        {
            foundP = true ;
            break;
        }
    }
    passF.close();
    if(foundU && foundP)
    {
        QMessageBox::information(this,"Login","Welcome " + user + " .") ;
        loged = true;
        username = user ;
        this->close();
    }
    else
    {
        QMessageBox::warning(this,"Login","Username and password don't match.");
    }


}
