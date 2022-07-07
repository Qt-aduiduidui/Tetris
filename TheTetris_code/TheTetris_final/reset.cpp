#include "reset.h"
#include "record.h"
#include "ui_reset.h"

Reset::Reset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reset)
{
    ui->setupUi(this);
    setWindowTitle("Reset");
    ui->textBrowser->setAttribute(Qt::WA_TranslucentBackground);
}

Reset::~Reset()
{
    delete ui;
}

void Reset::on_pushButton_clicked()
{

    close();
    Record*w=new Record(this);
    w->re();

}

void Reset::on_pushButton_2_clicked()
{
    close();
}
