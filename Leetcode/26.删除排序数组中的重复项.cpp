/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // 已知有序, 判断是否相等前一个数字即可, 使用双指针判定
        int left = 0,right = 0;
        int N = nums.size();
        if(N<=1) { return N;}

        for(right=0;right<N;right++) {
            if(nums[left] != nums[right]) {
                nums[++left] = nums[right];
            }
        }

        return ++left;
    }
};
// @lc code=end

