/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {

        //找到最后一个空格 如果没有找到 直接结束
        int N =s.size();
        if(!N)  return 0;

        // 滤除后面的空格 // 停在第一个非空格的位置
        int cur= N-1;
        while(cur>=0 && s[cur] == ' ')    cur--;
        
        int pos = cur;
        // 找到 尾部第一个空格
        while(pos>=0 && s[pos] != ' ')  pos --;

        return cur-pos;
        
    }
};
// @lc code=end

