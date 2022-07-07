#ifndef HOLDAREA_H
#define HOLDAREA_H

#include <QWidget>
#include "Block.h"

class HoldArea : public QWidget
{
    Q_OBJECT
public:
    explicit HoldArea(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

public slots:
    void slotUpdateHoldBlock(Block* HoldBlock);

private:
    Block block;
};

#endif // HOLDAREA_H
