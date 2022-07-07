#include "menu.h"
#include "ui_menu.h"
#include "GameWindow.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_exit_clicked()
{
    done(2);
}

void Menu::on_restart_clicked()
{
    close();
}
