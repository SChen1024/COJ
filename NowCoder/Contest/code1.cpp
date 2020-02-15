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
        str = to_string(vec[i]), +", ";
    }

    // 默认不输出 换行
    if(flg)
        str += "\n";
    // cout<<str;
    
    return str;
}

// 二维数组输出
template <typename T>
std::string CoutVec2(const T& vec,int flg =0)
{
    std::string str="";
    for(int i=0;i<vec.size();i++)
    {
        str += CoutVec(vec[i],flg);
    }
    return str;
}

/*****************************************************************/

#define PI 3.1415926535897929894


// 根据精度x 输出小数点后面的数值
string coutPrecision(double y,int x)
{
    string str = to_string(y);
    int pos = str.find(".");

    string sub_ = str.substr(0,pos);

    if(x != 0)
        sub_ += str.substr(pos,x+1);
        
    return sub_;
}


int main(void)
{

    int N=0;

    #if LOCAL_
        N = 1;
    #else
        cin>>N;
    #endif

    for(int i=0;i<N;i++)
    {
        int n=0,x=0;
        #if LOCAL_
            // n = 1,x=3;
            n = 7,x=6;
            // n = 9,x=1;
        #else
            cin>>n>>x;  
        #endif

        double y = pow(n,PI);

        cout<<coutPrecision(y,x)<<endl;

    }


    return 0;
}
