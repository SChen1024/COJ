/*
链接：https://ac.nowcoder.com/acm/contest/190/G?&headNav=www
来源：牛客网

题目描述 
CSL手上有n个苹果，第i个苹果的质量是wi，现在他想把这些苹果分给他的好朋友wavator和tokitsukaze。但是CSL为了不让他们打架，根据质量决定尽量地均分成两堆分给他们。现在CSL想知道到底给每个人分多少质量的苹果。

注意：苹果不能劈开来，并且如果不能正好均分，tokitsukaze小姐姐会拿到重的那一堆。
输入描述:
第一行输入一个整数n(2 ≤ n ≤ 100)，第二行n个整数，表示每个苹果的质量wi(1 ≤ wi ≤ 100)。
输出描述:
输出两个整数，分别表示wavator和tokitsukaze得到的苹果的质量。
示例1
输入
3
2 2 2
输出
2 4
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
        str = to_string(vec[i]), +", ";
    }

    // 默认不输出 换行
    if(flg)
        str += "\n";
    // cout<<str;
    
    return str;
}

// 二维数组输出
template <typename T>
std::string CoutVec2(const T& vec,int flg =0)
{
    std::string str="";
    for(int i=0;i<vec.size();i++)
    {
        str += CoutVec(vec[i],flg);
    }
    
    return str;
}


/*****************************************************************/

int main(void)
{
    int N = 0;

    #if LOCAL_
        N = 3;
    #else
        cin >> N;
    #endif

    vector<int> a(N,0);

    #if LOCAL_
        a = {2,2,2};
    #else
    for(int i=0i<N;i++)
        cin >> a[i];
    #endif 

    // 将 数据排序 依次取相应的数据放入背包
    // sort(a.begin(),a.end());
    int sum = 0;    // 计算总重量   // 由于数据限定 不会溢出
    for(int i=0;i<N;i++)
        sum += a[i];

    // 初始化 DP 数组
    vector<int> dp(10000,0);

    for(int i=0;i<=N;i++)
    {
        for(int j= sum/2;j>=a[i];j++)
        {
            dp[j] = max(dp[j],dp[j-a[i]] +a[i]);
        }
    }





    return 0;
}