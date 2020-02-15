/*
链接：https://ac.nowcoder.com/acm/problem/16599
来源：牛客网

请统计某个给定范围[L, R]的所有整数中，数字2出现的次数。

比如给定范围[2, 22]，数字2在数2中出现了1次，在数12中出现1次，在数20中出现1次，在数21中出现1次，在数22中出现2次，所以数字2在该范围内一共出现了6次。

输入描述:
输入共1行，为两个正整数L和R，之间用一个空格隔开。
输出描述:
输出共1行，表示数字2出现的次数。
示例1
输入
复制
2 22
输出
复制
6
示例2
输入
复制
2 100
输出
复制
20
备注:
1≤L≤R≤10000。

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