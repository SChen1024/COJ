/**
 * @file 70.cc
 * @author {SChen00} ({hugochen1024@gmai.com})
 * @brief 
 * @version 0.1
 * @date 2019-04-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>

using namespace std;

/**
 * @brief 
 * 
 */
class Solution{
    public:
    int climbStairs(int n)
    {
        vector<int> f(n+1,0);
        f[0] = f[1] = 1;

        for(auto i=2;i<=n;i++)
        {
            f[i] = f[i-1] +f[i-2];
        }

        return f[n];
    }
};

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
// 主函数控制输出
int main(int argc, char ** argv)
{
    cout << Solution().climbStairs(15) << endl;
    return 1;
}


