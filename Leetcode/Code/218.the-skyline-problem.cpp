/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<int> vec(INT_MAX,0);

        for (auto b:buildings)
        {
            vec[b[0]] +=b[2];
            vec[b[1]] -=b[2];
        }
        vector<vector<int>> res;
        if(buildings.size()==0)
            return res;



        int cur = vec[0];
        res.push_back({0,cur});

        for(int i=1;i<INT_MAX;i++)
        {
            if(vec[i] == 0)
                continue;
            cur += vec[i];
            res.push_back({i,cur});
        }

        return res;

    }
};

