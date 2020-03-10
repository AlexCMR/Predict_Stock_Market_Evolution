#ifndef DIALOG_ALG_2_H
#define DIALOG_ALG_2_H

#include <QDialog>

namespace Ui {
class dialog_alg_2;
}

class dialog_alg_2 : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_alg_2(QWidget *parent = nullptr);
    ~dialog_alg_2();

private:
    Ui::dialog_alg_2 *ui;
};

#endif // DIALOG_ALG_2_H
