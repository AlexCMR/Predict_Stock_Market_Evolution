#ifndef DIALOG_ALG_H
#define DIALOG_ALG_H

#include <QDialog>

namespace Ui {
class Dialog_ALG;
}

class Dialog_ALG : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ALG(QWidget *parent = nullptr);
    ~Dialog_ALG();

private:
    Ui::Dialog_ALG *ui;
};

#endif // DIALOG_ALG_H
