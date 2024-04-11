#include"game.h"
#include<Weasy.h>

void mune(){printf("开始游戏输入1,结束输入0\n");}

int main()
{
    int input=0;
    mune();
    scanf("%d",&input);
    clear();
    switch (input)
    {
    case 0:
        printf("退出游戏");
        break;
    case 1://游戏进行
        InitBoard();
        BuildBoard();
        int Input=1;
        int count=1;
        do
        {   
            //游戏进行+判断输入是否合法
            int Judgement=1;
            do
            {
                int Row;
                int Col;
                printf("请输入坐标");
                scanf("%d %d",&Col,&Row);
                row=ROW+1-Row;
                col=Col;
                clear();
                Judgement=Judge(row,col);
            } while (Judgement);
            
            count++;
            //输出棋盘
            SettingBoard(row,col,count);
            BuildBoard();
            //判断游戏结束
            Input=reject(count);

        }while(Input);
        printf("\n我他妈的做到了!");
        break;
    
    default:printf("重开吧886");
        break;
    }
    system("pause");
    return 0;
}
