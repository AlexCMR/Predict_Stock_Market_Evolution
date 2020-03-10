#include "dialog_invest.h"
#include "ui_dialog_invest.h"
#include "QMessageBox"
#include "variabile.h"
#include <QTimer>
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>

#include <dialog_alg.h>
#include "dialog_alg_2.h"
#include "dialog_alg_3.h"


Dialog_invest::Dialog_invest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_invest)
{
    ui->setupUi(this);
    if(loged)
    {
        ui->label->setText("Welcome, " + username + "!");
    }
    else
    {
        QMessageBox::warning(this,"Error","You are not loged");
        QTimer::singleShot(0, this, SLOT(close()));
    }

}

Dialog_invest::~Dialog_invest()
{
    delete ui;
}

void Dialog_invest::on_pushButton_clicked()
{
    ui->label_2->setText("<a href=\"http://www.bvb.ro/FinancialInstruments/Details/FinancialInstrumentsDetails.aspx?s=TLV\">BANCA TRANSILVANIA</a>");
    ui->label_2->setOpenExternalLinks(true);
    dialog_alg_2 * fereastra = new dialog_alg_2(this);
    fereastra->setModal(true);
    fereastra->show();
}

void Dialog_invest::on_pushButton_2_clicked()
{
    ui->label_3->setText("<a href=\"http://www.bvb.ro/FinancialInstruments/Details/FinancialInstrumentsDetails.aspx?s=ALR\">ARLO</a>");
    ui->label_3->setOpenExternalLinks(true);
    Dialog_ALG *fereastra = new Dialog_ALG(this);
    fereastra->setModal(true);
    fereastra->show();
}

void Dialog_invest::on_pushButton_3_clicked()
{
    ui->label_4->setText("<a href=\"http://www.bvb.ro/FinancialInstruments/Details/FinancialInstrumentsDetails.aspx?s=BRD\">BRD</a>");
    ui->label_4->setOpenExternalLinks(true);
    dialog_alg_3 * fereastra = new dialog_alg_3(this);
    fereastra->setModal(true);
    fereastra->show();
}
