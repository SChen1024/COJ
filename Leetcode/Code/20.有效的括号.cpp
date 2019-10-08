/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start



class Solution {
public:
    bool isValid(string s) {

        int N = s.size();
        if(N<0 || N%2) {
            return false;
        }
        // 设计一个 Stack  进行括号匹配
        // 左侧括号式 压入一个右侧括号,
        map<char,char> Map = {{'(',')'},
                            {'[',']'},
                            {'{','}'}
                            };
        stack<char> St;
        for(int i=0;i<N;i++) {
            char tmp = s[i];

            if(Map.count(tmp)){
                St.push(Map[tmp]);  // 压入 对应的符号
            } else {
                // 如果栈空 或者 栈顶不相等, 则必定不匹配
                if(St.empty() || St.top() != tmp) {
                    return false;
                }else {
                    St.pop();
                }
            }
        }

        return St.empty();  //

    }
};
// @lc code=end

