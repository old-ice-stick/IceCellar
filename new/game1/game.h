#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
//声明变量
int col;
int row;
//给定棋盘
char Board[ROW][COL];
//判断输入是否合法
int Judge(int row,int col){
    if(Board[row-1][col-1]==' '){return 0;}
    printf("输入不合法,请重新输入\n");
    return 1;
}
//初始化棋盘
void InitBoard()
{
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++){Board[i][j]=' ';}
    }
}
//双人下棋
void SettingBoard(int row,int col,int count)
{
    int Reject=count%2;
    switch (Reject)
    {
    case 0:
        Board[row-1][col-1]='O';
        break;
    default:
        Board[row-1][col-1]='x';
        break;
    }
}
//创建棋盘
void BuildBoard()
{ 
    system("cls");
    int i=0;
    for(i=0;i<ROW;i++)
    {
        int j=0;
        for(j=0;j<COL;j++)
        {
            printf(" %c ",Board[i][j]);
            if(j!=COL-1){printf("|");}
            else{printf("\n");}
        }
        if(i<ROW-1)
        {   
            int j=0;
            for (j = 0; j <COL; j++)
            {
                printf("---");
                if(j<COL-1){printf("|");}
                else{printf("\n");}
            }
        }
    }
}
//判断胜负
int reject(int count)
{
    int Reject=count%2;
    //用户几,reject=0时为玩家1
    int i=0;
    for(i=0;i<ROW;i++)
    {
        //判断row的胜利
        if(Board[i][0]==Board[i][1]&&Board[i][0]==Board[i][2]&&Board[i][0]!=' ')
        {
            if(Reject){printf("玩家2赢了");}
            else{printf("玩家1赢了");}
            return 0;
        }
        //判断col的胜利
        if(Board[0][i]==Board[1][i]&&Board[1][i]==Board[2][i]&&Board[0][i]!=' ')
        {
            if(Reject){printf("玩家2赢了");}
            else{printf("玩家1赢了");}
            return 0;
        }
    }
    //判断对角线的胜利
    if(Board[0][0]==Board[1][1]&&Board[0][0]==Board[2][2]&&Board[0][0]!=' ')
    {
        if(Reject){printf("玩家2赢了");}
        else{printf("玩家1赢了");}
        return 0;
    }
    if(Board[0][2]==Board[1][1]&&Board[2][0]==Board[1][1]&&Board[1][1]!=' ')
    {
        if(Reject){printf("玩家2赢了");}
        else{printf("玩家1赢了");}
        return 0;
    }
    //平局
    if(count==10)
    {
        printf("平局");
        return 0;
    }
    return 1;
}
