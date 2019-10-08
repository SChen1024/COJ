/*
5205. 独一无二的出现次数 

给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。

示例 1：

输入：arr = [1,2,2,1,1,3]
输出：true
解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
示例 2：

输入：arr = [1,2]
输出：false
示例 3：

输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
输出：true
 

提示：

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000

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

/*****************************************************************/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // 计算对应位置的字符串 ASCII差值, 
        // 然后转换为背包问题
        
        int N = s.size();
        vector<int> vec(N,0);
        for(int i=0;i<N;i++) {
            vec[i] = abs(s[i]-t[i]);     // 计算 单独值           
            // vec[i] = vec[i-1] + abs(s[i]-t[i]);     // 计算前缀和数组

        }
        
        cout<<CoutVec(vec)<<maxCost<<endl;

        // 使用双指针处理最大子区间长度
        int l=0;
        int max_len = 0,len = 0;
        int cur_sum = 0;

        for(int r=0;r<N;r++) {
            cur_sum += vec[r];
            if(cur_sum <= maxCost) {
                len ++;
                continue;
            } else {
                max_len = max(max_len,len);
                cur_sum -= vec[l++];
            }

        }


        return max(max_len,len);
        
    }
};

int main(void)
{   
    // 使用in.txt 重定向 到输入
    freopen("in.txt","r",stdin);
    
    string s,t;
    int m;
    cin>>s>>t>>m;

    Solution s1;
    int res = s1.equalSubstring(s,t,m);

    cout<<res<<endl;

    return 0;
}