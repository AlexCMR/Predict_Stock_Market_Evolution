#ifndef DIALOG_CONTACT_H
#define DIALOG_CONTACT_H

#include <QDialog>

namespace Ui {
class Dialog_contact;
}

class Dialog_contact : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_contact(QWidget *parent = nullptr);
    ~Dialog_contact();

private:
    Ui::Dialog_contact *ui;
};

#endif // DIALOG_CONTACT_H
