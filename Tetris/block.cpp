#include "block.h"

Tetris::Tetris(){
    //初始化，但是记得还要create一次才有
    score=0;
    speed=1;
    memset(grid,0,sizeof(grid));
    //创建下一个方块（
    createNextBlock();
    createBlock();
}

void Tetris::createBlock(){
    //将下一个方块转移到这个方块
    for(int i=0;i<COUNT;i++){
        block.x[i]=nextBlock.x[i];
        block.y[i]=nextBlock.y[i];
    }
    block.id = nextBlock.id;
    createNextBlock();
}

Block Tetris::getNextBlock(){
    return nextBlock;
}
Block Tetris::getBlock(){
    return block;
}
int Tetris::getScore(){
    return score;
}
//返回该坐标处的值，以确定是否有方格
int Tetris::getGrid(int x, int y){
    return grid[x][y];
}
bool Tetris::moveToLeft(){
    if(move(0,-1))return true;
    return false;
}
bool Tetris::moveToRight(){
    if(move(0,1))return true;
    return false;
}

//将方块向下移动一格，成功返回true并继续新建block，游戏结束返回false
bool Tetris::moveDown(){
    if(!move(1,0)){
        changeBlock(); //变为底部的方块整体
        killLines();
        if(isEnd())return false;
        else{
            createBlock();
        }
    }
    return true;
}

bool Tetris::moveToBottom(){
    //往下直到不能再往下为止
    //但是这里应该是连续的动画，不能直接就下去了
    int k=0;
    while(true){
        k++;
        if(!move(k,0)){
            changeBlock();
            killLines();
            if(isEnd())return false;
            else createBlock();
        }
    }
    return true;
}

bool Tetris::isEnd(){
    //第一行被碰到的时候就停止
    for(int j=0;j<MAXY;j++){
        if(grid[0][j]==1)return true;
    }
    return false;
}

//方块消除//
void Tetris::killLines(){
    //获得从上到下的第一个整行并将其上的行向下平移一行
    //消行：从上往下平移一行
    int countLines=0;
    while(true){
        int line=getFirstFullLine();
        if(line==-1)break;
        countLines++;
        for(int i=line;i>0;i--){
            for(int j=0;j<MAXY;j++){
                grid[i][j]=grid[i-1][j];
            }
        }
    }
    score+=countLines*10;//还没有考虑多行的加倍
}

int Tetris::getHeight(){
    return MAXX * HEIGHT + (MAXX - 1) * INTERVAL;
}

int Tetris::getWidth(){
    return MAXY * WIDTH + (MAXY - 1) * INTERVAL;
}

void Tetris::createNextBlock(){
    int centerY=MAXY/2-1;
    srand(time(0)); //随机数的种子
    int index=rand()%7;//0 长条 1 左L 2 右L 3 方块 4 左z 5 中间凸起 6 z
    nextBlock.id=index;
    if(index==0){
        //长条
        for(int i=0;i<COUNT;i++){
            nextBlock.x[i]=0;
        }
        nextBlock.y[0]=centerY-2;
        nextBlock.y[1]=centerY-1;
        nextBlock.y[2]=centerY;
        nextBlock.y[3]=centerY+1;
    }
    else if(index==1){
        nextBlock.x[0]=0;
        for(int i=1;i<COUNT;i++){
            nextBlock.x[i]=1;
        }
        nextBlock.y[0]=centerY-1;nextBlock.y[1]=centerY-1;
        nextBlock.y[2]=centerY;nextBlock.y[3]=centerY+1;
    }
    else if(index==2){
        nextBlock.x[3]=0;
        for(int i=0;i<COUNT-1;i++){
            nextBlock.x[i]=1;
        }
        nextBlock.y[0]=centerY-1;nextBlock.y[1]=centerY;
        nextBlock.y[2]=centerY+1;nextBlock.y[3]=centerY+1;
    }
    else if(index==3){
        for(int i=0;i<2;i++)nextBlock.x[i]=0;
        for(int i=2;i<COUNT;i++)nextBlock.x[i]=1;
        nextBlock.y[0]=centerY-1;nextBlock.y[1]=centerY;
        nextBlock.y[2]=centerY-1;nextBlock.y[3]=centerY;
    }
    else if(index==4){
        for(int i=0;i<2;i++)nextBlock.x[i]=1;
        for(int i=2;i<COUNT;i++)nextBlock.x[i]=0;
        nextBlock.y[0]=centerY-1;nextBlock.y[1]=centerY;
        nextBlock.y[2]=centerY;nextBlock.y[3]=centerY+1;
    }
    else if(index==5){
        nextBlock.x[0]=0;
        for(int i=1;i<COUNT;i++){
            nextBlock.x[i]=1;
        }
        nextBlock.y[0]=centerY;nextBlock.y[1]=centerY-1;
        nextBlock.y[2]=centerY;nextBlock.y[3]=centerY+1;
    }
    else if(index==6){
        for(int i=0;i<2;i++)nextBlock.x[i]=0;
        for(int i=2;i<COUNT;i++)nextBlock.x[i]=1;
        nextBlock.y[0]=centerY-1;nextBlock.y[1]=centerY;
        nextBlock.y[2]=centerY;nextBlock.y[3]=centerY+1;
    }
}

bool inMap(int x,int y){
    if(x<0||x>=MAXX||y<0||y>MAXY)return false;
    return true;
}

bool Tetris::move(int dx,int dy){
    //如果可以移动，就移动block
    //不能出界，也不能碰到已有的格子
    int tx[COUNT];int ty[COUNT];
    for(int i=0;i<COUNT;i++){
        tx[i]=block.x[i]+dx;ty[i]=block.y[i]+dy;
        if(!inMap(tx[i],ty[i]))return false;
    }
    //不能碰到已有的格子
    for(int i=0;i<COUNT;i++){
        if(grid[tx[i]][ty[i]]==1)return false;
    }
    for(int i=0;i<COUNT;i++){
        block.x[i]=tx[i];block.y[i]=ty[i];
    }
    return true;
}

bool Tetris::rotate(){
    //默认左旋,以(block.x[2],bloxk.y[2])为旋转中心
    if(block.id==3)return true;//方形
    int dx[COUNT];int dy[COUNT];
    int cx=block.x[2];int cy=block.y[2];
    for(int i=0;i<COUNT;i++){
        dx[i]=-(block.y[i]-cy);
        dy[i]=block.x[i]-cx;
    }
    int newX[COUNT];int newY[COUNT];
    for(int i=0;i<COUNT;i++){
        newX[i]=cx+dx[i];newY[i]=cy+dy[i];
        if(!inMap(newX[i],newY[i]))return false;
        if(grid[newX[i]][newY[i]]==1)return false;
    }
    //旋转
    for(int i=0;i<COUNT;i++){
        block.x[i]=newX[i];block.y[i]=newY[i];
    }
    return true;
}

void Tetris::changeBlock(){
    //将block变为grid
    for(int i=0;i<COUNT;i++){
        int x=block.x[i];int y=block.y[i];
        grid[x][y]=1;
    }
    memset(block.x,0,sizeof(block.x));
    memset(block.y,0,sizeof(block.y));
}

int Tetris::getFirstFullLine(){
    //返回第一个完全填满的行，若没有返回-1
    for(int i=0;i<MAXX;i++){
        bool full=true;
        for(int j=0;j<MAXY;j++){
            if(grid[i][j]!=1){
                full=false;break;
            }
        }
        if(full)return i;
    }
    return -1;
}

void Tetris::harder(){
    speed++; //这个还得实现得更好，而且可以有一些交互的东西
}




