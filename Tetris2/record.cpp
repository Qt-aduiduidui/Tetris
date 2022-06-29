#include "record.h"
#include "reset.h"
#include "ui_record.h"

Record::Record(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Record)
{
    ui->setupUi(this);
    setWindowTitle("Record");
}

Record::~Record()
{
    delete ui;
}

void Record::on_pushButton_clicked()
{   Reset *w=new Reset(this);
    w->setModal(true);
    w->show();
}

void Record::re(){
    ui->r1->setText("100");
    ui->r2->setText("90");
    ui->r3->setText("80");
    ui->r4->setText("70");
}
