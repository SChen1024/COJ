// 小Q定义了一种数列称为翻转数列:
// 给定整数n和m, 满足n能被2m整除。对于一串连续递增整数数列1, 2, 3, 4..., 每隔m个符号翻转一次, 最初符号为'-';。
// 例如n = 8, m = 2, 数列就是: -1, -2, +3, +4, -5, -6, +7, +8.
// 而n = 4, m = 1, 数列就是: -1, +2, -3, + 4.
// 小Q现在希望你能帮他算算前n项和为多少。

// 输入描述:
// 输入包括两个整数n和m(2 <= n <= 109, 1 <= m), 并且满足n能被2m整除。

// 输出描述:
// 输出一个整数, 表示前n项和。

// 输入例子1:
// 8 2

// 输出例子1:
// 8

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

int main(void)
{

    int n=0;
    int m=0;

    #if LOCAL_
        n=323445962 ,m=371;  // 对应输出 59999225951
    #else
        cin>>n>>m;
    #endif

    
    // 定义周期数目
    int k=(n/m/2);
    
    // 结果等于周期数目 乘 m个数 乘 每个周期数的差值 = k*m*m
    long long res = (long long)n/2*m;
    cout<<res<<endl;

    #if LOCAL_
    
    cout<<res<<":"<<k<<":"<<INT_MAX<<endl;
    
    #endif

    return 0;
}

