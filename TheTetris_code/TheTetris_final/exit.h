#ifndef EXIT_H
#define EXIT_H

#include <QDialog>

namespace Ui {
class Exit;
}

class Exit : public QDialog
{
    Q_OBJECT

public:
    explicit Exit(QWidget *parent = 0);
    ~Exit();

private slots:
    void on_no_clicked();

private:
    Ui::Exit *ui;
};

#endif // EXIT_H
