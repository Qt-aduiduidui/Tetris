#ifndef BLOCK_H
#define BLOCK_H


#include<cstdlib>
#include<ctime>
#include<cstring>
#include<QTime>
#include<QWidget>
#include"qpainter.h"

#define MAXX 20 //显示窗口的纵向格数
#define MAXY 10
#define WIDTH 35 //单格的宽度
#define HEIGHT 35
#define INTERVAL 4 //单格之间的间隔(pixel)
#define COUNT 4 //每个方块的格数
#define P 6 //P个方块中有一个道具
#define ITEM_KIND 3 //道具的数量
#define COLOR 5 //颜色的数量

class Cube;
class Tetris;
class Block;

class Cube{
public:
    int x,y,color;//color -2 石头 -1 没有颜色 0～5方块颜色
    Cube(){}
};


class Block{
public:
    Cube cubes[COUNT];
    int id;//0 长条 1 左L 2 右L 3 方块 4 左z 5 中间凸起 6 z 道具 0 石头 1 炸弹 2 水晶
    bool is_item;
};

//道具有什么用呢
class Tetris: public QWidget{
public:
    Tetris();
    static int getWidth();
    static int getHeight();
    Block& getNextBlock();
    Block& getBlock();
    int getScore();
    int getSpeed();
    Cube& getGrid(int x,int y);

    void createBlock();             //创建新方块
    void createNextBlock();         //创建下一个新方块
    bool rotate();                  //可以旋转返回true，否则返回false
    bool moveToLeft();              //左移
    bool moveToRight();             //右移
    bool moveDown();                //下移
    bool moveToBottom();            //直接下降到底部
    bool isEnd();
    void drop();
    bool one_time_eliminate(int mul);
    void eliminate();
    void harder(); //增加难度并提升等级
    void crystal();
    void boom();
    void changeBlock();             //将block中的数据转移到grid中
    bool move(int dx,int dy);       //移动
    Block* holdBlock;
    bool can_be_held;

private:
    Block block;
    Block nextBlock;
    int speed;
    Cube grid[MAXX+1][MAXY+1];      //背景
    int score;
    void dfs(int x,int y,int color);
    bool inMap(int x,int y);
};


#endif // BLOCK_H
