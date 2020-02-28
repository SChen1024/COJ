/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:

    bool isNum(const char &ch) const
    {
        if(ch >= '0' && ch <= '9')
            return true;
        return false;
    }
    // 判断字符是否是字母
    bool isChar(const char &ch) const
    {
        // A-Z a-z 0-9 都是字符
        if(ch >= 'A' && ch <= 'Z')
            return true;
        if(ch >= 'a' && ch <= 'z')
            return true;
        return isNum(ch);
    }

    bool isEqual(const char &ch1, const char &ch2) const
    {
        // 如果字符相等 true
        if(ch1 == ch2)
            return true;
        // 判断 字符于数字的区别 0P  ASCII 差 32

        // 字符 大小写不同  ture
        int err = ch1 - ch2;
        if(err == 32 || err == -32)
        {
            if(isNum(ch1) || isNum(ch2))
                return false;
            return true;
        }
        return false;

    }

    bool isPalindrome(string s) {

        // 使用左右指针, 判断字符是否相等
        int n = s.size();

        int l = 0, r = n-1;

        while(l < r)
        {
            while(!isChar(s[l]) && l < r)
                l++;
            
            while(!isChar(s[r]) && l < r)
                r --;
            
            // printf("l: %d : %c, r: %d : %c \n",l, s[l],r, s[r]);
            if(!isEqual(s[l], s[r]))
                return false;

            l ++;
            r --;

        }
        
        return true;

    }
};
// @lc code=end

