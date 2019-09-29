/*
链接：https://ac.nowcoder.com/acm/problem/16538
来源：牛客网

试计算在区间1 到n 的所有整数中，数字x（0 ≤ x ≤ 9）共出现了多少次？
例如，在1到11 中，即在1、2、3、4、5、6、7、8、9、10、11 中，数字1 出现了4 次。
输入描述:
输入共1行，包含2个整数n、x，之间用一个空格隔开。
输出描述:
输出共1行，包含一个整数，表示x出现的次数。
示例1
输入
复制
11 1
输出
复制
4
备注:
对于100%的数据，1≤ n ≤ 1,000,000，0 ≤ x ≤ 9。

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
/* https://blog.csdn.net/Koala_Tree/article/details/79524603
    总结一下以上的算法，可以看到，当计算右数第 i 位包含的 X 的个数时:
        取第 i 位左边（高位）的数字，乘以 10i−1，得到基础值 a。
        取第 i 位数字，计算修正值：
            如果大于 X，则结果为 a+10i−1。
            如果小于 X，则结果为 a。
            如果等 X，则取第 i 位右边（低位）数字，设为 b，最后结果为 a+b+1。
*/
int  countX(int n,int x)
{
    int cnt= 0 ,k = 0;
    for(int i=1; k = n/i; i *= 10)
    {
        // k/10 表示高位数字
        int high = k /10;
        if(x == 0)      // 处理 0 的情况
        {
            if(high)
            {
                high --;
            }
            else
                break;
        }
        cnt += high * i;

        // 当前位
        int tmp = k%10;
        // 大于情况全 加上
        if(tmp >x)
        {
            cnt += i;
        }
        else if(tmp == x)   // 等于的话 考虑低位
        {
            cnt += n - k*i +1;
        }
    }
    return cnt;
}

int main(void)
{   
    int n=0,x= 0;

    // 使用in.txt 重定向 到输入
    freopen("in.txt","r",stdin);
    cin>>n>>x;

    int res = countX(n,x);

    cout<<res<<endl;

    return 0;
}