#ifndef DIALOG_ALG_3_H
#define DIALOG_ALG_3_H

#include <QDialog>

namespace Ui {
class dialog_alg_3;
}

class dialog_alg_3 : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_alg_3(QWidget *parent = nullptr);
    ~dialog_alg_3();

private:
    Ui::dialog_alg_3 *ui;
};

#endif // DIALOG_ALG_3_H
