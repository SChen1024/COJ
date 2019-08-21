#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main(void)
{
    long long m=0,n=0;
    
    // cin>>n>>m;
    n = 323445962 ,m=371;
    
    // 定义周期数目
    int k=(n/m/2);
    
    // 结果等于周期数目 乘 m个数 乘 每个周期数的差值 = k*m*m
    long long res = k*m*m;
    
    cout<<res<<":"<<k<<":"<<INT_MAX<<endl;
    cout<<n<<":"<<n/2<<":"<<n/2*m<<endl;
    cout<<n/2*m<<endl;
    
    return 0;
}

