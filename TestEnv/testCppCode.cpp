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
// 常用算法记录 避免每次手动写
// strtok  字符串分割函数
void fun(void)
{
    char s[] = "Golden Global      View,disk * desk";
    const char *d = " ,*";         
    char *p;
    p = strtok(s,d);         
    while(p)
    {
        printf("%s\n",p);
        p=strtok(NULL,d);
    }
}

void split(const std::string& s,
    std::vector<std::string>& sv,
                  const char* delim = " ") {
    sv.clear();                                 // 1.
    char* buffer = new char[s.size() + 1];      // 2.
    std::copy(s.begin(), s.end(), buffer);      // 3.
    char* p = std::strtok(buffer, delim);       // 4.
    do {
        sv.push_back(p);                        // 5.
    } while ((p = std::strtok(NULL, delim)));   // 6.
    return;
}

// 利用流分割字符串
void split(const std::string& s,
    std::vector<std::string>& sv,
                   const char delim = ' ') {
    sv.clear();
    std::istringstream iss(s);
    std::string temp;

    while (std::getline(iss, temp, delim)) {
        sv.emplace_back(std::move(temp));
    }

    return;
}


// 字符串分割 存放到数组中
vector<string> &split(const string &str, char delim,  bool skip_empty = true) 
{
    vector<string> elems;
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




/*****************************************************************/



int main(void)
{
    int n = 10;





    
    return 0;
}

