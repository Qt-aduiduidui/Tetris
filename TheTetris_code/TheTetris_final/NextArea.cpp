#include "NextArea.h"

NextArea::NextArea(QWidget *parent) : QWidget(parent)
{

}

void NextArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    int xStart = 30;
    int yStart = 85;
    int w = 40;
    int h = 40;
    if (!block.is_item)
    {
        QPixmap im[6];
        im[0].load(":/new/prefix1/pic/red.jpg");
        im[1].load(":/new/prefix1/pic/blue.jpg");
        im[2].load(":/new/prefix1/pic/yellow.jpg");
        im[3].load(":/new/prefix1/pic/green.jpg");
        im[4].load(":/new/prefix1/pic/purple.jpg");
        im[5].load(":/new/prefix1/pic/stone.jpg");

        if (block.id>0)
        {
            xStart = 10;
            if (block.id!=3)
                yStart=65;
        }
        for (int i=0;i<COUNT;++i)
            painter.drawPixmap(yStart+w*block.cubes[i].y,xStart+block.cubes[i].x*h,w,h,im[block.cubes[i].color]);
    }
    else
    {
        yStart=65;
        if (block.id==0)
            painter.drawPixmap(yStart,xStart,w,h,QPixmap(":/new/prefix1/pic/stone.jpg"));
        else if (block.id==1)
            painter.drawPixmap(yStart,xStart,w,h,QPixmap(":/new/prefix1/pic/boom.png"));
        else if (block.id==2)
            painter.drawPixmap(yStart,xStart,w,h,QPixmap(":/new/prefix1/pic/crystal.png"));
    }

    update();
    return;
}

void NextArea::slotUpdateNextBlock(Block NextBlock)
{
    block=NextBlock;
    if (!block.is_item)
    {
        int centerY=MAXY/2-1;
        for (int i=0;i<COUNT;++i)
            block.cubes[i].y-=centerY;
    }
    return;
}
