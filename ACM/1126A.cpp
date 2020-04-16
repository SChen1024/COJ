#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

// 定义 位置 方向 结构体
struct Boy {
    int local;    // 初始位置
    int dir;    // 行进方向 0-- 左  1--右 

    // 初始化构造函数
    Boy(int l=0,int d=1) {
        local = l;
        dir = d;
    }
};
    
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

inline int readin()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
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
bool solve(ll x,ll y) {

    if(x-y<=1) {
        return false;
    }


    return true;
}



// 主函数运行
int main(void)
{   
    // 使用in.txt 重定向 到输入
    // freopen("in.txt","r",stdin);

    int T= 0;
    cin >> T;

    for(int i=1;i<=T;i++) {
        long long  x=0,y=0;
        cin >> x >> y;
        
    }
    return 0;
}