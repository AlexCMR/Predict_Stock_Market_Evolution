#include "dialog_alg_3.h"
#include "ui_dialog_alg_3.h"
#include "prediction.cpp"

dialog_alg_3::dialog_alg_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_alg_3)
{
    ui->setupUi(this);

    Company BRD(3,"BRD SA");

        BRD.forecast();
        BRD.yearprofit();

        if(BRD.losingMoney==true)
        {
        ui->label->setText("Warning! This company is losing action value annually and risks to go bankrupt! You may lose money on your investment.");
        }
        else
        {
            ui->label->setText("Monthly Profit - Rated on 3 years");
        }
        QString luni[12];
        luni[0]=QString("January: %1 %2\n").arg(BRD.company_Profit[0].monthly_Profit[0]).arg(BRD.currency);
        luni[1]=QString("February: %1 %2\n").arg(BRD.company_Profit[0].monthly_Profit[1]).arg(BRD.currency);
        luni[2]=QString("March: %1 %2\n").arg(BRD.company_Profit[0].monthly_Profit[2]).arg(BRD.currency);
        luni[3]=QString("April: %1 %2\n").arg(BRD.company_Profit[0].monthly_Profit[3]).arg(BRD.currency);
        luni[4]=QString("May: %1 %2\n").arg(BRD.company_Profit[0].monthly_Profit[4]).arg(BRD.currency);
        luni[5]=QString("June: %1 %2\n").arg(BRD.company_Profit[0].monthly_Profit[5]).arg(BRD.currency);
        luni[6]=QString("July: %1 %2\n").arg(BRD.company_Profit[0].monthly_Profit[6]).arg(BRD.currency);
        luni[7]=QString("August: %1 %2\n").arg(BRD.company_Profit[0].monthly_Profit[7]).arg(BRD.currency);
        luni[8]=QString("September: %1 %2\n").arg(BRD.company_Profit[0].monthly_Profit[8]).arg(BRD.currency);
        luni[9]=QString("October: %1 %2\n").arg(BRD.company_Profit[0].monthly_Profit[9]).arg(BRD.currency);
        luni[10]=QString("November: %1 %2\n").arg(BRD.company_Profit[0].monthly_Profit[10]).arg(BRD.currency);
        luni[11]=QString("December: %1 %2\n").arg(BRD.company_Profit[0].monthly_Profit[11]).arg(BRD.currency);

        QString text = QString("--2018--\n");
        for(int i=0;i<12;i++)
        {
            text+=luni[i];
        }
        //text+=QString("Total Year Profit: %1 %2\n").arg(BRD.company_Profit[0].yearly_Profit).arg(BRD.currency);
        ui->textBrowser->setText(text);

        luni[0]=QString("January: %1 %2\n").arg(BRD.company_Profit[1].monthly_Profit[0]).arg(BRD.currency);
        luni[1]=QString("February: %1 %2\n").arg(BRD.company_Profit[1].monthly_Profit[1]).arg(BRD.currency);
        luni[2]=QString("March: %1 %2\n").arg(BRD.company_Profit[1].monthly_Profit[2]).arg(BRD.currency);
        luni[3]=QString("April: %1 %2\n").arg(BRD.company_Profit[1].monthly_Profit[3]).arg(BRD.currency);
        luni[4]=QString("May: %1 %2\n").arg(BRD.company_Profit[1].monthly_Profit[4]).arg(BRD.currency);
        luni[5]=QString("June: %1 %2\n").arg(BRD.company_Profit[1].monthly_Profit[5]).arg(BRD.currency);
        luni[6]=QString("July: %1 %2\n").arg(BRD.company_Profit[1].monthly_Profit[6]).arg(BRD.currency);
        luni[7]=QString("August: %1 %2\n").arg(BRD.company_Profit[1].monthly_Profit[7]).arg(BRD.currency);
        luni[8]=QString("September: %1 %2\n").arg(BRD.company_Profit[1].monthly_Profit[8]).arg(BRD.currency);
        luni[9]=QString("October: %1 %2\n").arg(BRD.company_Profit[1].monthly_Profit[9]).arg(BRD.currency);
        luni[10]=QString("November: %1 %2\n").arg(BRD.company_Profit[1].monthly_Profit[10]).arg(BRD.currency);
        luni[11]=QString("December: %1 %2\n").arg(BRD.company_Profit[1].monthly_Profit[11]).arg(BRD.currency);

        text = QString("--2019--\n");
        for(int i=0;i<12;i++)
        {
            text+=luni[i];
        }
        //text+=QString("Total Year Profit: %1 %2\n").arg(BRD.company_Profit[1].yearly_Profit).arg(BRD.currency);
        ui->textBrowser_2->setText(text);

        luni[0]=QString("January: %1 %2\n").arg(BRD.company_Profit[2].monthly_Profit[0]).arg(BRD.currency);
        luni[1]=QString("February: %1 %2\n").arg(BRD.company_Profit[2].monthly_Profit[1]).arg(BRD.currency);
        luni[2]=QString("March: %1 %2\n").arg(BRD.company_Profit[2].monthly_Profit[2]).arg(BRD.currency);
        luni[3]=QString("April: %1 %2\n").arg(BRD.company_Profit[2].monthly_Profit[3]).arg(BRD.currency);
        luni[4]=QString("May: %1 %2\n").arg(BRD.company_Profit[2].monthly_Profit[4]).arg(BRD.currency);
        luni[5]=QString("June: %1 %2\n").arg(BRD.company_Profit[2].monthly_Profit[5]).arg(BRD.currency);
        luni[6]=QString("July: %1 %2\n").arg(BRD.company_Profit[2].monthly_Profit[6]).arg(BRD.currency);
        luni[7]=QString("August: %1 %2\n").arg(BRD.company_Profit[2].monthly_Profit[7]).arg(BRD.currency);
        luni[8]=QString("September: %1 %2\n").arg(BRD.company_Profit[2].monthly_Profit[8]).arg(BRD.currency);
        luni[9]=QString("October: %1 %2\n").arg(BRD.company_Profit[2].monthly_Profit[9]).arg(BRD.currency);
        luni[10]=QString("November: %1 %2\n").arg(BRD.company_Profit[2].monthly_Profit[10]).arg(BRD.currency);
        luni[11]=QString("December: %1 %2\n").arg(BRD.company_Profit[2].monthly_Profit[11]).arg(BRD.currency);

        text = QString("--Estimated 2020--\n");
        for(int i=0;i<12;i++)
        {
            text+=luni[i];
        }
        //text+=QString("Total Year Profit: %1 %2\n").arg(BRD.company_Profit[2].yearly_Profit).arg(BRD.currency);
        ui->textBrowser_3->setText(text);
}

dialog_alg_3::~dialog_alg_3()
{
    delete ui;
}
