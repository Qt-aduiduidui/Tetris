#include "assistant.h"
#include "widget.h"
#include "ui_widget.h"
#include "record.h"
#include "exit.h"
#include "GameWindow.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("开始界面");
    //ui->textBrowser->styleSheet("background:transparent;border-width:0;border-style:outset")
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_help_clicked()
{
    assistant *a=new assistant(this);
    a->setModal(true);
    a->show();
}

void Widget::on_pushButton_clicked()
{
   Exit *w=new Exit(this);
   w->setModal(true);
   Exit w1;
   w1.show();
   if(w1.exec()==QDialog::Accepted){
       close();
   }

}

void Widget::on_record_clicked()
{
    Record *r=new Record(this);
    r->setModal(true);
    r->show();
}



void Widget::on_start_clicked()
{
    GameWindow *w=new GameWindow(this);
    w->show();
}
