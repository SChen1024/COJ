/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {

        int  n = nums.size();

        if(n==0)
            return 0;
        if(n == 1)
            return nums[0];


        // 计算一个区间的最大值, 不能连续取值, 所以 0 , 1 作为初始值
        // dp[i] == 标识{0,i} 能枪的最大值
        // dp[i] = max( dp[i-2] + nums[i], dp[i-1]);
        // dp[0] = nums[0]; dp[1] = max(num[0],nums[1]);

        std::vector<int> dp(n,0);

        dp[0] = nums[0];
        dp[1] = std::max(dp[0],nums[1]);

        for(int i=2;i<nums.size();i++)
        {
            dp[i] = std::max(dp[i-2]+nums[i],dp[i-1]);
        }

        return dp.back();
    }
};
// @lc code=end

