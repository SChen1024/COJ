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
    链接：https://ac.nowcoder.com/acm/contest/1114/A
来源：牛客网

超越学姐非常喜欢自己的名字，以至于英文字母她只喜欢“c”和“y”。因此超越学姐喜欢只含有“c”和“y”的字符串，且字符串中不能出现两个连续的“c”。请你求出有多少种长度为n的字符串是超越学姐喜欢的字符串。答案对1e9+7取模。
输入描述:
输入一个整数n。
1<=n<=100000
输出描述:
输出一个整数表示答案。
示例1
输入
复制
3
输出
复制
5
说明
cyy,cyc,yyy,yyc,ycy

*/

// 从n个里面选择m个
int Cselct(int n,int m) {
    if(m==0)    return 1;

    ll res = 1,res_n=1,res_m=1;
    for(int i=1;i<=m;i++) {
        
    }

    return 0;
}


int a[100005][2];
int solve(int n) {
    // 累计解算 C_y^c 的结果值
    // C 之后只能接C y后面都能接
    a[0][0]  = 1,a[0][1] =1;
    for(int i=1;i<n;i++) {
        a[i][1] = (a[i-1][0] + a[i-1][1])%INF9;
        a[i][0] = a[i-1][1];
    }
    return (a[n-1][0] + a[n-1][1])%INF9;
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