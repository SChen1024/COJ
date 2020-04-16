
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Number of Equivalent Domino Pairs
 */
class Solution {
public:

    // 将 vector 两位值  转换成 11-99
    // 手工设定 小数做十位 大数做个位
    int converTo100(vector<int> &vec)
    {
        if(vec[0]>vec[1])
            return vec[0]*10+vec[1];
        return vec[1]*10+vec[0];
    }

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {



        // 将每一个 子数组排序, 计算是否存在, 如果存在 计数
        vector<int> table(100,0);

        // 转换为 11-100 数字计数
        for(int i=0;i<dominoes.size();i++)
            table[converTo100(dominoes[i])] ++;
        
        //  对于每一个相同的组 可以形成 n(n-1)/2 组结果

        int res = 0;
        for(int i=0;i<100;i++)
        {
            res += table[i]*(table[i]-1) /2;
        }

        return res;
    }
};

