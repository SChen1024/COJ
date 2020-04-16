#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

// 常用输出函数 
// 一维 数组输出
template <typename T>
std::string CoutVec(const T& vec,int flg =0)
{
    std::string str="";
    int n = vec.size();
    for(auto i=0;i<n;i++)
    {
        str += to_string(vec[i])  +", ";
    }

    // 默认不输出 换行
    if(flg)
        str += "\n";
    // cout<<str;
    
    return str;
}

/********************************************/

struct File {
    int a;
    int b;
    bool flg;    // 标识 a>b

    File(int a0=0, int b0 = 0):a(a0),b(b0) {}
};

// 比较函数
bool cmp(File & l, File &r)
{
    return max(l.a,l.b) <= max(r.a,r.b);
}

int main(void) {
        // 使用in.txt 重定向 到输入
    freopen("in.txt","r",stdin);

    int n=0,k=0;
    cin>>n>>k;


    vector<File> vec(n);
    for(int i=0;i<n;i++){   
        cin>>vec[i].a>>vec[i].b;
        vec[i].flg  = (vec[i].a > vec[i].b);    // 标识 a>b
    }

    // 排序
    sort(vec.begin(),vec.end(),cmp);

    /*
    // 小白二号 
        首先，按a和b哪个大排序
        因为手动删除不能连续，所以这里也有次数限制，如果总次数是奇数，手动删除次数限制是n/2+1，偶数，也是n/2  次数限制取个最小值
        然后按a和b哪个大排序，两边分，如果分完，没超限制，返回
        超过手动删除的限制的话，手动删除的那边按a-b小的挪到自动删除那一堆
    */

    // 手动删除有次数限制 自动没有限制
    int res = 0;
    int d_flg = n+1;     // 标记 上一次手动删除的位置信息
    for(int i=n-1;i>=0 ;i--) {
        // 判断能够进行手动删除
        // if(!vec[i].flg) {
        
        // a 大于b 且 有操作次数 且 上次删除在可选范围内
        if(vec[i].flg && k>0 && (d_flg - i) != 1) {    
            res += vec[i].a;
            d_flg = i ;
            --k;
        } else {
            res += vec[i].b;
        }
        
            
    }

    cout<<res<<endl;

        
    return 0;    
}
