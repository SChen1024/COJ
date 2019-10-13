/*
    ACM template 
*/


/*****************************************************************/
#include <bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define INF5 100005
#define INF9 1000000007
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define r1 rt<<1
#define r2 rt<<1|1
#define ri register int
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)         // for 循环 [a,b]:1
#define rep2(i,a,b,c) for(ri i=(a);i<=(b);i+=(c))       // for [a,b] :c
#define REP(i,a,b) for(ri i=(a);i>=(b);--i)             // 逆序 for 
#define REP2(i,a,b,c) for(ri i=(a);i>=(b);i-=(c))
using namespace std;

// 字符串读取输入的值
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}

// 将 ll 值输出
inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

// 输出 x 值
void printnum(int x)
{
	if(x>9)printnum(x/10);
	putchar(x%10^48);
}
// 输出加 换行
void print(int x,char ch)
{
	if(x<0){putchar('-');x=-x;}
	printnum(x);putchar(ch);
}

// *****************************************************************
// 计算所有的数字
/*
链接：https://ac.nowcoder.com/acm/contest/1114/B
来源：牛客网

题目描述 

\sum_{i=1}^{n}{}\sum_{j=1}^{i}{i*\left[ \frac{i}{j}\right]^{j}}∑ 
i=1
n
​	
 ∑ 
j=1
i
​	
 i∗[ 
j
i
​	
 ] 
j
  由于n越大jelly越美味，这里n<=3000000,只需求这个式子对1e9+7取模的值。
输入描述:
第一行输入一个整数 n。 1<=n<=3000000。
输出描述:
输出一个整数表示答案。
示例1
输入
复制
3
输出
复制
22

*/
/*
int solve(int n) {
    ll res = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            res = (res + i *(int) pow(i/j,j)) % INF9;
        }
    }
    return res;
}
*/
int arr[3000005];
int solve(int n) {
    if(n==1)    return 1;
    ll res = 0;
    for(int i=1;i<=n;i++) {
        res = (res + n*(int)pow(n/i,i)) % INF9;
    }
    res = (res + solve(n-1))%INF9;



    return (res + solve(n-1))%INF9;
}




// 主函数运行
int main(void)
{   
    // 使用in.txt 重定向 到输入
    freopen("in.txt","r",stdin);

    int n= 0;
    cin >> n;


    int res = solve(n);


    cout<<res<<endl;

    return 0;
}