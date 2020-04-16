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
    

int main(void) {
    int n=0,t=0;

    // 使用in.txt 重定向 到输入
    freopen("in.txt","r",stdin);
    cin>>n>>t;
    
    // 输入
    vector<Boy> vec(n);    //初始化状态
    
    for(int i=0;i<n;i++) {
        cin >> vec[i].local >> vec[i].dir;
        // cout<<"i:"<<i<<"\t"<<vec[i].local<<"\t"<<vec[i].dir<<endl;

    }
    
    // 根据位置排序
    // sort(vec.begin(),vec.end(),cmp);

    // 在时间有限的情况下 所有左向的能够转移的时间的都能抓到, 转向不浪费时间 // 相当于进行了转移
    // 所以计算最难能够达到 最远距离是2个 时间长度
    int  res = 0;
    for(int i=0;i<n;i++) {
        if(vec[i].dir==0 &&  vec[i].local < (2*t) ) {
            res ++;
        }
    }
    
    cout << res << endl;    // 输出结果
        
    return 0;    
}
