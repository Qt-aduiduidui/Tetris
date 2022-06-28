#include "block.h"


Tetris::Tetris(){
    //初始化，但是记得还要create一次才有
    score=0;
    speed=1;
    for(int i=0;i<MAXX;i++){
        for(int j=0;j<MAXY;j++){
            grid[i][j].color=-1;
        }
    }
    //创建下一个方块
    createNextBlock();
    createBlock();
}

void Tetris::createBlock(){
    //将下一个方块转移到这个方块
    for(int i=0;i<COUNT;i++){
        block.cubes[i].x=nextBlock.cubes[i].x;
        block.cubes[i].y=nextBlock.cubes[i].y;
        block.cubes[i].color=nextBlock.cubes[i].color;
    }
    block.is_item=nextBlock.is_item;
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
Cube Tetris::getGrid(int x, int y){
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
//新增color，规则改变
//将方块向下移动一格，成功返回true，游戏结束返回false
bool Tetris::moveDown(){
    if(!move(1,0)){
        changeBlock(); //变为底部的方块整体
        eliminate();
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
    while(true){
        if(!move(1,0)){
            changeBlock();
            eliminate();
            break;
        }
    }
    if(isEnd())return false;
    return true;
}

bool Tetris::isEnd(){
    //第一行被碰到的时候就停止
    for(int j=0;j<MAXY;j++){
        if(grid[0][j].color!=-1)return true;
    }
    return false;
}

int visited[MAXX][MAXY];
int count=0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void Tetris::dfs(int x,int y,int color){
    for(int i=0;i<4;i++){
        int tx=x+dx[i];int ty=y+dy[i];
        if(tx<0||ty<0||tx>=MAXX||ty>=MAXY)continue;
        if(visited[tx][ty]==0 && grid[x][y].color==color){
            count++;
            visited[tx][ty]=1;
            grid[x][y].color=-1;
            dfs(tx,ty,color);
        }
    }
}
//单次的全局方块消除//
//相同颜色消除，直接搜索
//这里应该可以做动画
bool Tetris::one_time_eliminate(int mul){
    memset(visited,0,sizeof(visited));
    int total_score=0;
    for(int i=0;i<MAXX;i++){
        for(int j=0;j<MAXY;j++){
            count=1;
            if(grid[i][j].color>=0&&visited[i][j]==0){
                visited[i][j]=1;
                dfs(i,j,grid[i][j].color);
                if(count>=2){
                    grid[i][j].color=-1;
                    total_score+=count;
                }
            }
        }
    }
    score+=total_score*mul;//已考虑连续消
    if(total_score==0)return false;
    return true;
}

void Tetris::drop(){
    for(int j=0;j<MAXY;j++){
        for(int i=MAXX-1;i>=0;i--){
            if(grid[i][j].color==-1){
                //有空的块，检查上面有没有不是空的块
                for(int k=i-1;k>=0;k--){
                    if(grid[k][j].color!=-1){
                        int len=0;
                        for(int l=k;l>=0;l--){
                            if(grid[l][j].color==-1)break;
                            len++;
                        }
                        //转移小块
                        for(int l=i;l>i-len;l--){
                            grid[l][j].color=grid[l-(i-k)][j].color;
                        }
                        //上面变为空
                        for(int l=k-len;l>=0;l--){
                            grid[l][j].color=-1;
                        }
                    }
                }
            }
        }
    }
}

void Tetris::eliminate(){
    //所有的消除，即消除+下落
    int mul=1;
    while(true){
        //消除
        if(!one_time_eliminate(mul))break;
        //下落,一行一行来
        mul++;
        drop();
    }
}
int Tetris::getHeight(){
    return MAXX * HEIGHT + (MAXX - 1) * INTERVAL;
}

int Tetris::getWidth(){
    return MAXY * WIDTH + (MAXY - 1) * INTERVAL;
}

//颜色,is_item
void Tetris::createNextBlock(){
    int centerY=MAXY/2-1;
    srand(time(0)); //随机数的种子
    int item=rand()%P;
    if(item==0){
        //生成道具
        nextBlock.cubes[0].x=0;nextBlock.cubes[1].y=centerY;
        for(int i=1;i<COUNT;i++){
            nextBlock.cubes[i].x=-1;nextBlock.cubes[i].y=-1;
        }
        for(int i=0;i<COUNT;i++){
            nextBlock.cubes[i].color=-2;
        }
        nextBlock.is_item=true;
        srand(time(0));
        int index=rand()%ITEM_KIND;
        nextBlock.id=index;
    }
    else{
        nextBlock.is_item=false;
        //形状
        srand(time(0));
        int index=rand()%7;//0 长条 1 左L 2 右L 3 方块 4 左z 5 中间凸起 6 z
        nextBlock.id=index;
        //颜色
        int last_color=0;
        for(int i=0;i<COUNT;i++){
            while(true){
                srand(time(0));
                int c=rand()%COLOR;
                if(c!=last_color){
                    last_color=c;
                    nextBlock.cubes[i].color=c;
                    break;
                }
            }
        }
        if(index==0){
            //长条
            for(int i=0;i<COUNT;i++){
                nextBlock.cubes[i].x=0;
            }
            nextBlock.cubes[0].y=centerY-2;
            nextBlock.cubes[1].y=centerY-1;
            nextBlock.cubes[2].y=centerY;
            nextBlock.cubes[3].y=centerY+1;
        }
        else if(index==1){
            nextBlock.cubes[0].x=0;
            for(int i=1;i<COUNT;i++){
                nextBlock.cubes[i].x=1;
            }
            nextBlock.cubes[0].y=centerY-1;nextBlock.cubes[1].y=centerY-1;
            nextBlock.cubes[2].y=centerY;nextBlock.cubes[3].y=centerY+1;
        }
        else if(index==2){
            nextBlock.cubes[3].x=0;
            for(int i=0;i<COUNT-1;i++){
                nextBlock.cubes[i].x=1;
            }
            nextBlock.cubes[0].y=centerY-1;nextBlock.cubes[1].y=centerY;
            nextBlock.cubes[2].y=centerY+1;nextBlock.cubes[3].y=centerY+1;
        }
        else if(index==3){
            for(int i=0;i<2;i++)nextBlock.cubes[i].x=0;
            for(int i=2;i<COUNT;i++)nextBlock.cubes[i].x=1;
            nextBlock.cubes[0].y=centerY-1;nextBlock.cubes[1].y=centerY;
            nextBlock.cubes[2].y=centerY-1;nextBlock.cubes[3].y=centerY;
        }
        else if(index==4){
            for(int i=0;i<2;i++)nextBlock.cubes[i].x=1;
            for(int i=2;i<COUNT;i++)nextBlock.cubes[i].x=0;
            nextBlock.cubes[0].y=centerY-1;nextBlock.cubes[1].y=centerY;
            nextBlock.cubes[2].y=centerY;nextBlock.cubes[3].y=centerY+1;
        }
        else if(index==5){
            nextBlock.cubes[0].x=0;
            for(int i=1;i<COUNT;i++){
                nextBlock.cubes[i].x=1;
            }
            nextBlock.cubes[0].y=centerY;nextBlock.cubes[1].y=centerY-1;
            nextBlock.cubes[2].y=centerY;nextBlock.cubes[3].y=centerY+1;
        }
        else if(index==6){
            for(int i=0;i<2;i++)nextBlock.cubes[i].x=0;
            for(int i=2;i<COUNT;i++)nextBlock.cubes[i].x=1;
            nextBlock.cubes[0].y=centerY-1;nextBlock.cubes[1].y=centerY;
            nextBlock.cubes[2].y=centerY;nextBlock.cubes[3].y=centerY+1;
        }
    }

}

bool inMap(int x,int y){
    if(x<0||x>=MAXX||y<0||y>=MAXY)return false;
    return true;
}

bool Tetris::move(int dx,int dy){
    //如果可以移动，就移动block
    //不能出界，也不能碰到已有的格子
    int tx[COUNT];int ty[COUNT];
    for(int i=0;i<COUNT;i++){
        tx[i]=block.cubes[i].x+dx;ty[i]=block.cubes[i].y+dy;
        if(!inMap(tx[i],ty[i]))return false;
    }
    //不能碰到已有的格子
    for(int i=0;i<COUNT;i++){
        if(grid[tx[i]][ty[i]].color!=-1)return false;
    }
    for(int i=0;i<COUNT;i++){
        block.cubes[i].x=tx[i];block.cubes[i].y=ty[i];
    }
    return true;
}

bool Tetris::rotate(){
    //默认左旋,以(block.x[2],bloxk.y[2])为旋转中心
    if(block.id==3)return true;//方形
    int dx[COUNT];int dy[COUNT];
    int cx=block.cubes[2].x;int cy=block.cubes[2].y;
    for(int i=0;i<COUNT;i++){
        dx[i]=-(block.cubes[i].y-cy);
        dy[i]=block.cubes[i].x-cx;
    }
    int newX[COUNT];int newY[COUNT];
    for(int i=0;i<COUNT;i++){
        newX[i]=cx+dx[i];newY[i]=cy+dy[i];
        if(!inMap(newX[i],newY[i]))return false;
        if(grid[newX[i]][newY[i]].color!=-1)return false;
    }
    //旋转
    for(int i=0;i<COUNT;i++){
        block.cubes[i].x=newX[i];block.cubes[i].y=newY[i];
    }
    return true;
}

void Tetris::changeBlock(){
    //将block变为grid
    for(int i=0;i<COUNT;i++){
        int x=block.cubes[i].x;int y=block.cubes[i].y;
        grid[x][y].color=block.cubes[i].color;
    }
    for(int i=0;i<COUNT;i++){
        block.cubes[i].x=0;
        block.cubes[i].y=0;
        block.cubes[i].color=0;
    }
}


void Tetris::harder(){
    speed++; //这个还得实现得更好，而且可以有一些交互的东西
}




