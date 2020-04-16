// https://www.nowcoder.com/question/next?pid=10611931&qid=161633&tid=26924438
// 小Q有X首长度为A的不同的歌和Y首长度为B的不同的歌，现在小Q想用这些歌组成一个总长度正好为K的歌单，每首歌最多只能在歌单中出现一次，在不考虑歌单内歌曲的先后顺序的情况下，请问有多少种组成歌单的方法。

// 输入描述:
// 每个输入包含一个测试用例。
// 每个测试用例的第一行包含一个整数，表示歌单的总长度K(1<=K<=1000)。
// 接下来的一行包含四个正整数，分别表示歌的第一种长度A(A<=10)和数量X(X<=100)以及歌的第二种长度B(B<=10)和数量Y(Y<=100)。保证A不等于B。

// 输出描述:
// 输出一个整数,表示组成歌单的方法取模。因为答案可能会很大,输出对1000000007取模的结果。

// 输入例子1:
// 5
// 2 3 3 3

// 输出例子1:
// 9

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


#if LOCAL_

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

// 二维数组输出
template <typename T>
std::string CoutVec2(const T& vec,int flg =1)
{
    std::string str="";
    for(int i=0;i<vec.size();i++)
    {
        str += CoutVec(vec[i],flg);
    }
    return str;
}

#endif

/*****************************************************************/
#define MAX  1000000007
int main(void)
{
    int k,a,x,y,b;

    #if LOCAL_
        k=5;
        a=2,x=3,b=3,y=3;

    #else 
    cin>>k;
    cin>>a>>x>>b>>y;
    #endif

    // 01 背包问题  x个a 和 y个 B 背包为 K
    vector<int> dp(k+1,0);
    dp[0] =1;

    // 计算初始状态
    for(int i=0;i<x;i++) {
        for(int j=k;j>=a;j--) {
            dp[j] = (dp[j] + dp[j-a])%MAX;
        }
    }

    for(int i=0;i<y;i++) {
        for(int j=k;j>=b;j--) {
            dp[j] =(dp[j]+dp[j-b])%MAX;
        }
    }

    cout<< dp[k]<<endl;

    // cout<<CoutVec(dp)<<endl;

    
    return 0;
}
