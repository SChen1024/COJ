/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++)  {
            if(!cnt) {
                cnt ++;
                cur = nums[i];
            } else {
                cnt += (nums[i] == cur)?1:-1;
            }
        }   

        return cur;
        
    }
};
// @lc code=end

