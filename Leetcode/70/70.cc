#include <iostream>
#include <vector>

using namespace std;


class Solution{
    public:
    int climbStairs(int n)
    {
        vector<int> f(n+1,0);
        f[0] = f[1] = 1;

        for(auto i=0;i<=n;i++)
        {
            f[i] = f[i-1] +f[i-2];
        }

        return f[n];
    }
};



int main(int argc, char ** argv)
{
    cout << Solution().climbStairs(15) << endl;
    return 1;
}


