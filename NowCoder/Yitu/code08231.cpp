/*****************************************************************/
// 包含必须的头文件

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


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



// 定义本地
#define LOCAL_ 1
/*****************************************************************/


// 数值表: 1,5,10,550,100
// vector<string> tabel ={"I","V","X","L","C"};
// 存储能够匹配到到的值  IV 标识的值 为 IV -I 同理
map<string,int> table= {
    {"I",1},
    {"IV",3},
    {"V",5},
    {"IX",8},
    {"X",10},
    {"XL",30},
    {"L",10},
    {"XC",80},
    {"C",100}
};

// 罗马数字转换成 十进制数字
int Roma2Dec(string &str)
{
    // 对于正向的排列, V 后面最多三个I ; L 后面最多三个X, 
    // 对于逆向排列, V前面最多一个I; X前面最多一个I; L前面最多一个X, C前面最多一个X
    // 对于同级排列, I最多三个, V最多一个, X 最多三个, 

    int res = table[str.substr(0,1)];   // 截取第一个字符做判断
    for(int i=1;i<str.size();i++)
    {
        // 截取当前字符 或者前缀一个字母的字符 
        string tmp_1 = str.substr(i,1);
        string tmp_2 = str.substr(i-1,2);

        // 如果存在两字母组合, 加上 否则进行一字母组合
        if(table[tmp_2])
            res+= table[tmp_2];
        else
        {
            res += table[tmp_1];
        }
        #if LOCAL_
        cout<<tmp_2<<":"<<tmp_1<<":"<<table[tmp_1]<<endl;
        #endif
    }
    return res;
}

// 数字转换表
const vector<vector<string>> table2 = {
    {"","I","II","III","IV","V","VI","VII","VIII","IX"},
    {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"}
};
string Int2Roma(int num)
{
    return table2[1][num/10] + table2[0][num%10];
}

int main(void)
{

    string input = "";

#if LOCAL_
    vector<string> test ={"IXIII","VI","III"};
    input = test[0];
#else
    cin>>input;
#endif

    // 对于输入字符串 获取真实值, 
    // 计算字符排列能够得到的最小值 
    map<string,int> m;

    // 排序生成全排列, 得到最小值
    // sort(input.begin(),input.end());
    int  min_ = INT_MAX;
    string ans = "";


    int tmp = Roma2Dec(input);

    string back_input = input;

    sort(input.begin(),input.end());

    int flg  = 0;
    // 暴力 如果一致  找到最小的值即可
    for(int i=1;i<tmp;i++)
    {
        string tt = Int2Roma(i);
        ans = tt;

        #if LOCAL_
            cout<<i<<":"<<tt<<endl;
        #endif 

        sort(tt.begin(),tt.end());

        #if LOCAL_
            // cout<<input<<":"<<tt<<endl;
        #endif 

        // 如果字符组合一致 则可以交换排列得到
        if(input == tt)
        {
            flg = 1;
            break;
        }
    }

    // 判断 是否

    if(flg)
        cout<<ans<<endl;
    else
    {
        cout<<back_input<<endl;
    }
    









    return 0;
}