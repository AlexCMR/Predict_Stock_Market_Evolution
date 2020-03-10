#include <iostream>
#include <fstream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <iomanip>

using namespace std;

typedef struct Profit
{
    double yearly_Profit[10];
}PROFIT;

class Company
{
    int company_ID;
    QString company_Name;
    QString company_profit_filename;
public:
    PROFIT company_Profit;
    QString currency;
    bool losingMoney;
public:
    Company(int id, QString name, QString filename)
    {
        //QString temp;

        currency="RON";
        losingMoney=false;

        company_ID=id;
        company_Name=name;
        company_profit_filename=filename;

        //QFile f("Alro S.A.txt");
        //f.open(QIODevice::ReadOnly | QIODevice::Text);
        //QTextStream passStream(&f);

        if(company_ID==1)
        {
        //temp = passStream.readLine();
        company_Profit.yearly_Profit[0]=67220024;                             //reprezinta profitul REAL pe anul 2016
        //temp=passStream.readLine();
        company_Profit.yearly_Profit[1]=317686272;                             //reprezinta profitul REAL pe anul 2017
        //temp=passStream.readLine();
        company_Profit.yearly_Profit[2]=225956817;                             //reprezinta profitul REAL pe anul 2018
        //f.close();
        }
        if(company_ID==2)
        {
            company_Profit.yearly_Profit[0]=1228440317;
            company_Profit.yearly_Profit[1]=1185979233;
            company_Profit.yearly_Profit[2]=1219390606;
        }
        if(company_ID==3)
        {
            company_Profit.yearly_Profit[0]=728281000;
            company_Profit.yearly_Profit[1]=1380384000;
            company_Profit.yearly_Profit[2]=1545989000;
        }
    }
    double growth(double current, double last)                                      //cresterea actiunii
    {
        double val;
        val=current/last-1;
        if(val<0)
        {
            losingMoney=true;
        }
        return val;
    }
    double forecast(double last, double current)                                   //previziuni
    {
        double val=current*(1+growth(current, last));
        return val;
    }
    void generate_values()
    {
        for(int i=3;i<10;i++)
        {
            company_Profit.yearly_Profit[i]=forecast(company_Profit.yearly_Profit[i-2],company_Profit.yearly_Profit[i-1]);
        }
    }
};
