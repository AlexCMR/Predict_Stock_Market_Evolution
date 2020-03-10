#ifndef DIALOG_LOGIN_H
#define DIALOG_LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include <string.h>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>


namespace Ui {
class Dialog_login;
}

class Dialog_login : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_login(QWidget *parent = nullptr);
    ~Dialog_login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_login *ui;
};

#endif // DIALOG_LOGIN_H
