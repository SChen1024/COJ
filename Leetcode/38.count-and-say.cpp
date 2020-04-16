#include <string>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say  暴力求解
 */
class Solution {
public:
    string countAndSay(int n) {

        string res = "1";

        if(n==1)    
            return res;
        
        while(--n)
        {
            string cur = "";

            for(int i=0;i<res.size();i++)
            {
                int cnt = 1;
                while(i<res.size()-1 && res[i] == res[i+1])
                {
                    ++cnt ;
                    ++i;
                }
                cur += to_string(cnt) + res[i];
            }

            res = cur;
        }
        
        return res;
    }
};

