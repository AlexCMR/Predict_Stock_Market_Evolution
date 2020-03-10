#include <iostream>
#include <fstream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef struct Profit
{
    double monthly_Profit[12];
    double yearly_Profit;
    //0 = January ... 11 = December
}PROFIT;

class Company
{
    int company_ID;
    QString company_Name;
public:
    PROFIT company_Profit[3];                                       //0 - previous after previous (ante-previous), 1 - previous, 2 - current
    QString currency;                                               //to correctly display currency in interface
    bool losingMoney;                                               //if company is losing money this value will be true

    //double MAD_1_3, MAD_4_6, MAD_7_9, MAD_10_12;                                     //MAD = Mean Absolute Deviation (Dispersia Standard / Eroarea Absoluta)
public:
    Company(int id, QString name)
    {
        QString temp;
        QString filename = name + "_ante_previous.txt";

        currency="RON";
        losingMoney=false;

        company_ID=id;
        company_Name=name;

        QFile f(filename);
        f.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream passStream(&f);

        for(int i=0;i<12;i++)
        {
            temp = passStream.readLine();
            company_Profit[0].monthly_Profit[i] = temp.toDouble();
        }
        f.close();

        filename = name + "_previous.txt";
        QFile f1(filename);
        f1.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream passStream1(&f1);

        for(int i=0;i<12;i++)
        {
            temp = passStream1.readLine();
            company_Profit[1].monthly_Profit[i] = temp.toDouble();
        }
        f1.close();
    }

    double factor(int month)                                                                             //forecasting factor
    {
        double sum_previous, sum_anteprevious;

        if(month<=3)
        {
            sum_anteprevious = company_Profit[0].monthly_Profit[9] + company_Profit[0].monthly_Profit[10] + company_Profit[0].monthly_Profit[11];
            sum_previous = company_Profit[1].monthly_Profit[9] + company_Profit[1].monthly_Profit[10] + company_Profit[1].monthly_Profit[11];
        }
        else
        {
            month--;
            sum_previous = company_Profit[2].monthly_Profit[month-5] + company_Profit[2].monthly_Profit[month-4] + company_Profit[2].monthly_Profit[month-3];
            sum_anteprevious = company_Profit[1].monthly_Profit[month-5] + company_Profit[1].monthly_Profit[month-4] + company_Profit[1].monthly_Profit[month-3];
        }
        return (sum_previous/sum_anteprevious);
    }
    void forecast()                                                                                   //forecast values
    {
        for(int i=0;i<12;i++)
        {
            if(i<3)
            {
                company_Profit[2].monthly_Profit[i] = company_Profit[1].monthly_Profit[i] * this->factor(3);
            }
            else if(i>=3 && i<6)
            {
                company_Profit[2].monthly_Profit[i] = company_Profit[1].monthly_Profit[i] * this->factor(6);
            }
            else if(i>=6 && i<9)
            {
                company_Profit[2].monthly_Profit[i] = company_Profit[1].monthly_Profit[i] * this->factor(9);
            }
            else
            {
                company_Profit[2].monthly_Profit[i] = company_Profit[1].monthly_Profit[i] * this->factor(12);
            }
        }
    }

    void yearprofit()                                                                                   //total yearly profit calculation
    {
        company_Profit[0].yearly_Profit=0;
        company_Profit[1].yearly_Profit=0;
        company_Profit[2].yearly_Profit=0;
        for(int i=0;i<12;i++)
        {
            company_Profit[0].yearly_Profit+=company_Profit[0].monthly_Profit[i];
            company_Profit[1].yearly_Profit+=company_Profit[1].monthly_Profit[i];
            company_Profit[2].yearly_Profit+=company_Profit[2].monthly_Profit[i];
        }
        if(company_Profit[0].monthly_Profit[11] > company_Profit[1].monthly_Profit[11])
        {
            losingMoney=true;
        }
    }

    /*void calc_dispersion()                                                                          //calculate MAD
    {
        for(int i=0;i<3;i++)
        {
            MAD_1_3 = abs(company_Profit[2].monthly_Profit[i] - company_Profit[1].monthly_Profit[i]);
            MAD_4_6 = abs(company_Profit[2].monthly_Profit[i+3] - company_Profit[1].monthly_Profit[i+3]);
            MAD_7_9 = abs(company_Profit[2].monthly_Profit[i+6] - company_Profit[1].monthly_Profit[i+6]);
            MAD_10_12 = abs(company_Profit[2].monthly_Profit[i+9] - company_Profit[1].monthly_Profit[i+9]);
        }
        MAD_1_3 = MAD_1_3 / 3;
        MAD_4_6 = MAD_4_6 / 3;
        MAD_7_9/=3;
        MAD_10_12/=3;
    }*/
};
