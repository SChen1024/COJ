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

// 二维数组输出
template <typename T>
std::string CoutVec2(const T& vec,int flg =1)
{
    std::string str="";
    for(int i=0;i<vec.size();i++)
    {
        str += CoutVec(vec[i],flg);
    }
    return str;
}


/*****************************************************************/

char * find_lonest_num_str(char* input)
{
    int max_cnt,cnt;
    char* max_num_char;

    // 初始化
    max_cnt = 0;
    cnt = 0;
    max_num_char = input;
    while(input)
    {
        // 如果数字 累加 否则 终止
        if(*input >='0' && *input <= '9')
        {
            cnt ++;
        }
        else
        {
            if(cnt > max_cnt)
            {
                max_cnt = cnt;
                max_num_char = input;
            }
            cnt = 0;
        }

        input ++;
    }
    return max_num_char;
}

class C
{
    private:
        int b;
        int *p;
    public:
        virtual void funcb()
        {
            cout<<"b:funcb"<<endl;
        }
        void funca()
        {
            cout<<"a"<<endl;
        }

        C()
        {
            cout<<"C"<<endl;
        }
};

class Solution2
{

public:
    long long  jumpFloor(long long n)
    {
        if(n <= 2)
        {
            return n;
        }
        long long one = 1;
        long long two = 2;
        long long res = 0;

        for(long long i = 3; i <= n; i++)
        {
            res = one + two;

            one = two;
            two = res;
        }

        return res;
    }

};

// 计算阶乘
int fun(int n)
{
    const int MOD = 1000003;
    if(n>MOD)
        return 0;
    
    int res= 1;
    for(int i=1;i<=n;i++)
    {
        res  = (res*i)%MOD;
    }

    return res;
}

// 计算 三个数的三次方和为42 

int main(void)
{
    C cc;
    cout<<sizeof(cc)<<endl;

    // long long N = 10000000L;

    // Solution2 s2;
    // long long res = s2.jumpFloor(N);
    // cout<<res<<endl;

    /*
    string str = to_string(n);

    while(str.size() < 5)
    {
        str = "0" + str;
        cout<<str<<":"<<str.size()<<endl;
    }

    str += "\n\n 123";

    cout<<str<<endl;

    cout<<sizeof(void*)<<endl;
    cout<<sizeof(void)<<endl;
    
    // char test[] = "abc360360xyz123you";
   // char * chh = find_lonest_num_str(test);

    cout<<string(chh)<<endl;
    */
    
    return 0;
}

