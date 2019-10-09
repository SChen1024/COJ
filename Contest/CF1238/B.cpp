/*
    ACM template 
*/


/*****************************************************************/
#include <bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define INF5 100005
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


// 主函数运行
int main(void)
{   
    // 使用in.txt 重定向 到输入
    // freopen("in.txt","r",stdin);

    int T= read();
    int n,r;
    int a[INF5];    // 存储位置
    int bj,res;
    while(T--) {
        n = read();r=read();        // 输入敌人位置 和攻击范围
        rep(i,1,n) a[i] = read();
        sort(a+1,a+n+1);            // 将最大位置的敌人放在最右侧

        int ans = 0,now = 0;
        for(int i=n;i;--i) {
            if(a[i] <= now) break;  // 多次攻击范围累加 推到边缘了
            ans ++;     // 每次使用一次 至少攻击一个点
            now += r;   // 每次可以将 now 左边的值全部向前推r个位置 // 推到0位置 死
            while(i && a[i-1] == a[i]) --i;     // 相等的值全部略去 // 依次攻击杀死位置相等的所有制
        }
        // 输出最小次数
        write(ans);puts("");    
    }
    return 0;
}