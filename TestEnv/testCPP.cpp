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

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string testRef(string src_str)
{
    for(int i=0;i<src_str.size();i++)
    {
        // this += src_str[i];
    }

    return src_str;

}

int main(void)
{
    int n = 10;


    string str = to_string(n);

    while(str.size() < 5)
    {
        str = "0" + str;
        cout<<str<<":"<<str.size()<<endl;
    }

    str += "\n\n 123";

    cout<<str<<endl;

    


    
    return 0;
}

