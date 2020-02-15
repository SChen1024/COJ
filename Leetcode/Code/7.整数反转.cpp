/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {

        // 使用longlong  避免 数据溢出 以及数据出现错误
        long long  res = 0;
        while(x) {
            res = res*10 + (x%10);
            x /= 10;
        }
        
        return (res<INT_MIN || res >INT_MAX) ?0:res;
        
    }
};
// @lc code=end

