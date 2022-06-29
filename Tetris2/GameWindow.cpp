#include "GameWindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->widgetBGD->setStyleSheet("border-image:url(:/new/prefix1/pic/bg.jpg)");
    ui->widgetG->setStyleSheet("background-color:rgba(247,247,247,0.5);border-radius:15px;");
    ui->widgetN->setStyleSheet("background-color:rgba(247,247,247,0.5);border-radius:15px;");
    ui->widgetG_2->setStyleSheet("background-color:black");
    ui->widgetN_2->setStyleSheet("background-color:black;border-radius:15px;");

    connect(ui->widgetGameArea,&GameArea::sigUpdateNextBlock,ui->widgetNextArea,&NextArea::slotUpdateNextBlock);

    ui->widgetGameArea->NewGame();
}

void GameWindow::keyPressEvent(QKeyEvent *e)
{
    ui->widgetGameArea->KeyPressed(e->key());
    QMainWindow::keyPressEvent(e);
}

GameWindow::~GameWindow()
{
    delete ui;
}
