/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */
class Solution {
public:
    string convertToBase7(int num) {
        
        if(num ==0)
            return "0";

        // 转换成正值
        int flg_minus = 0;
        if(num<0)
        {
            flg_minus = 1;
            num = -num;
        }
            
        string res ="";

        while(num)
        {
            res = to_string(num%7) + res;
            num = num/7;
        }
        
        if(flg_minus)
            res = "-" +res;

        
        return res; 
    }
};

