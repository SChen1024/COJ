/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // 使用 滑动窗口处理
        int res = 0,left = -1, n=s.size();
        vector<int> table(128,-1);

        for(int i=0;i<n;i++)
        {

            left = max(left, table[s[i]]);  // 找到left 最近一次出现位置


            table[s[i]] = i;    // 记录上一次出现的位置
            res = max(res,i-left);
        }

        return res;

    }
};
// @lc code=end

