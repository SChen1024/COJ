#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;


int main(void)
{
    int k,a,x,y,b;
    cin>>k;
    cin>>a>>x>>b>>y;


    vector<int> dp(k+x);

    vector<int> p(x+y+1);

    for(int i=1;i<=x;i++)
        p[i] = a;
    for(int i=x+1;i<=y;i++)
        p[i] = b;

    const int MOD  = 10000000007;
    for(int i=1;i<=x+y;i++)
        for(int j=k;j>=p[i];j--)
            dp[j] = (dp[j]%MOD + dp[j-p[i]]%MOD)%MOD;

    cout<<dp[k]<<endl;

    
    return 0;
}
