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
#define P 10 //P个方块中有一个道具
#define ITEM_KIND 3 //道具的数量
#define COLOR 3 //颜色的数量

class Cube;
class Tetris;
class Block;

class Cube{
private:
    int x,y,color;//color -2 道具 -1 没有颜色 0～5方块颜色
    Cube(){};
public:
    friend class Tetris;
    friend class Block;
};


class Block{
public:
    Cube cubes[COUNT];
    int id;//0 长条 1 左L 2 右L 3 方块 4 左z 5 中间凸起 6 z 道具 0 石头 1 炸弹 2 水晶
    bool is_item;
};

//道具有什么用呢
class Tetris{
public:
    Tetris();
    static int getWidth();
    static int getHeight();
    Block getNextBlock();
    Block getBlock();
    int getScore();
    Cube getGrid(int x,int y);

    void createBlock();
    void createNextBlock();
    bool rotate();//可以旋转返回true，否则返回false
    bool moveToLeft();
    bool moveToRight();
    bool moveDown();
    bool moveToBottom();//直接下降到底部
    bool isEnd();
    void drop();
    bool one_time_eliminate(int mul);
    void eliminate();
    void harder(); //增加难度并提升等级
    void createItem(); //制造道具

private:
    Block block;
    Block nextBlock;
    int speed;
    //背景
    Cube grid[MAXX+1][MAXY+1];
    int score;
    void changeBlock(); //将block中的数据转移到grid中
    bool move(int dx,int dy);
    int getFirstFullLine();//持续消除
    void dfs(int x,int y,int color);
};

#endif // BLOCK_H



