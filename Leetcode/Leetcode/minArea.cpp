/*
    1. 找到多个数组的最小公共区间

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


/*****************************************************************/



class Solution {
public:

    // 找到满足多个数组的最小公共子区间
    // 一个数组记录每个数组的最小值,和索引值  
    // 每次处理 数组的 范围就是 当前区间的值 最终求最小值就好
    // 依次删除此数组最小值, 并由被删除的数组的后一个补充 (重复值继续)
    // 在某一个数组为空之时得到的值就是左边界 
    // 最小值数组中的最大值 就是右边界
    int minCommArea(vector<vector<int>> & vec)
    {
        int K = vec.size();
        vector<vector<int>> minVec(K,vector<int>(2,0));    // 记录K个数组的最小值

        // 处理
        for(int i=0;i<K;i++)
        {
            minVec[i][0] = 0;
            minVec[i][1] = vec[i][0];
        }

        while(1)
        {
            // 
        }

        



    }
};

int main(void)
{
    Solution s1;

    vector<vector<int>> test = {
        {4,10,15,24,26},
        {0,9,12,20},
        {5,18,22,30}
    };



    return 0;
}