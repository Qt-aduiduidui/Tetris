#include "assistant.h"
#include "widget.h"
#include "ui_widget.h"
#include "record.h"
#include "exit.h"
#include "GameWindow.h"
#include<QGraphicsDropShadowEffect>
#include<QMovie>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("开始界面");
    auto movie=new QMovie(":/new/prefix1/e1.gif");
    ui->Title->setMovie(movie);
    movie->start();

    QGraphicsDropShadowEffect * efc_start = new QGraphicsDropShadowEffect();
    efc_start->setBlurRadius(200);
    efc_start->setOffset(0);
    efc_start->setColor(QColor(255, 0, 0));
    ui->start->setGraphicsEffect(efc_start);
    ui->start->setStyleSheet("QPushButton:hover{color:rgb(205, 0, 0);}"
                            "QPushButton:checked{color:rgb(205, 0, 0);}");

    QGraphicsDropShadowEffect * efc_help = new QGraphicsDropShadowEffect();
    efc_help->setBlurRadius(200);
    efc_help->setOffset(0);
    efc_help->setColor(QColor(255,0,0));
    ui->help->setGraphicsEffect(efc_help);
    ui->help->setStyleSheet("QPushButton:hover{color:rgb(0, 0, 205);}"
                            "QPushButton:checked{color:rgb(0, 0, 205);}");

    QGraphicsDropShadowEffect * efc_record = new QGraphicsDropShadowEffect();
    efc_record->setBlurRadius(200);
    efc_record->setOffset(0);
    efc_record->setColor(QColor(255,0,255));
    ui->record->setGraphicsEffect(efc_record);
    ui->record->setStyleSheet("QPushButton:hover{color:rgb(191,62,255);}"
                            "QPushButton:checked{color:rgb(191,62,255);}");

    QGraphicsDropShadowEffect * efc_exit = new QGraphicsDropShadowEffect();
    efc_exit->setBlurRadius(200);
    efc_exit->setOffset(0);
    efc_exit->setColor(QColor(0,0,255));
    ui->pushButton->setGraphicsEffect(efc_exit);
    ui->pushButton->setStyleSheet("QPushButton:hover{color:rgb(205,0,0);}"
                            "QPushButton:checked{color:rgb(205,0,0);}");
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
    w->setWindowModality(Qt::WindowModal);
    w->show();
}
