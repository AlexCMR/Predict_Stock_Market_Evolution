#include "dialog_login.h"
#include "ui_dialog_login.h"


Dialog_login::Dialog_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_login)
{
    ui->setupUi(this);
}

Dialog_login::~Dialog_login()
{
    delete ui;
}

void Dialog_login::on_pushButton_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString pass = ui->lineEdit_pass->text();
    QString Cpass = ui->lineEdit_Cpass->text();
    QString Email = ui->lineEdit_Email->text();
    bool incPass = false, incUser1 = false, incUser2 = false , incEmail = false , check = false ;
    QString ver1 = QString(".com");
    QFile userF("User.txt") , passF("shadow.txt") , EmailF("contact.txt") , passF2("shadow2.txt");


    if ( pass != Cpass || pass.isEmpty())
    {
    incPass = true;
    }
    if ( username.length() < 4 )
    {
        incUser2 = true;
    }
    if ( username.length() > 16 )
    {
        incUser1 = true;
    }
    if (!Email.contains('@') || !Email.contains(ver1))
    {
        incEmail = true;
    }
    if(ui->checkBox->isChecked())
    {
        check = true;
    }
    if (incUser1)
    {
        QMessageBox::warning(this,"Register error" , "The Username is to long");
    }
    else if (incUser2)
    {
        QMessageBox::warning(this,"Register error" , "The Username is to short");
    }
    else if (incEmail)
    {
        QMessageBox::warning(this,"Register error " , "Invalid email adress ");
    }
    else if (incPass)
    {
        QMessageBox::warning(this,"Register error " , "Passwords desn't coincide");
    }
    else if (!check)
    {
        QMessageBox::warning(this,"Register error " , "Accept the terms and contitions.");
    }
    else
    {
    userF.open(QIODevice::Append | QIODevice::Text);
    QTextStream userStream(&userF);
    userStream << username << "\n" ;
    EmailF.open(QIODevice::Append | QIODevice::Text);
    QTextStream EmailStream(&EmailF);
    EmailStream << Email << "\n" ;
    passF.open(QIODevice::Append | QIODevice::Text);
    QTextStream passStream(&passF);
    QByteArray enc = pass.toUtf8();
    QString encodepass = QCryptographicHash::hash(enc,QCryptographicHash::Md5);
    passStream << encodepass << "\n" ;
    passF2.open(QIODevice::Append | QIODevice::Text);
    QTextStream passStream2(&passF2);
    passStream2 << pass << "\n" ;


    QMessageBox::information(this,"Register complete " , "Your account was created.");
    this->close();


    }

}
