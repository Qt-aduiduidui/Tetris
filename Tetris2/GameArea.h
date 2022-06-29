#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QWidget>
#include "Block.h"

class GameArea : public QWidget
{
    Q_OBJECT
public:
    explicit GameArea(QWidget *parent = 0);

    void DrawBG();                  //画背景
    void DrawCur();                 //画下落中的方块

    void NewGame();                 //新游戏
    void KeyPressed(int key);       //按键

signals:
    void sigUpdateNextBlock(Block NextBlock);

protected:
    void paintEvent(QPaintEvent* );
    void timerEvent(QTimerEvent* );

public slots:

private:
    int MyTimerID;
    Tetris* tetris;
};

#endif // GAMEAREA_H
