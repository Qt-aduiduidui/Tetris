#ifndef NEXTAREA_H
#define NEXTAREA_H

#include <QWidget>
#include "Block.h"

class NextArea : public QWidget
{
    Q_OBJECT
public:
    explicit NextArea(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

public slots:
    void slotUpdateNextBlock(Block NextBlock);

private:
    Block block;
};

#endif // NEXTAREA_H
