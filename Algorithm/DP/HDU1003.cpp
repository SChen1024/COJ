/*
    HDU 1003

    Max Sum
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 331501    Accepted Submission(s): 78920


Problem Description
Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
 

Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).
 

Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.
 

Sample Input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
 

Sample Output
Case 1:
14 1 4

Case 2:
7 1 6
 

Author
Ignatius.L
 

Recommend
We have carefully selected several similar problems for you:  1176 1087 1069 2084 1058 
 

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
        str = to_string(vec[i]), +", ";
    }

    // 默认不输出 换行
    if(flg)
        str += "\n";
    // cout<<str;
    
    return str;
}

// 二维数组输出
template <typename T>
std::string CoutVec2(const T& vec,int flg =0)
{
    std::string str="";
    for(int i=0;i<vec.size();i++)
    {
        str += CoutVec(vec[i],flg);
    }
    return str;
}
/*****************************************************************/

// 找到 数组中的最大 子序列 满足和最大
// sum[i] = max(sum[i-1] +a[i], a[i]);
void MaxSum(vector<int> &vec)
{
    //vector<int> sum(vec.size(),0);
    int start=0,end=-1;    // 记录其实位置和结束位置  // 临时子区间
    int start_ =-1,end_=-1;    // 记录 最终的其实值和结束值
    int max_ = INT_MIN;

    int sum = vec[0];    // 存储初始值
    for(int i=1;i<vec.size();i++)
    {
        if(sum <0 )
        {
            sum = vec[i];
            start = i;
            end = i;
        }
        else
        {
            // 状态转移 更新 结束值
            sum = sum + vec[i];
            end = i;
        }

        if(max_ < sum)
        {
            max_ = sum;
            start_ = start;
            end_ = end;
        }
    }

    cout<<max_<<" "<<start_+1<<" "<<end_+1<<endl;

}




int main(void)
{
    int n=0;

    #if LOCAL_
    n = 1;
    #else
    cin>>n;
    #endif
    // 读取一个 数据组数目
    for(int k=0;k<n;k++)
    {
        int N= 0;
        #if LOCAL_
            N = 7;
        #else
        cin>>N;
        #endif 

        vector<int> input(N,0);

        #if LOCAL_
        input = {0,6,-1,1,-6,7,-5};
        #else
        for(int j=0;j<N;j++)
            cin>>input[i]; 
        #endif 
        // 对于每一个测试样例 得到计算结果

        cout<<"Case "<<k+1<<":"<<endl;
        MaxSum(input);
        cout<<endl;

    }

    return 0;
}