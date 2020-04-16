/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        // 使用 set  判断, 如果已经出现过 则, 结束, 否则 循环

        std::set<int> Set;

        // 在 n ==1  或者已经出现循环的情况下结束
        while(n != 1 && !Set.count(n)) 
        {
            Set.insert(n);

            // 依次获取每一位然后 平方累加
            int sum = 0;
            int cur = 0;
            while(n != 0)
            {
                cur = n%10;
                sum += cur*cur;

                n /= 10;
            }
            n = sum;
        }

        // 如果 == 1, 则是快乐数, 否则则是循环了
        return n == 1;
    }
};
// @lc code=end

