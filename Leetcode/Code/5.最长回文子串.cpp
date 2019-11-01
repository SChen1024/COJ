/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {

     if(s.empty())  return "";

     int n =s.size();
     int dp[n][n] = {0},left = 0,len = 1;
     for(int i=0;i<n;i++)
     {
         dp[i][i] =1;
         for(int j=0;j<i;j++)
         {
             dp[j][i] = (s[i]==s[j] && (( i-j <2 ) ||dp[j+1][i-1]));
             if(dp[j][i] && len<i-j+1)
             {
                 len = i-j+1;
                 left = j;
             }
         }
     }
    return s.substr(left,len);

    }
};
// @lc code=end

