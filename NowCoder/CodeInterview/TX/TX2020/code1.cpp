#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <stack>
using namespace std;

// 1. 字符串 解压缩
int  main(void)
{
    std::string input;
    // cin>>input;
    input = "HG[3|B[2|CA]]F";

    if(input.empty()) return 1;

    // 1. 遇到左括号进行到 左括号开始读取数字, 遇到| 开始压栈, 遇到右括号进行出栈

    int index=0;

    stack<char> st;

    // 记录每层字符的 各个位置, 包括  [ 位置 | 位置] 位置
    vector<vector<int>> cnt(10,vector<int>(3,-1)); // 记录 数字起始位置 和该层的倍数
    int level = 0;

    // 初始字符串
    string res="";



    string tmp_str = "";
    int start_=0;

    cnt[0] = {0,0,0};
    cnt[0][2] = input.size()-1;
    level = 1;
    // 依次获取字符
    while(index<input.size())
    {

        char tmp = input[index];
        switch (tmp)
        {
            // 记录层次 起点
            case '[': 
            {
                cnt[++level][0] = index;

            } break;

            case '|':
            {
                // 记录该层次数
                // start_ = cnt[level][0] +1;
                // string num_str = input.substr(start_,index-start_);
                cnt[level][1] = index; // - cnt[level][0]; // 记录数字字符串的长度

                // start_ ++;  // 移动到字符的开始
                // level ++;    // 层次加1 
            } break;

            case ']':
            {
                cnt[level][2] = index; //记录后括号位置
                // 计算倍数
                string num_str = input.substr(cnt[level][0]+1,cnt[level][1]-cnt[level][0]-1);

                int k = stoi(num_str);

                if(cnt[level+1][0] != -1)
                {
                    tmp_str =res;
                }
                else
                {
                    tmp_str = input.substr(cnt[level][1]+1,cnt[level][2]-cnt[level][1]-1);
                }
                
                res = "";

                // 计算中间字符串 // 后加 指定次数
                for(int i=0;i<k;i++)
                    res += tmp_str;
                
                // 获取本层 前缀字符串 // 前加
                res = input.substr(cnt[level-1][1]+1,cnt[level][0]-cnt[level-1][1]-1) 
                        + res ;

                // 获取后缀
                if(cnt[level+1][2] != -1)
                {
                    res =res+ input.substr(cnt[level+1][2],cnt[level][2]-cnt[level+1][2]-1);
                }
                        
                
                cout<<cnt[level+1][2]<<":"<<cnt[level][2]<<":"<<tmp_str<<":"<<res<<endl;



                level --;



            } break;

            // 开始处理字符
            default: 
            {   
                // tmp_str
            }
        }

        res += input.substr(cnt[1][2]+1,input.size()-cnt[1][2]-1) ;
        // cout<<tmp_str<<endl;

        index ++;

    }







    return 0;
}