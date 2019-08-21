/*
时间限制：1秒

空间限制：32768K

小Q的父母要出差N天，走之前给小Q留下了M块巧克力。小Q决定每天吃的巧克力数量不少于前一天吃的一半，但是他又不想在父母回来之前的某一天没有巧克力吃，请问他第一天最多能吃多少块巧克力

输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，表示父母出差的天数N(N<=50000)和巧克力的数量M(N<=M<=100000)。

输出描述:
输出一个数表示小Q第一天最多能吃多少块巧克力。

输入例子1:
3 7

输出例子1:
4

*/


#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
// 每天 d n 天最少吃多少
int sum1(int n,int d)
{
    int sum =0;
    for(int i=0;i<n && d !=0;i++)
    {
        sum += d;
        d  = (d+1)>>1;
    }

    return sum;
}

int fun(int n,int m)
{
    
    // 如果根据等比数列计算 吃的巧克力的和
    // 由于数据 不允许操作半块巧克力, 计算 只等进行累计计算
    if(n==1) return m;
    int l=0,h=m;

    while(l<h)
    {
        int mid = (l + (h-l+1)>>1);

        int sum = sum1(n,mid);
        if(sum == m) 
            return mid;
        else if(sum<m)
            l = mid;
        else
            h = mid -1;

    }

    return h;
}

int main(void)
{
    int n=0,m=0;
    // cin>>n>>m;
    n=3,m=7;

    int res = fun(n,m);

    cout<<res<<endl;


    
    return 0;
}









