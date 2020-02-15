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



int main(void) {
        // 使用in.txt 重定向 到输入
    freopen("in.txt","r",stdin);

    int n=0,k=0;
    cin>>n>>k;
    vector<int> vec(n);

    for(int i=0;i<n;i++)    cin>>vec[i];

    // 可以使用一个数组来处理所有的技能值
    vector<int> table(62,0);    // 数据从高位存储低位值
    for(int i=0;i<n;i++) {
        int tmp = vec[i];
        // 将所有的数据投影到一个数组中
        for(int i=0;i<62;i++) {
            if(tmp & (1<<(61-i))) {
                table[i] ++;
            }
        }
    }

    cout<<CoutVec(table)<<endl;
    // 从数组首位开始 遇到赋值1 遇到偶数 减一
    // 标识遇到的第一个 天赋值 
    int flg_fir = 0;
    for(int i=0;i<62 && k >0;i++) {
        // 直到遇到第一个奇数位置
        if(table[i] != 0) {
            flg_fir = 1;
        }
        if(!flg_fir)    continue;

        // 遇到偶数 减一 处理 变成奇数
        if(table[i] == 0) {
            table[i]  = 1;
            --k;
        } else if(table[i] %2 == 0) {
            table[i] --;
            --k;
        } 
    }

    cout<<CoutVec(table)<<endl;
    // 比哪里数据, 从头开始 奇数值表示异或和  非零值表示 或和
    int res_xor=0,res_or = 0;
    for(int i=0;i<62;i++) {
        if(table[i] != 0) {
            res_or += (1<<(61-i));
        } else {
            continue;
        }
        
        // 奇数值 才进行 异或 否则相互抵销
        if(table[i] & 1) {
            res_xor += (1<<(62-i));
        }

    }
    cout<<res_xor <<"\t"<<res_or<<endl;

    // 输出结果
    cout<< res_or + res_xor <<endl;

        
    return 0;    
}
