// https://www.nowcoder.com/question/next?pid=10611931&qid=161634&tid=26924438

// 小Q的公司最近接到m个任务, 第i个任务需要xi的时间去完成, 难度等级为yi。
// 小Q拥有n台机器, 每台机器最长工作时间zi, 机器等级wi。
// 对于一个任务,它只能交由一台机器来完成, 如果安排给它的机器的最长工作时间小于任务需要的时间, 则不能完成,如果完成这个任务将获得200 * xi + 3 * yi收益。

// 对于一台机器,它一天只能完成一个任务, 如果它的机器等级小于安排给它的任务难度等级, 则不能完成。

// 小Q想在今天尽可能的去完成任务, 即完成的任务数量最大。如果有多种安排方案,小Q还想找到收益最大的那个方案。小Q需要你来帮助他计算一下。


// 输入描述:
// 输入包括N + M + 1行,
// 输入的第一行为两个正整数n和m(1 <= n, m <= 100000), 表示机器的数量和任务的数量。
// 接下来n行,每行两个整数zi和wi(0 < zi < 1000, 0 <= wi <= 100), 表示每台机器的最大工作时间和机器等级。
// 接下来的m行,每行两个整数xi和yi(0 < xi < 1000, 0 <= yi<= 100), 表示每个任务需要的完成时间和任务的难度等级。

// 输出描述:
// 输出两个整数, 分别表示最大能完成的任务数量和获取的收益。

// 输入例子1:
// 1 2
// 100 3
// 100 2
// 100 1

// 输出例子1:
// 1 20006

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
// 参考链接 https://blog.csdn.net/chen134225/article/details/81047868
// 按照时间和等级降序，这样保证取到的一定是收益最大的解（因为时间的收益严格大于等级，所以时间作为第一关键字，如果能完成收益大的任务，自然不会去完成收益低的任务）；
// 然后在此基础上，加所有工作时间大于等于任务的机器加入multiset中，取出等级最接近任务等级的，且大于等于任务等级的，就是lower_bound，这样可以保证完成的任务一定是最多的，不会遗漏。
// （因为任务和机器都按照时间进行过排序，那么在set中机器的时间一定是可以完成后续任务的，它们是被时间更长的任务选择进来的，所以在此不需要考虑机器的工作时间了，在后面他们的时间不会有区别都是一样的，为了防止后面出现等级更大的任务，那么肯定要选择等级刚好大于任务的机器了），
// 这样两次贪心下来得到的就是一定是最优解了，而且第二次贪心可以二分，不会超时。


int main(void)
{
    int k,a,x,y,b;

    #if LOCAL_
        k=5;
        a=2,x=3,b=3,y=3;

    #else 
    cin>>k;
    cin>>a>>x>>b>>y;
    #endif

    // 01 背包问题  x个a 和 y个 B 背包为 K
    vector<int> dp(k+1,0);
    dp[0] =1;

    // 计算初始状态
    for(int i=0;i<x;i++) {
        for(int j=k;j>=a;j--) {
            dp[j] = (dp[j] + dp[j-a])%MAX;
        }
    }

    for(int i=0;i<y;i++) {
        for(int j=k;j>=b;j--) {
            dp[j] =(dp[j]+dp[j-b])%MAX;
        }
    }

    cout<< dp[k]<<endl;

    // cout<<CoutVec(dp)<<endl;

    
    return 0;
}
