/*
链接：https://ac.nowcoder.com/acm/problem/16584
来源：牛客网

给定一个整数，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见样例2）。
输入描述:
一个整数 N。
输出描述:
一个整数，表示反转后的新数。
示例1
输入
复制
123
输出
复制
321
示例2
输入
复制
-380
输出
复制
-83
备注:
-1,000,000,000≤N≤1,000,000,000

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