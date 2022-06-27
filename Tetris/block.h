#ifndef BLOCK_H
#define BLOCK_H

#include<cstdlib>
#include<ctime>
#include<cstring>

#define MAXX 20 //显示窗口的纵向格数
#define MAXY 10
#define WIDTH 30 //单格的宽度
#define HEIGHT 30
#define INTERVAL 4 //单格之间的间隔(pixel)
#define COUNT 4 //每个方块的格数

//A Block
struct Block{
    int x[COUNT]; //方块单格的x坐标
    int y[COUNT];
    int id; //0 长条 1 左L 2 右L 3 方块 4 左z 5 中间凸起 6 z
};

class Tetris{
public:
    Tetris();
    static int getWidth();
    static int getHeight();
    Block getNextBlock();
    Block getBlock();
    int getScore();
    int getGrid(int x,int y);

    void createBlock();
    void createNextBlock();
    bool rotate();//可以旋转返回true，否则返回false
    bool moveToLeft();
    bool moveToRight();
    bool moveDown();
    bool moveToBottom();//直接下降到底部
    bool isEnd();
    void killLines();
    void harder(); //增加难度并提升等级
    void createItem(); //制造道具

private:
    Block block;
    Block nextBlock;
    int speed;
    //背景
    int grid[MAXX][MAXY];
    int score;
    void changeBlock(); //将block中的数据转移到grid中
    bool move(int dx,int dy);
    int getFirstFullLine();
};

#endif // BLOCK_H



