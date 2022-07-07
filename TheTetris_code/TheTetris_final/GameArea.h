#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QWidget>
#include "Block.h"

class GameArea : public QWidget
{
    Q_OBJECT
public:
    explicit GameArea(QWidget *parent = 0);
    ~GameArea();

    void DrawBG();                  //画背景
    void DrawCur();                 //画下落中的方块

    void NewGame();                 //新游戏
    void KeyPressed(int key);       //按键
    void setTimer();

    int SpeedToTime(int speed);

    int MyTimerID, eliminateTimerID, dropTimerID;

signals:
    void sigUpdateNextBlock(Block NextBlock);
    void sigUpdateHoldBlock(Block* HoldBlock);
    void sigUpdateScore(int nScore);
    void sigUpdateSpeed(int nSpeed);

protected:
    void paintEvent(QPaintEvent* );
    void timerEvent(QTimerEvent* );

public slots:

private:
    int mul;
    Tetris* tetris;
    bool InProgress;        //能否被键盘操控
};

#endif // GAMEAREA_H
