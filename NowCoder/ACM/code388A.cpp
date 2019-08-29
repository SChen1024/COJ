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
链接：https://ac.nowcoder.com/acm/evaluate/388/A
来源：牛客网

       牛可乐和牛妹在玩一个游戏，牛可乐给出a个黄球，b个红球，还有一个正整数K。让牛妹把这些球进行排列，围成一圈。使得这些球满足下列条件：每次删除第K个球（第一个球是从1开始数的）。删除之后被删除的那个球后面的一个球再变成第一个球。最后可以在不删除黄球的情况下删除掉所有的红球。
      请你帮助牛妹完成牛可乐的游戏。
输入描述:
第一行给出一个正整数a表示a个黄球，
第二行给出一个正整数b表示b个红球，
第三行给出一个正整数K表示每次删除第K个球。
（0 \leq a \leq 25,0 \leq b \leq 25,0 \leq K \leq 1000 ）（0≤a≤25,0≤b≤25,0≤K≤1000）
输出描述:
用M表示黄球，F表示红球，输出牛妹给出的答案。
示例1
输入
复制
5
3
2
输出
复制
MFMFMFMM
说明
对于样例1，第一回合删除第二个球。变成 "M_MFMFMM"，新的起点从刚刚删除的球的后一个开始，整个环变成"MFMFMMM"。

第二回合再删除第二个球。变成"M_MFMMM",整个环变成"MFMMMM"。

第三回合再删除第二个球。变成"M_MMMM",这样就在不删除黄球的情况下删除掉的所有的红球。
示例2
输入
复制
7
3
1
输出
复制
FFFMMMMMMM
*/

int main(void)
{
    int a=0,b=0,K=0;
    #if LOCAL_
        a = 5,b=3,K=3;
    #else 
        cin>>a>>b>>K;
    #endif 

    int num = a+b;
    // 初始化 为ie用于计数
    vector<int> res(num,1);

    int cur = 0;
    // 依次删除 直到 为a
    while(num >a)
    {
        int pre = cur;
        // 计算累加值 // 只计算没被剔除的值 // 游标记录当前值
        int cnt = 1;
        while(cnt <= K)
        {
            if(res[(pre+cnt-1)%num])
            {
                
                cnt ++;
                cur = pre + cnt -1; // 计算当前指向值
            }

            cout<<CoutVec(vector<int>{pre,cur,cnt})<<endl;


        }

        // cur ++;

        res[cur-1] = 0;

        
        num --;
    }

    cout<<CoutVec(res);







    return 0;
}