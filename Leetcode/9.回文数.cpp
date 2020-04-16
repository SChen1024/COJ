/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0) return false;
        if(x<10)    return true;
        // 计算两个指针 数字初一相应的值 自后得到的结果
        // 得到 x 的量级 100== 10^3 量级
        long long  div = 1;
        while ( x / div >= 10) div *= 10;
        while (x > 0) {
            int first = x / div;
            int last = x % 10; 
            if (first != last) return false;
            x = (x % div) / 10;
            div = div / 100;           
        }
        return true;

        
    }
};
// @lc code=end

