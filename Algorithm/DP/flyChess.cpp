/*
玩飞行棋，假设有n个格子，一开始在第一个格子，我们掷色子走，色子有6面，每一面都是1/6的概率，
到达第n个格子包括超过第n个格子结束。问，掷色子掷的次数的期望是多少

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
float preSixSum(vector<float>&dp,int i)
{
    return 0;
}
//dp 处理
float fun(int n)
{
    vector<float> dp(n+1,0);

    // 前

    dp[1] = 1.0f;
    dp[2] = 1.0 + 1/6.0f*(dp[1]);
    dp[3] = 1.0 + 1/6.0f*(dp[1] + dp[2]);
    dp[4] = 1.0 + 1/6.0f*(dp[1] + dp[2]+dp[3]);
    dp[5] = 1.0 + 1/6.0f*(dp[1] + dp[2]+dp[3]+dp[4]);
    dp[6] = 1.0 + 1/6.0f*(dp[1] + dp[2]+dp[3]+dp[4]+dp[5]);

    for(int i=7;i<=n;i++)
        dp[i] = 1 + 1/6.0f*(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6]);


    // 前面 n-6 造旧

    // 最后六个


    // 对于飞行棋 超过n 之后 反向走的
    // 最后 六个的值 不仅正向 还有反向
    dp[n-5] = 1 + 1/6.0f*(preSixSum(dp,n-5) + dp[n-1]);
    dp[n-4] = 1 + 1/6.0f*(preSixSum(dp,n-4) + dp[n-1] + dp[n-2]);
    dp[n-3] = 1 + 1/6.0f*(preSixSum(dp,n-3) + dp[n-1] + dp[n-2] + dp[n-3]);
    dp[n-2] = 1 + 1/6.0f*(preSixSum(dp,n-2) + dp[n-1] + dp[n-2] + dp[n-3] + dp[n-4]);
    dp[n-1] = 1 + 1/6.0f*(preSixSum(dp,n-1) + dp[n-1] + dp[n-2] + dp[n-3] + dp[n-4] + dp[n-5]);
    dp[n-0] = 1 + 1/6.0f*(preSixSum(dp,n));   // 直接到达




    return dp[n];
}



int main(void) 
{
    const int N = 30;
    vector<float> res(N-6,0);
    for(int i=7;i<=N;i++)
    {
        res[i-7] = fun(i);
    }

    // cout<< fun(10)<<":"<<to_string(fun(10))<<endl;
        

    
    cout<<CoutVec(res)<<endl;


    return 0;
}