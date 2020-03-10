#include "dialog_contact.h"
#include "ui_dialog_contact.h"

Dialog_contact::Dialog_contact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_contact)
{
    ui->setupUi(this);
}

Dialog_contact::~Dialog_contact()
{
    delete ui;
}
