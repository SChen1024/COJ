#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int N = digits.size();

        if(N<=0)
            return digits;
        
        int tmp=digits[N-1] +1;
        digits[N-1] = tmp%10;
        int flg = tmp/10;

        for(int i=N-2;i>=0;i--)
        {
            tmp = digits[i]+flg;
            digits[i] = tmp%10;
            flg = tmp /10;
        }

        if(flg)
            digits.insert(digits.begin(),flg);
        return digits;

        
    }
};

