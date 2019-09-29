/*
链接：https://ac.nowcoder.com/acm/problem/16786
来源：牛客网

若一个数（首位不为零）从左向右读与从右向左读都一样，我们就将其称之为回文数。

例如：给定一个10进制数56，将56加56（即把56从右向左读），得到121是一个回文数。
又如：对于10进制数87：
STEP1：87+78  = 165                  STEP2：165+561 = 726

STEP3：726+627 = 1353                STEP4：1353+3531 = 4884

在这里的一步是指进行了一次N进制的加法，上例最少用了4步得到回文数4884。

写一个程序，给定一个N（2<=N<=10，N=16）进制数M，求最少经过几步可以得到回文数。如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible！”
输入描述:
两行，分别是N，M。
输出描述:
STEP=ans(ans表示答案)
示例1
输入
复制
9
87
输出
复制
STEP=6

*/


/*****************************************************************/
// 包含必须的头文件

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

// 定义本地
#define LOCAL_ 1

typedef vector<int>             Vint;
typedef vector<string>          Vstr;
typedef vector<vector<int>>     VVint;


// 常用输出函数 
// 一维 数组输出
template <typename T>
std::string CoutVec(const T& vec,int flg =0)
{
    std::string str="";
    for(int i=0;i<vec.size();i++)
    {
        str += to_string(vec[i])  +", ";
    }

    // 默认不输出 换行
    if(flg)
        str += "\n";
    // cout<<str;
    
    return str;
}


/*****************************************************************/
/* 
1. 将 int 逆转

*/
int reverseInt(int x)
{
    int res = 0;
    int flg = 1 ; // 负数标志位
    if(x<0)
    {
        flg = -1;
        x = -x;
    }

    // 逆转计算x 
    while(x)
    {
        int tmp = x%10;
        res = res*10 + tmp;
        x /= 10;
    }

    // 返回结果
    return res * flg;
}

int main(void)
{   
    int n=0;

    // 使用in.txt 重定向 到输入
    freopen("in.txt","r",stdin);
    cin>>n;

    int res = reverseInt(n);

    cout<<res<<endl;

    return 0;
}