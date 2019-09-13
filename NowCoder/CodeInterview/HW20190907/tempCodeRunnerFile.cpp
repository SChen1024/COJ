/*****************************************************************/
// 包含必须的头文件

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

// 定义本地
#define LOCAL_ 1

// 数据 通过 60

/*****************************************************************/

int  main(void)
{
    vector<int> vec;
    #if LOCAL_
        vec = {7,5,9,4,2,6,8,3,5,4,3,9};
    #else 
        int tmp;
        while(cin>>tmp)
            vec.push_back(tmp);
    #endif 

    vector<int> dp(vec.size(),INT_MAX);

    // 1步能够达到的位置
    for(int i=1;i<=vec.size()/2;i++)
    {
        dp[i] = 1;
    }

    // 后面计算 每一个位置累加能够达到的位置
    for(int i=0;i<vec.size();i++)
    {
        int tmp = (i+vec[i])%vec.size();
        dp[tmp] = std::min(dp[tmp],dp[i]+1);
        // cout<<"i:"<<i<<":"<<dp[i]<<endl;
    }

    // 判断 能否达到 否则返回 -1
    if(dp.back() == INT_MAX)
        cout<<-1<<endl;
    else
        cout<<dp.back()<<endl;

    return 0;
}