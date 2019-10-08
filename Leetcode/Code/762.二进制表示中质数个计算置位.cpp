/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */


#include <set>

// @lc code=start
class Solution {
public:

    int calc1Nums(int n) {
        int cnt = 0;
        while(n) {
            cnt ++;
            n &= (n-1);
        }
        return cnt;
    }

    int countPrimeSetBits(int L, int R) {

        // 由于R 的最大值为 10^6 < 2^20
        // 只需要找到 20以内的质数即可 然后计算每个数字 中1的个数

        set<int> Set = {2,3,5,7,11,13,17,19};

        int cnt = 0;
        for(int i=L;i<=R;i++) {
            int tmp = calc1Nums(i);
            if(Set.count(tmp))
                cnt ++;
        }

        return cnt;       
    }
};
// @lc code=end

