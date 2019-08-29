/*
题目描述
请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，不合法的地址和掩码单独归类。

所有的IP地址划分为 A,B,C,D,E五类

A类地址1.0.0.0~126.255.255.255;

B类地址128.0.0.0~191.255.255.255;

C类地址192.0.0.0~223.255.255.255;

D类地址224.0.0.0~239.255.255.255；

E类地址240.0.0.0~255.255.255.255


私网IP范围是：

10.0.0.0～10.255.255.255

172.16.0.0～172.31.255.255

192.168.0.0～192.168.255.255


子网掩码为二进制下前面是连续的1，然后全是0。（例如：255.255.255.32就是一个非法的掩码）

输入描述:
多行字符串。每行一个IP地址和掩码，用~隔开。

输出描述:
统计A、B、C、D、E、错误IP地址或错误掩码、私有IP的个数，之间以空格隔开。

示例1
输入
复制
10.70.44.68~255.254.255.0
1.0.0.1~255.0.0.0
192.168.0.2~255.255.255.0
19..0.~255.255.255.0
输出
复制
1 0 1 0 0 2 1
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
vector<string> &split(const string &str, char delim, vector<string> &elems, bool skip_empty = true) {
    istringstream iss(str);
    for (string item; getline(iss, item, delim); )
        if (skip_empty && item.empty()) continue;
        else elems.push_back(item);
    return elems;
}

// 将 字符串转换数组, 如果出现不是数字的字符 返回 -1 
int str2int(string &str)
{
    int res = 0;
    for(int i=1;i<str.size();i++)
    {
        char tmp = str[i];
        if(tmp<'0' || tmp >'9')
            return -1;
        res = res*10 + tmp-'0';
    }
    return res;
}


// 判断掩码有效性
set<int> Set={128,192,224,240,248,252,254};
bool vaild(vector<int> &mask)
{
    // 设置一个flg 标识前面的是否存在 全0 
    bool zero = false;
    for(int i=0;i<mask.size();)
    {
        if(zero = false)
        {
            // 如果全0 下一轮
            if(mask[i] != 255)
            {
                if(Set.find(mask[i]) == Set.end() )
                    return false;
            }

        }
        else
        {
            // 出现0 之后 后面的必须全0
            if(mask[i] != 0)
                return false;
        }
    }
    return true;
}

vector<int> VEC=  {128,192,224,240};
int getIndex(int n)
{
    if(n==0) return -1;
    int i=0;
    for(i=0;i<VEC.size();i++)
    {
        if(n>VEC[i])
            continue;
        return i;
    }
    return i;
}


int main(void)
{
    // 存储结果
    vector<int> res(7,0);

    string input = "";

    while(cin>>input)
    {   
        // 存储前后两段
        vector<string> vec;
        split(input,'~',vec);

        // 存放字符和ip地址
        vector<vector<string>> table(2,vector<string>());
        vector<vector<int>> ip(2,vector<int>(4,0));

        split(vec[0],'.',table[0]);
        split(vec[1],'.',table[1]);

        // cout<<vec[0]<<":"<<vec[1]<<endl;
        // cout<<CoutVec(table[0])<<endl;
        // cout<<CoutVec(table[1])<<endl;

        // 转换成数字
        for(int i=0;i<4;i++)
        {
            ip[0][i] = stoi(table[0][i]);
            ip[1][i] = stoi(table[1][i]);
        }

        if(!vaild(ip[1]))
        {
            res[6] ++;
            continue;
        }

        int ans = getIndex(ip[0][0]);

        if(ans == -1) 
        {
            res[6]++;
            continue;
        }
        
        // 根据返回 index  执行不同 区域自增
        res[ans] ++;
        

            




    }




    return 0;
}