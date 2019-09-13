// 01 背包问题
/* 

01背包问题：
1、  给定n(n <= 1000)个物品，每个物品有个重量和价值(w[i], c[i])，
    在背包总容量为W（W<=1000）的情况下，求问能装下背包的最大价值是多少？
2、给定n(n <= 1000)个物品，每个物品有个重量和价值(w[i], c[i])，
   物品价值为(c[i] <= 10)，背包容量为W (W <= 100000000)，求问能装下背包的最大价值是多少？

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


const int N = 100;
const int W = 1000;
int main(void)
{
    vector<int> c(N,0); // 价值 / 花费
    vector<int> w(W,0); // 重量

    vector<int> dp(N+1,0);
    // dp[i][j]  表示 i个 物品 最大重量j  能够存放的最大价值

    for(int i=1;i<=N;i++)
    {
        for(int j=W;j>=w[i];j--)
        {
            dp[j] = max(dp[j], dp[j-w[i]]+c[i]);
        }
    }







    return 0;
}

class classB
{

};
class classA
{
     classB class_b;
};







