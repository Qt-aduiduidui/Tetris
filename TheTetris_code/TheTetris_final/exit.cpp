#include "exit.h"
#include "ui_exit.h"

Exit::Exit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exit)
{
    ui->setupUi(this);
    setWindowTitle("Exit");
    ui->text->setAttribute(Qt::WA_TranslucentBackground);

}

Exit::~Exit()
{
    delete ui;
}

void Exit::on_no_clicked()
{
    close();
}
