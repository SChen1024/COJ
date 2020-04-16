#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    bool divisorGame(int N) {


        if(N%2 ==0 )
            return true;
        
        return false;

    // 维持两个表, 一定赢 的数据存入数组 wins中,
    // 计算N 减去自己的因子, 如果在数组中 则必输, 否则一定赢 存入数组
        
        // 计算
    
        unordered_set<int> wins;
        wins.insert(2);
        
        // 计算一下每一个因子 如果存在一个因子不在数组内 则 可以必胜
        for(int i=3;i<N+1;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(i%j == 0)
                {
                    if(wins.count(i-j) ==0)
                    {
                        wins.insert(i);
                        break;
                    }
                }

            }
        }
        
        
        if(wins.count(N))
            return true;
        return false;
        
        
        
        
    }
};



int main() 
{
    Solution s1;

    for(int i=0;i<100;i++)
    {
        if(s1.divisorGame(i))
            cout<<i<<":";
    }

    return 1;
}