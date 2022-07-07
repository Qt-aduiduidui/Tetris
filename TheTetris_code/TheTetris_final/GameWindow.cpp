#include "GameWindow.h"
#include "ui_gamewindow.h"
#include "QPushButton"
#include "menu.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->widgetG->setStyleSheet("border-image: url(:/new/prefix1/pic/bg.jpg);");
    ui->widgetG->setStyleSheet("background-color:rgba(247,247,247,0.5);border-radius:15px;");
    ui->widgetN->setStyleSheet("background-color:rgba(247,247,247,0.5);border-radius:15px;");
    ui->widgetS->setStyleSheet("background-color:rgba(247,247,247,0.5);border-radius:15px;");
    ui->widgetH->setStyleSheet("background-color:rgba(247,247,247,0.5);border-radius:15px;");
    ui->widgetSp->setStyleSheet("background-color:rgba(247,247,247,0.5);border-radius:15px;");
    ui->widgetG_2->setStyleSheet("background-color:black");
    ui->widgetN_2->setStyleSheet("background-color:black;border-radius:15px;");
    ui->widgetS_2->setStyleSheet("background-color:black;border-radius:15px;");
    ui->widgetH_2->setStyleSheet("background-color:black;border-radius:15px;");
    ui->widgetSp_2->setStyleSheet("background-color:black;border-radius:15px;");

    connect(ui->widgetGameArea,&GameArea::sigUpdateNextBlock,ui->widgetNextArea,&NextArea::slotUpdateNextBlock);
    connect(ui->widgetGameArea,&GameArea::sigUpdateHoldBlock,ui->widgetHoldArea,&HoldArea::slotUpdateHoldBlock);
    connect(ui->widgetGameArea,&GameArea::sigUpdateScore,this,&GameWindow::slotUpdateScore);
    connect(ui->widgetGameArea,&GameArea::sigUpdateSpeed,this,&GameWindow::slotUpdateSpeed);

    ui->widgetGameArea->NewGame();
}

void GameWindow::keyPressEvent(QKeyEvent *e)
{
    ui->widgetGameArea->KeyPressed(e->key());
    QMainWindow::keyPressEvent(e);
    return;
}

void GameWindow::slotUpdateScore(int nScore)
{
    ui->labelScore->setText(QString::number(nScore));
    return;
}

void GameWindow::slotUpdateSpeed(int nSpeed)
{
    Speed=nSpeed;
    ui->labelSpeed->setText(QString::number(Speed));
    return;
}

void GameWindow::on_Pause_clicked(){
    if (ui->widgetGameArea->MyTimerID!=0x3f3f)
    {
        ui->widgetGameArea->killTimer(ui->widgetGameArea->MyTimerID);
        Menu *w=new Menu(this);
        w->setModal(true);
        w->show();
        int n =w->exec();
        if(n == QDialog::Accepted){
            close();
            GameWindow *w1=new GameWindow(this);
            w1->show();
        }
        else if (n==2)
            close();
        else if (n==QDialog::Rejected)
            ui->widgetGameArea->setTimer();
    }
    return;
}

GameWindow::~GameWindow()
{
    delete ui;
}
