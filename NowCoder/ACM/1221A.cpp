/*
链接：https://ac.nowcoder.com/acm/problem/16786
来源：牛客网

若一个数（首位不为零）从左向右读与从右向左读都一样，我们就将其称之为回文数。

例如：给定一个10进制数56，将56加56（即把56从右向左读），得到121是一个回文数。
又如：对于10进制数87：
STEP1：87+78  = 165                  STEP2：165+561 = 726

STEP3：726+627 = 1353                STEP4：1353+3531 = 4884

在这里的一步是指进行了一次N进制的加法，上例最少用了4步得到回文数4884。

写一个程序，给定一个N（2<=N<=10，N=16）进制数M，求最少经过几步可以得到回文数。如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible！”
输入描述:
两行，分别是N，M。
输出描述:
STEP=ans(ans表示答案)
示例1
输入
复制
9
87
输出
复制
STEP=6

*/


/*****************************************************************/
// 包含必须的头文件

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

// 定义本地
#define LOCAL_ 1

typedef vector<int>             Vint;
typedef vector<string>          Vstr;
typedef vector<vector<int>>     VVint;


// 常用输出函数 
// 一维 数组输出
template <typename T>
std::string CoutVec(const T& vec,int flg =0)
{
    std::string str="";
    for(int i=0;i<vec.size();i++)
    {
        str += to_string(vec[i])  +", ";
    }

    // 默认不输出 换行
    if(flg)
        str += "\n";
    // cout<<str;
    
    return str;
}

#if 1
/*****************************************************************/
// 判断是够质数 6倍附近判断 质数
bool IsPrime(int num) {
    if(num <= 1) {
        return false;
    }
    if(num == 2 || num ==3) {
        return true;
    }
    // 处理 不靠近6的数据
    if(num %6 != 1 && num %6 != 5) {
        return false;
    }
    for(int i=5;i<sqrt(num)+1;i += 6) {
        if(num %i == 0 || num %(i+2) == 0) {
            return false;
        }
    }
    return true;
}



// 计算质数表
const int MAX = 30000000;
const int MOD = 1000000007;

//  计算小于
void solve(vector<int> &count)
{
    int n = count.size();
    for(int i=2;i<= n;i++)
    {
        int tmp = 0;
        // 没被访问过 且是质数
        if(count[i] == 0 && IsPrime(i))
        {
            for(int j=2*i;j<=n; j += i)
            {
                if(count[j] == 0)
                {
                    count[j]  = i;
                }

            }
            count[i] = i;
        }
    }
}


// 计算从 x 到 n 的有多少个 x 的倍数
int solve(vector<int> &vec, int x);

int main(void)
{   
    int n=0;

    // 使用in.txt 重定向 到输入
    freopen("in.txt","r",stdin);
    cin>>n;

    vector<int> count(n+1,0); 

    solve(count);

    long long  res = 0;
    for(int i=2;i<=n;i++)
    {
        res = (res + count[i])%MOD;
    }

    cout<<CoutVec(count)<<endl;

    cout<<res<<endl;

    return 0;
}

#endif

#if 0

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

vector<int> prime;
void init() {
	prime.push_back(2);
	for (int i = 3;i <= 10000;i+=2) {
		bool flag = true;
		for (int j = 0;j < prime.size();j++) {
			if (i % prime[j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			prime.push_back(i);
		}
	}
}

int cal(int n, int idx) {
	if (n <= 1) {
		return 0;
	}
	int ret = n / prime[idx];
	for (int i = 0;i < idx;i++) {
		if (n < prime[i] * prime[i]) {
			break;
		}
		ret -= cal(n / prime[idx], i);
	}
	return ret;
}

int main() {
	init();
	int n = 4;

	int ret = 0;
	for (int i = 0;prime[i] * prime[i] <= n;i++) {
		ret += (cal(n, i) - 1) * prime[i];
	}
	printf("%d\n", ret);

    cout<<CoutVec(prime)<<endl;

	return 0;
}
#endif 