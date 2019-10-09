/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int,int> Map;


        // 找寻已经出现过的值是否存在差值
        for(int i=0;i<nums.size();i++) {
            if(Map.count(target-nums[i])) {
                return {Map[target-nums[i]],i};
            }
                
            Map[nums[i]] = i;   // 记录当前值
        }
        
        return {-1, -1};    // 如果不存在 目标值
    }
};
// @lc code=end

