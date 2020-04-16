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
        str += to_string(vec[i]) +", ";
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
Problem Description
有一张 nn 个点的完全无向图，点的标号是 1...n1...n，其中边 (i,j)(i,j) 的长度是 ixorji xor j，现在你需要求出点 11 到点 nn 的最短路的长度。

Input
第一行一个正整数 TT 表示数据组数 1\leq T\leq 1001≤T≤100

对于每组数据：第一行一个正整数 nn 表示点数 (2\leq n\leq 10^5)(2≤n≤10
​5
​​ )

Output
输出 TT 行，每行一个整数表示点 11 到点 nn 的最短路

Sample Input
1
3
Sample Output
Copy
2

*/
#define MAX_  100000

int main(void)
{
    int T = 0;
    #if LOCAL_
    T = 1;
    #else
    cin>>T;
    #endif 

    

#if 0
    // 构造邻接表 输出
    vector<vector<int>> vec(MAX_+1,vector<int>(MAX_+1,0));

    for(int i=1;i<vec.size();i++)
        for(int j=1;j<i;j++)
            vec[i][j] = (i^j);



cout<<CoutVec2(vec,1);
    
#endif 


    // 数据分别输入
    for(int i=0;i<T;i++)
    {
        int n=0,m=0;
        #if LOCAL_
            n = 4, m=4;
        #else
        cin>>n>>m;
        #endif 

        vector<vector<int>> vec(n+1,vector<int>(n+1,INT_MAX));

        for(int j=0;j<m;j++)
        {
            int u=0,v=0,w=0;
            #if LOCAL_
                vec = {{INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                        {INT_MAX,0,1,INT_MAX,1},
                        {INT_MAX,1,0,1,INT_MAX},
                        {INT_MAX,INT_MAX,1,0,1},
                        {INT_MAX,1,INT_MAX,1,0}};

            #else 
            cin>>u>>v>>w;
            #endif

            vec[u][v] = w;
            vec[v][u] = w;
        }

        

    }




    return 0;
}