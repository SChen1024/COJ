/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (42.70%)
 * Total Accepted:    1.6M
 * Total Submissions: 3.7M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */

#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
             // 通过两步hash map 得到结果,
        // 将结果计算hashmap
        // 之后按照结果查找

        vector<int> res;
        // 加入hash map
        unordered_map<int,int> map;

//        for(int i=0;i<nums.size();i++)
//        {
//            map.insert(i,nums[i]);
//        }

        //  直接查找, 如果得到结果就直接返回 否则 添加map
        for(int i=0;i<nums.size();i++)
        {
            int com = target- nums[i];
            if(map.find(com) != map.end())
            {
                res.push_back(map[com]);
                res.push_back(i);
                return res;

            }
            map[nums[i]] = i;
        }

        return res;

    }
};

