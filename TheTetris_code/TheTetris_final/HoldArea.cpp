#include "HoldArea.h"

HoldArea::HoldArea(QWidget *parent) : QWidget(parent)
{
    block.is_item=true;
}

void HoldArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    int xStart = 30;
    int yStart = 5;
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

        switch(block.id)
        {
        case 1: xStart = 10; yStart = 25; break;
        case 2: xStart = 50; yStart = 25; break;
        case 3: xStart = 10; yStart = 45; break;
        case 4: xStart = 50; yStart = 25; break;
        case 5: xStart = 10; yStart = 65; break;
        case 6: xStart = 10; yStart = 25; break;
        default:break;
        }
        for (int i=0;i<COUNT;++i)
            painter.drawPixmap(yStart+w*(block.cubes[i].y-block.cubes[0].y),xStart+(block.cubes[i].x-block.cubes[0].x)*h,w,h,im[block.cubes[i].color]);
    }
    update();
    return;
}

void HoldArea::slotUpdateHoldBlock(Block* HoldBlock)
{
    block=*HoldBlock;
    return;
}
