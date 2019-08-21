/*
3. 苹果堆 的分法
    1. 一共N堆苹果 第i个苹果的重量为 a[i]
    2. 分成两堆 A, B
    3. A堆总重量严格大于B堆总重量
    4. 把A堆任意一个苹果放到B堆, 则A堆总重量严格小于B堆总重量
    5. 每个苹果必须被分配 到其中一堆. 
满足上述要求的苹果分堆方案数目, 
*/

// 包含必须的头文件

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

#define LOCAL_ 1



int main(void)
{
    int N = 0;

    #if LOCAL_
        N = 4;
    #else
        cin >> N;
    #endif

    vector<int> a(N,0);

    #if LOCAL_
        a = {5,4,6,7};
    #else
    for(int i=0i<N;i++)
        cin >> a[i];
    #endif 

    // 将 数据排序 依次取相应的数据放入背包
    // sort(a.begin(),a.end());
    int sum = 0;    // 计算总重量
    for(int i=0;i<N;i++)
        sum += a[i];


    // 排序计算 能够得到所有 半数以上重量的 方案
    vector<vector<int>> bag(sum,vector<int>(2,0));

    for(int i=1;i<N;i++)
    {
        for(int j=1;j<=sum/2;j++)
        {

        }
    }




    return 0;
}