/*
2. 给定一个 整数  正  交换任意两位获得最大值

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
    int num = 0;

    #if LOCAL_
        num = 77;
    #else
        cin >> num;
    #endif

    // 从前往后 获取第一个 递增区域, 记录小值, 找到后面的最大值 交换 
    // 如果不存在递减 返回原始值

    string str = to_string(num);
    
    if(str.size()<2)
    {
        cout<<str<<endl;

        return 2;
    }

    int in_index = -1;
    for(int i=0;i<=str.size()-2;i++)
    {   
        // 后向差值 判断相差 // 判断递增点 // 找到第一个即可
        if(str[i+1] > str[i])
        {
            in_index = i;
            break;
        }

        #if LOCAL_
            cout<<i<<":"<<str[i]<<":"<<str[i+1]<<":"<<in_index<<endl;
        #endif
    }

    // 不存在递增 原样输出
    if(in_index == -1)
    {
        cout<<str<<endl;
        return 1;
    }

    int max_index=in_index;
    for(int i=in_index+1;i<str.size();i++)
    {
        // 找到最后 面的那个 最大值
        if(str[i]>=str[max_index])
            max_index = i;
    }

    if(max_index >= str.size())
    {
        cout<<str<<endl;
        return 3;
    }

    swap(str[in_index],str[max_index]);

    cout<<str<<endl;

    return 0;
}