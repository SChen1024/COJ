//
// Created by hugoc on 2019/3/18.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {

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

        for(int i=0;i<nums.size();i++)
        {
            int com = target- nums[i];
            if(map.find(com) != map.end())
            {
                res.push_back(i+1);
                res.push_back(map[com]+1)

                return res;

            }
            map.insert(i,nums[i]);
        }

        return res;




    }
};
