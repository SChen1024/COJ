// POJ 2982 数独问题计算

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

#define NUM 9
int pencilMark[NUM][NUM][NUM]; // 存储每个位置的铅笔标记值
int question[NUM][NUM]={};     // 题目值
int emptyCell[NUM][NUM];    // 未填的区域


// 谁都能够座标点
struct sPoint
{
    int rol;
    int col;
};

vector<sPoint> toFill;

// 判断 rc 位置 n 值
bool Judge(int r,int c,int n)
{

    return true;
}

// 深度优先计算
bool dfs(int)
{

    return true;
}

// rc 位置 标注 pencil 
void setMark(int row,int col,int n,int flg)
{

}

// 获取 位置点值
int getBlockNum(int r,int c)
{

    return 0;
}

// 清空
void Clear()
{

}

void main(void)
{
    int num=0;
    cin>>num; // 获取要计算的值


    // 循环读取几组 数据
    while(num--)
    {
        // 一次读取每一行
        for(auto i=0;i<NUM;i++)
        {
            string str = "";
            cin >> str;

            for(int j=0;j<NUM;j++)
            {
                // 获取每一个字符
                int n = str[i] -'0';
                question[i][j] = n;

                if(n == 0)
                {
                    toFill.push_back(sPoint{i,j});
                }
                else
                {
                    // 将相应位置设置为设定值
                    setMark(i,j,n,1);
                }
                




            }
            
        }




    }



    return 0;
}
















