/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {

        // 将数据 
        int res = 0;
        map<char,int> Map{  {'I',1},
                            {'V',5},
                            {'X',10},
                            {'L',50},
                            {'C',100},
                            {'D',500},
                            {'M',1000}};

        // 如果 当前值大于前面的值 直接相加
        // 如果大于前面的值 减去两倍的值 减去前面多加的那个的结果
        for(int i=0;i<s.size();i++) {
            if(i==0 || Map[s[i]] <= Map[s[i-1]]) {
                res += Map[s[i]];
            } else {
                res += Map[s[i]] - 2*Map[s[i-1]];
            }
        }

        return res;
        
    }
};
// @lc code=end

