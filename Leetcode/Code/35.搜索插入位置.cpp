/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 二分查找直到满足

        int N = nums.size();
        if(!N)  return 0;
        int left=0,right = N-1;
        if(nums[right] <target) return N;

        while(left <= right) {
            int mid = left + (right-left) /2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                left = mid +1;
            } else {
                right = mid - 1;
            }

        }

        return left;
    }
};
// @lc code=end

