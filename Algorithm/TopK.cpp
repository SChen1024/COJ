/*****************************************************************/
// 包含必须的头文件

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;

// 定义本地
#define LOCAL_ 0

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


/*
    1. 无序数组第K大的数字
    2. 无序数组的中位数
    3. 两个数组的第K大的数字
*/

// 将数组 区间内数字 分区
int part (vector<int> &vec,int low, int high)
{
    int i=low-1,j=low;
    while(j<high)
    {
        if(vec[j] >= vec[high])
        {
            swap(vec[i+1],vec[j]);
            i++;
        }
        j++;
    }
    swap(vec[i+1],vec[high]);
    return i+1;
}

int find(vector<int> &vec,int low,int high, int K)
{
    if(low<high)
    {
        int q = part(vec,low,high);
        int len = 1 - low + 1;
        if(len == K)
            return q;
        else if(len<K)
        {
            return find(vec,q+1,high,K-len);
        }
        else
        {
            return find(vec,low,q-1,K);
        }

    }


    return 0;
}






/*********************************************************************/

#define MAX  20
int main(int argc, const char** argv) {

    vector<int> vec(MAX,0);

    // 生成随机数据
    for(int i=0;i<MAX;i++)
        vec[i] = (rand()%MAX);

    cout<<CoutVec(vec)<<endl;;

    vector<int> vec_bak = vec;
    
    int K = 5;
    int res = find(vec,0,vec.size()-1,K);

    sort(vec_bak.rbegin(),vec_bak.rend());

    cout<<CoutVec(vec)<<"-->"<<vec[K]<<endl;
    cout<<CoutVec(vec_bak);






    return 0;
}

















