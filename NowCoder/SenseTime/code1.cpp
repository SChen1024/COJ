/*
1. 产线工人 小明

*/

// 包含必须的头文件

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

#define LOCAL_ 1

//计算 每小时工作 k 是否能够完成需求
bool fun(const vector<int> & vec,int k,int h)
{
    int sum = 0;

    for(int i=0;i<vec.size();i++)
    {
        // 计算浮点 向上取整
        sum += vec[i]/k;

        if(vec[i]%k)
            sum += 1;
    }


    // 如果事件符合 则可以满足
    return (sum <= h);
}




int main(void)
{
    int N=0,H=0;

    #if LOCAL_

        N = 5,H = 8;
    #else
        cin >> N >> H;
    #endif



    // 样品超过小时
    if(N>H) return 1;

    vector<int> counts(N,0);

    #if LOCAL_
        counts = {3,6,7,11,12};
    #else
    for(int i=0;i<N;i++)
        cin >> counts[i];
    #endif

    // 找到 每小时 至少的速度 K
    // 尝试二分查找
    int max_ =INT_MIN;

    for(int i=0;i<counts.size();i++)
    {
        max_ = max(max_,counts[i]);
    }    
    // 找到最大值
    // sort(counts.begin(),counts.end());

    int low = 0,high = max_;

    // cout<<max_<<endl;

    // 二分 查找最小能够完成的值
    while(low<high)
    {
        int mid = low + (high-low)/2;

        // 如果能够完成
        if(fun(counts,mid,H))
            high = mid;
        else
        {
            low = mid +1;
        }
        
        #if LOCAL_
         cout<<low<<":"<<mid<<":"<<high<<endl;
        #endif
    }

    cout<<high<<endl;

    return 0;
}