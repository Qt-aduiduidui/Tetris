#ifndef RESET_H
#define RESET_H

#include <QDialog>

namespace Ui {
class Reset;
}

class Reset : public QDialog
{
    Q_OBJECT

public:
    explicit Reset(QWidget *parent = 0);
    ~Reset();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Reset *ui;
};

#endif // RESET_H
