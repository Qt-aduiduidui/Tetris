#include "Block.h"
#include "GameArea.h"

Tetris::Tetris(){
    //初始化，但是记得还要create一次才有
    holdBlock=NULL;
    can_be_held=true;
    score=0;
    speed=1;
    srand(time(0));
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
    return;
}

Block& Tetris::getNextBlock(){
    return nextBlock;
}
Block& Tetris::getBlock(){
    return block;
}
int Tetris::getScore(){
    return score;
}

int Tetris::getSpeed(){
    return speed;
}

//返回该坐标处的值，以确定是否有方格
Cube& Tetris::getGrid(int x, int y){
    return grid[x][y];
}
bool Tetris::moveToLeft(){
    if(move(0,-1))
        return true;
    return false;
}
bool Tetris::moveToRight(){
    if(move(0,1))
        return true;
    return false;
}
//新增color，规则改变
//将方块向下移动一格，成功返回true,移动之后到达底部返回false
bool Tetris::moveDown(){
    if(!move(1,0)){
        /*
        if(block.is_item){
            //0 石头 1 炸弹 2 水晶
            if(block.id==0){
                changeBlock(); //变为底部的方块整体
                eliminate();
                if(isEnd())
                    return false;
                else{
                    createBlock();
                    return true;
                }
            }
            else if(block.id==1){
                boom();
                return true;
            }
            else{//2
                crystal();
                return true;
            }
        }
        else{
            changeBlock(); //变为底部的方块整体
            drop();
            eliminate();
            if(isEnd())
                return false;
            else{
                createBlock();
                return true;
            }
        }
        */
    }
    else
        return true;
    return true;
}

bool Tetris::moveToBottom(){
    //往下直到不能再往下为止
    //但是这里应该是连续的动画，不能直接就下去了
    while(true){
        if(!move(1,0)){
            break;
        }
    }
    return true;
}

bool Tetris::isEnd(){
    //第二行被碰到的时候就停止
    for(int j=0;j<MAXY;j++){
        if(grid[1][j].color!=-1)
            return true;
    }
    return false;
}

int visited[MAXX][MAXY];
int count_cubes=0;
void Tetris::dfs(int x,int y,int color){
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    for(int i=0;i<4;i++){
        int tx=x+dx[i];int ty=y+dy[i];
        if(tx<0||ty<0||tx>=MAXX||ty>=MAXY)
            continue;
        if(visited[tx][ty]==0 && grid[tx][ty].color==color){
            count_cubes++;
            visited[tx][ty]=1;
            grid[tx][ty].color=-1;
            dfs(tx,ty,color);
        }
    }
    return;
}
//单次的全局方块消除//
//相同颜色消除，直接搜索
//这里应该可以做动画
bool Tetris::one_time_eliminate(int mul){
    memset(visited,0,sizeof(visited));
    int total_score=0;
    for(int i=0;i<MAXX;i++){
        for(int j=0;j<MAXY;j++){
            count_cubes=1;
            if(grid[i][j].color<COLOR&&grid[i][j].color>=0&&visited[i][j]==0){
                visited[i][j]=1;
                dfs(i,j,grid[i][j].color);
                if(count_cubes>=2){
                    grid[i][j].color=-1;
                    total_score+=count_cubes;
                }
            }
        }
    }
    score+=total_score*mul;//已考虑连续消
    if(total_score==0)
        return false;
    return true;
}

void Tetris::drop(){
    for(int j=0;j<MAXY;j++){
        for(int i=MAXX-2;i>=0;i--){
            /*
            if(grid[i][j].color==-1){
                //有空的块，检查上面有没有不是空的块
                for(int k=i-1;k>=0;k--){
                    if(grid[k][j].color!=-1){
                        for(int l=k;l>=0;l--){
                            if(grid[l][j].color==-1)break;
                        }
                        int len=i-k;
                        //整体向下移len
                        for(int l=k;l>=0;l--){
                            grid[l+len][j].color=grid[l][j].color;
                        }
                        //上面变为空
                        for(int l=0;l<len;l++){
                            grid[l][j].color=-1;
                        }
                    }
                }
            }
            */
            if (grid[i][j].color!=-1){
                for (int k = i + 1; k < MAXX; ++k){
                    if (grid[k][j].color==-1){
                        grid[k][j].color=grid[k-1][j].color;
                        grid[k-1][j].color=-1;
                    }
                    else
                        break;
                }
            }
        }
    }
    return;
}

void Tetris::eliminate(){
    //所有的消除，即消除+下落
    int mul=1;
    while(true){
        //消除
        if(!one_time_eliminate(mul))
            break;
        mul++;
        drop();
    }
    return;
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
    int item=rand()%P;
    if(item==0){
        //生成道具
        nextBlock.cubes[0].x=0;nextBlock.cubes[0].y=centerY;
        for(int i=1;i<COUNT;i++){
            nextBlock.cubes[i].x=-1;nextBlock.cubes[i].y=-1;
        }
        for(int i=0;i<COUNT;i++){
            nextBlock.cubes[i].color=-1;
        }
        nextBlock.is_item=true;
        int index=rand()%ITEM_KIND;
        if (index==0)
            nextBlock.cubes[0].color=5;
        nextBlock.id=index;
    }
    else{
        nextBlock.is_item=false;
        can_be_held=true;
        //形状
        int index=rand()%7;//0 长条 1 左L 2 右L 3 方块 4 左z 5 中间凸起 6 z
        nextBlock.id=index;
        //颜色
        int last_color=0;
        for(int i=0;i<COUNT;i++){
            while(true){
                int c=(rand()%11)/2;
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
    return;
}

bool Tetris::inMap(int x,int y){
    if(x<0||x>=MAXX||y<0||y>=MAXY)
        return false;
    return true;
}

bool Tetris::move(int dx,int dy){
    //如果可以移动，就移动block
    //不能出界，也不能碰到已有的格子
    int tx[COUNT];int ty[COUNT];
    int Cnt=COUNT;
    if (block.is_item)
        Cnt=1;
    for(int i=0;i<Cnt;i++){
        tx[i]=block.cubes[i].x+dx;ty[i]=block.cubes[i].y+dy;
        if(!inMap(tx[i],ty[i]))
            return false;
    }
    //不能碰到已有的格子
    for(int i=0;i<Cnt;i++){
        if(grid[tx[i]][ty[i]].color!=-1)
            return false;
    }
    for(int i=0;i<Cnt;i++){
        block.cubes[i].x=tx[i];block.cubes[i].y=ty[i];
    }
    return true;
}

bool Tetris::rotate(){
    //默认左旋,以(block.x[2],bloxk.y[2])为旋转中心
    if (block.is_item)
        return false;
    if(block.id==3)
    {
        int c=block.cubes[0].color;
        block.cubes[0].color=block.cubes[1].color;
        block.cubes[1].color=block.cubes[3].color;
        block.cubes[3].color=block.cubes[2].color;
        block.cubes[2].color=c;
        return true;
    }//方形
    int dx[COUNT];int dy[COUNT];
    int cx=block.cubes[2].x;int cy=block.cubes[2].y;
    for(int i=0;i<COUNT;i++){
        dx[i]=-(block.cubes[i].y-cy);
        dy[i]=block.cubes[i].x-cx;
    }
    int newX[COUNT];int newY[COUNT];
    for(int i=0;i<COUNT;i++){
        newX[i]=cx+dx[i];newY[i]=cy+dy[i];
        if(!inMap(newX[i],newY[i]))
            return false;
        if(grid[newX[i]][newY[i]].color!=-1)
            return false;
    }
    //旋转
    for(int i=0;i<COUNT;i++){
        block.cubes[i].x=newX[i];block.cubes[i].y=newY[i];
    }
    return true;
}

void Tetris::changeBlock(){
    //将block变为grid
    int Cnt=COUNT;
    if (block.is_item)
        Cnt=1;
    for(int i=0;i<Cnt;i++){
        int x=block.cubes[i].x;int y=block.cubes[i].y;
        grid[x][y].color=block.cubes[i].color;
    }
    for(int i=0;i<COUNT;i++){
        block.cubes[i].x=0;
        block.cubes[i].y=0;
        block.cubes[i].color=-1;
    }
    return;
}

void Tetris::harder(){
    speed=score/30+1;
    if (speed>=8)
        speed=5;
    return;
}

void Tetris::crystal(){
    //消除一列
    int j=block.cubes[0].y;
    for(int i=0;i<MAXX;i++){
        grid[i][j].color=-1;
    }
    return;
}

void Tetris::boom(){
    int dx[9]={-1,-1,-1,0,0,0,1,1,1};
    int dy[9]={1,0,-1,1,0,-1,1,0,-1};
    for(int i=0;i<9;i++){
        int tx=block.cubes[0].x+dx[i];int ty=block.cubes[0].y+dy[i];
        if(inMap(tx,ty))
            grid[tx][ty].color=-1;
    }
    return;
}
