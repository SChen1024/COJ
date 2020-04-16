/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        
        if(x <= 1) return x;

        // 找到满足的结果
        int l = 0, r= x;
        while(l<r) {
            int mid = (l+r)/2;
            if(x/mid >= mid) l = mid+1;
            else r = mid;
        }

        return r-1;
    }
};
// @lc code=end

