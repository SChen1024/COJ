/*****************************************************************/
#if 1
// 包含必须的头文件

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
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

 //打印任意变量 // 如果本地 打印 否则不打印
template <typename T>
void CoutVar(const T & var)
{
    #if LOCAL_
        cout<<var<<endl;
    #endif
}

#endif 
/*****************************************************************/

// 计算两个矩阵的处理 // 存储数组的值
int fun(vector<int> & A,const vector<int> &B )
{
    if(A[1] != B[0]) return -1;
    int res = A[0]*A[1]*B[1];

    // 将结果存储在A 上 便于进行连续操作
    A[1] = B[1];
    return res;
}

// 主函数执行入口
int main(void)
{
    int N = 0;
    cin>>N;

    // 初始化输入
    vector<vector<int>> input(N,vector<int>(2,0));

    for(int i=0;i<N;i++)
    {
        cin>>input[i][0]>>input[i][1];
    }

    string str = "";
    cin>>str;

    // 建立字母和尺寸的对应关系  // 按照字母下标对应
    // map<char, vector<int>> m;


    // 存储数据临时值
    stack<vector<int>> st;

    // 初始化 输出结果
    int ans = 0;
    int level = 0;  // 括号等级

    //  对于str 进行遍历, 每次结果
    for(int i=0;i<str.size();i++)
    {
        char tmp = str[i];
        switch(tmp)
        {
            // 遇到左括号开始压栈 处理数据
            case '(' :
            {
                level ++;
                continue;
            } break;
            case ')' : 
            {   
                // 表示之前进入了一层
                // TODO: 后续完成

                level --;
                    
            } break;

            default:
            {
                // 如果为空  首个字母 压入数据
                if(st.empty)
                    st.push(input[tmp-'A']);
                else
                {
                    // 每次弹出首个数据 计算之后重新压入
                    vector<int> tmpM = st.top();
                    st.pop();   // 弹出首个
                    ans += fun(tmpM,input[tmp-'A']);    // 统计计算次数
                    st.push(tmpM);      // 将结果重新压入栈中连续计算
                }
            }
            break;
        }
    }

    // 最终占用一定只有一个袁术

    cout<<ans<<endl;




    return 0;
}