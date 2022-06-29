#include "GameArea.h"
#include <QTimerEvent>
#include <QKeyEvent>
#include <QTime>
#include <QMessageBox>


GameArea::GameArea(QWidget *parent) : QWidget(parent)
{
    tetris=NULL;
}

void GameArea::paintEvent(QPaintEvent *)
{
    DrawBG();
    DrawCur();
    update();
}

void GameArea::DrawBG()
{
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::red));
    painter.setPen(Qt::NoPen);
    painter.drawRect(0,68,350,2);

    QPixmap im[5];
    im[0].load(":/new/prefix1/pic/red.jpg");
    im[1].load(":/new/prefix1/pic/blue.jpg");
    im[2].load(":/new/prefix1/pic/yellow.jpg");
    im[3].load(":/new/prefix1/pic/green.jpg");

    for (int i=0;i<MAXX;++i)
        for (int j=0;j<MAXY;++j)
        {
            int val=tetris->getGrid(i,j).color;
            if (val>=0&&val<4)
                painter.drawPixmap(j*WIDTH,i*HEIGHT,WIDTH,HEIGHT,im[val]);
        }
}

void GameArea::DrawCur()
{
    const Block block=tetris->getBlock();
    if (!block.is_item)
    {
        QPainter painter(this);
        QPixmap im[5];
        im[0].load(":/new/prefix1/pic/red.jpg");
        im[1].load(":/new/prefix1/pic/blue.jpg");
        im[2].load(":/new/prefix1/pic/yellow.jpg");
        im[3].load(":/new/prefix1/pic/green.jpg");

        for (int i=0;i<COUNT;++i)
            painter.drawPixmap(WIDTH*block.cubes[i].y,block.cubes[i].x*HEIGHT,WIDTH,HEIGHT,im[block.cubes[i].color]);
    }
}


void GameArea::timerEvent(QTimerEvent* t)
{
    if (t->timerId() == MyTimerID)
    {
        tetris->moveDown();
        emit sigUpdateNextBlock(tetris->getNextBlock());
    }
}

void GameArea::NewGame()
{
    MyTimerID = startTimer(1000);
    if (tetris!=NULL)
        delete tetris;
    tetris = new Tetris;
    emit sigUpdateNextBlock(tetris->getNextBlock());
}

void GameArea::KeyPressed(int key)
{
    switch(key)
    {
    case Qt::Key_Space: tetris->moveToBottom();break;
    case Qt::Key_Left: tetris->moveToLeft(); break;
    case Qt::Key_Right: tetris->moveToRight(); break;
    case Qt::Key_Down: tetris->moveDown(); break;
    case Qt::Key_Up: tetris->rotate(); break;
    default: break;
    }
    return;
}
