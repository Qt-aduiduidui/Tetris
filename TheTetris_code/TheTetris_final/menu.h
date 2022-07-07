#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_exit_clicked();

    void on_restart_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
