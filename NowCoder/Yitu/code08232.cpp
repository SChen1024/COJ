/*****************************************************************/
// 包含必须的头文件

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


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



// 定义本地
#define LOCAL_ 1
/*****************************************************************/



int main(void)
{
    int N =0,K=0;


#if LOCAL_
    N = 2,K = 7;
#else
    cin>>N>>K;
#endif

    vector<vector<int>> vec(N,vector<int>(6,0));

#if LOCAL_
    vec[0] = {1,2,3,4,5,6},vec[1] = {1,2,3,4,5,6};
#else
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<6;j++)
            cin>>vec[i][j];
    }
#endif

    // 暴力尝试 破解
    vector<int> sum(1400,0);

    vector<vector<int>> dp(N*6,vector<int>(6,0));
    
    while








    return 0;
}