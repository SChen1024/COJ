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
std::string CoutVec(T& vec,int flg =0)
{
    std::string str="";
    for(int i=0;i<vec.size();i++)
    {
        str += to_string(vec[i]) + ", ";
    }

    // 默认不输出 换行
    if(flg)
        str += "\n";
    // cout<<str;
    
    return str;
}

// 二维数组输出
template <typename T>
std::string CoutVec2(T& vec,int flg =1)
{
    std::string str="";
    for(int i=0;i<vec.size();i++)
    {
        str += CoutVec(vec[i],flg);
    }
    return str;
}


/*****************************************************************/



 // 获取杨辉三角
class Solution {
public:
    int generate(int row,int col)
    {
        // cout<<row<<"--"<<col<<endl;
        if(row == col || col == 1 || row == 1)
            return 1;
        else
            return (generate(row-1,col-1) +generate(row-1,col));
    }

    vector<vector<int>> generate(int numRows) {      
        
        vector<vector<int>> res;

        if(numRows<1)
            return res;
        // 加入第一行
        res.push_back({1});

        // 后续每一行直接计算
        for(int i=1;i<numRows;i++)
        {
            // 前后加入 1 然后中间值用上一行的计算值
            vector<int> vec;
            vec.push_back(1);
            for(int j=1;j<i;j++)
                vec.push_back(res[i-1][j]+res[i-1][j-1]);
            vec.push_back(1);
            // cout<<CoutVec(vec)<<endl;

            res.push_back(vec);
        }
        return res;
    }
};

class Solution2 {
    public:
    vector<int> getRow(int rowIndex) {
        
        // 全部初始化为1 
        vector<int> res(rowIndex+1,0);
        res[0] = 1;

        if(rowIndex<=0)
            return res;

        // 由于第i 行一共和i+1 个数字  循环递进得到第i行数字
        for(int i=1;i<=rowIndex;i++)
        {
            // 对于每一行 的 更新当前值加上前一个的值  1210  变成  1331 
            for(int j=i; j>=1;j-- )
            {
                res[j] += res[j-1];
            }
        }

        return res;


    }
};


int main(void)
{

    #if 0
    Solution s1;

    vector<vector<int>> res;
    res = s1.generate(6);
    #endif

    Solution2 s2;
    vector<int> res = s2.getRow(6);

    // Vint vv ={1,2,2,3,3,3,4,45,5};
    // cout<<CoutVec(vv);
    cout<<CoutVec(res);

    
    return 0;
}

