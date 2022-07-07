#include "GameArea.h"
#include <QTimerEvent>
#include <QKeyEvent>
#include <QTime>
#include <QMessageBox>

GameArea::GameArea(QWidget *parent) : QWidget(parent)
{
    tetris=NULL;
    eliminateTimerID=0x3fff; dropTimerID=0x3f3f;
    mul=1;
    InProgress=false;
}

void GameArea::paintEvent(QPaintEvent *)
{
    DrawBG();
    DrawCur();
    update();
}

//画背景
void GameArea::DrawBG()
{
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::red));
    painter.setPen(Qt::NoPen);
    painter.drawRect(0,68,350,2);

    QPixmap im[6];
    im[0].load(":/new/prefix1/pic/red.jpg");
    im[1].load(":/new/prefix1/pic/blue.jpg");
    im[2].load(":/new/prefix1/pic/yellow.jpg");
    im[3].load(":/new/prefix1/pic/green.jpg");
    im[4].load(":/new/prefix1/pic/purple.jpg");
    im[5].load(":/new/prefix1/pic/stone.jpg");

    for (int i=0;i<MAXX;++i)
        for (int j=0;j<MAXY;++j)
        {
            int val=tetris->getGrid(i,j).color;
            if (val>=0&&val<=5)
                painter.drawPixmap(j*WIDTH,i*HEIGHT,WIDTH,HEIGHT,im[val]);
        }
}

//画落块
void GameArea::DrawCur()
{
    QPainter painter(this);
    const Block block=tetris->getBlock();
    if (!block.is_item)
    {
        QPixmap im[6];
        im[0].load(":/new/prefix1/pic/red.jpg");
        im[1].load(":/new/prefix1/pic/blue.jpg");
        im[2].load(":/new/prefix1/pic/yellow.jpg");
        im[3].load(":/new/prefix1/pic/green.jpg");
        im[4].load(":/new/prefix1/pic/purple.jpg");
        im[5].load(":/new/prefix1/pic/stone.jpg");

        for (int i=0;i<COUNT;++i)
            painter.drawPixmap(WIDTH*block.cubes[i].y,block.cubes[i].x*HEIGHT,WIDTH,HEIGHT,im[block.cubes[i].color]);
    }
    else
    {
        if (block.id==0)
            painter.drawPixmap(WIDTH*block.cubes[0].y,block.cubes[0].x*HEIGHT,WIDTH,HEIGHT,QPixmap(":/new/prefix1/pic/stone.jpg"));
        else if (block.id==1)
            painter.drawPixmap(WIDTH*block.cubes[0].y,block.cubes[0].x*HEIGHT,WIDTH,HEIGHT,QPixmap(":/new/prefix1/pic/boom.png"));
        else if (block.id==2)
            painter.drawPixmap(WIDTH*block.cubes[0].y,block.cubes[0].x*HEIGHT,WIDTH,HEIGHT,QPixmap(":/new/prefix1/pic/crystal.png"));
    }
}

//按一定速度下落
void GameArea::timerEvent(QTimerEvent* t)
{
    if (t->timerId() == MyTimerID)
    {
        if(!tetris->move(1,0)){
            mul=1;InProgress=false;
            killTimer(MyTimerID);
            MyTimerID = 0x3f3f;
            if(tetris->getBlock().is_item){
                //0 石头 1 炸弹 2 水晶
                if(tetris->getBlock().id==0){
                    tetris->changeBlock(); //变为底部的方块整体
                    if(!tetris->isEnd()){
                        tetris->createBlock();
                        InProgress=true;
                        MyTimerID = startTimer(SpeedToTime(tetris->getSpeed()));
                    }
                }
                else if(tetris->getBlock().id==1){
                    tetris->boom();
                    tetris->changeBlock();
                    tetris->drop();
                    repaint();
                    if(!tetris->isEnd()){
                        tetris->createBlock();
                        dropTimerID=startTimer(500);
                    }
                }
                else{//2
                    tetris->crystal();
                    tetris->changeBlock();
                    if(!tetris->isEnd()){
                        tetris->createBlock();
                        InProgress=true;
                        MyTimerID = startTimer(SpeedToTime(tetris->getSpeed()));
                    }
                }
            }
            else{
                tetris->changeBlock(); //变为底部的方块整体
                tetris->drop();
                if(!tetris->isEnd()){
                    tetris->createBlock();
                    dropTimerID=startTimer(200);
                }
            }
        }
        emit sigUpdateNextBlock(tetris->getNextBlock());
    }
    else if (t->timerId() == dropTimerID)
    {
        eliminateTimerID = startTimer(200);
        killTimer(dropTimerID);
        dropTimerID = 0x3f3f;
    }
    else if (t->timerId() == eliminateTimerID)
    {
        if(tetris->one_time_eliminate(mul))
        {
            mul++;
            tetris->drop();
            dropTimerID=startTimer(200);
        }
        else
        {
            InProgress = true;
            MyTimerID = startTimer(SpeedToTime(tetris->getSpeed()));
        }
        killTimer(eliminateTimerID);
        eliminateTimerID = 0x3fff;
        tetris->harder();
        emit sigUpdateScore(tetris->getScore());
        emit sigUpdateSpeed(tetris->getSpeed());
    }
    return;
}

//新游戏
void GameArea::NewGame()
{
    MyTimerID = startTimer(1000);
    if (tetris!=NULL)
        delete tetris;
    tetris = new Tetris;
    InProgress = true;
    emit sigUpdateNextBlock(tetris->getNextBlock());
}

//按键
void GameArea::KeyPressed(int key)
{
    if (InProgress)
    {
        switch(key)
        {
        case Qt::Key_Left: tetris->moveToLeft(); break;
        case Qt::Key_Right: tetris->moveToRight(); break;
        case Qt::Key_Down: tetris->moveDown(); break;
        case Qt::Key_Up: tetris->rotate(); break;
        case Qt::Key_Space: tetris->moveToBottom(); break;            
        case Qt::Key_C:{
            if (tetris->can_be_held){
                if (!tetris->getBlock().is_item)
                {
                    tetris->can_be_held = false;
                    if (tetris->holdBlock==NULL)
                    {
                        tetris->holdBlock=new Block;
                        while(true){
                            if(!tetris->move(-1,0)){
                                break;
                            }
                        }
                        while(true){
                            if(!tetris->move(0,-1)){
                                break;
                            }
                        }
                        *tetris->holdBlock=tetris->getBlock();
                        tetris->createBlock();
                    }
                    else
                    {
                        Block tmp=*tetris->holdBlock;
                        while(true){
                            if(!tetris->move(-1,0)){
                                break;
                            }
                        }
                        while(true){
                            if(!tetris->move(0,-1)){
                                break;
                            }
                        }
                        *tetris->holdBlock=tetris->getBlock();
                        tetris->getBlock()=tmp;
                        tetris->move(0,MAXY/2-1);
                    }
                    emit sigUpdateHoldBlock(tetris->holdBlock);
                }
            }
            break;
        }
        default: break;
        }
    }
    return;
}

//将速度转化为下落一格的用时
int GameArea::SpeedToTime(int speed)
{
    int t = 1100-100*speed;
    return t;
}

void GameArea::setTimer()
{
    MyTimerID=startTimer(SpeedToTime(tetris->getSpeed()));
    return;
}

GameArea::~GameArea()
{
    delete tetris;
}
