/*
链接：https://ac.nowcoder.com/acm/contest/1113/A
来源：牛客网

Bessie and all the other cows have an RFID serial number tag in their ear so FJ can mechanically tally them. Many cows have a 'cowpal' whose serial number is equal to the sum of the divisors (that are not the number itself) of their own serial number. Some cows don't have a cowpal because no cow's serial number matches their divisor sum.
Some cows have a superpal. Cows are superpals when their serial numbers make each of them a pal of the other. Cows that are superpals of themselves are shunned; do not consider them!
Given a serial number S (6 <= S <= 18,000), find the first cow with serial number at least S who has a super pal.
By way of example, consider serial number 220 whose divisors are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55, and 110. Their sum is 284. Similarly, the divisors of 284 are 1, 2, 4, 71, and 142. Their sum is 220.
输入描述:
* Line 1: A single integer: S
输出描述:
* Line 1: A single line with two space-separated integers that are the serial number of the first superpal whose serial number is no smaller than S and the serial number of her pal.
示例1
输入
复制
206
输出
复制
220 284

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


/*****************************************************************/
// 计算 n 值的因子和值
int calc(int n) {
    int k = sqrt(n);
    int res = 1;
    for(int i=2;i<k;i++) {
        if(n%i == 0) {
            res  = res + i + (n/i);
        }
    }
    return res;
}

// 计算从 n 开始的第一个亲和数
// 计算因子和 之后将因子和计算是否相等本身
vector<int> solve(int n) {
    while(true) {
        int tmp1 = calc(n);         // 计算 因子和
        int tmp2 = calc(calc(n));   // 计算 因子和的因子和
        // cout<<"n:"<<n<<"\t"<<calc(n)<<"\t"<<calc(calc(n))<<endl;
        // 剔除非自身相等的值 并且满足亲和数的值
        if( (tmp1 != n) && (tmp2 == n)) {
            return {n, tmp1};
        }
        n ++;
    }
    return {};
}
void solveX(int n) {
    vector<int> res = solve(n);

    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
}

int main(void)
{   
    int n=0;

    // 使用in.txt 重定向 到输入
    freopen("in.txt","r",stdin);
    cin>>n;

    solveX(n);


    /*
    map<int,int> Map;

    for(int i=6;i<18000;i += 5) {
        vector<int> tmp = solve(i);     // 计算数对
        
        if(Map.count(tmp[0]))
            continue;
        
        Map[tmp[0]] = tmp[1];
        cout<<tmp[0]<<"----"<<tmp[1]<<endl;
    }
    */
    
    // cout<<CoutVec(res)<<endl;

    return 0;
}