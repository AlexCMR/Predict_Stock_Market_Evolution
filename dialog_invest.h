#ifndef DIALOG_INVEST_H
#define DIALOG_INVEST_H

#include <QDialog>

namespace Ui {
class Dialog_invest;
}

class Dialog_invest : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_invest(QWidget *parent = nullptr);
    ~Dialog_invest();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog_invest *ui;
};

#endif // DIALOG_INVEST_H
