// https://www.nowcoder.com/question/next?pid=10611931&qid=161631&tid=26924438
// 时间限制：1秒

// 空间限制：32768K

// 牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字ai。
// 牛牛和羊羊轮流抽牌, 牛牛先抽, 每次抽牌他们可以从纸牌堆中任意选择一张抽出, 直到纸牌被抽完。
// 他们的得分等于他们抽到的纸牌数字总和。
// 现在假设牛牛和羊羊都采用最优策略, 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。


// 输入描述:
// 输入包括两行。
// 第一行包括一个正整数n(1 <= n <= 105),表示纸牌的数量。
// 第二行包括n个正整数ai(1 <= ai <= 109),表示每张纸牌上的数字。

// 输出描述:
// 输出一个整数, 表示游戏结束后牛牛得分减去羊羊得分等于多少。

// 输入例子1:
// 3
// 2 7 4

// 输出例子1:
// 5




#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main(void)
{
    int n=0;
    cin>>n;

    // 存储输入数据
    vector<int> input(n,0);

    for(int i=0;i<n;i++)
        cin>>input[i];

    sort(input.begin(),input.end());

    int sum_niu=0,sum_yang=0;

    int end_ = input.size()-(n/2*2);

    // 执行偶数次循环 得到基础结果
    for(int i=input.size()-1;i>=end_;)
    {
        sum_niu += input[i--];
        sum_yang += input[i--];
    }

    int res= sum_niu-sum_yang;
    if(end_)
    {
        res += input[0];
    }

    cout<<res<<endl;
    


    
    return 0;
}

