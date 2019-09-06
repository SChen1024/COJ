// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 输出 一列结果 值
void coutVec(const vector<int> &vec)
{
    for(int i=0;i<vec.size();++i)
        cout<<vec[i];
    cout<<endl;
}

#define LOCAL 1

int main() {

    // 输入 n 计算 1-n 的全排列
    // 根据 字符顺序 得到字符 排序的顺序值
    // 倒数的排序值 排列结果

    // 使用 vector<vector<int>> 存储 全排列结果 最好按照字典序生成 字符
    // 或者 生成 字典序排列之后  打印既可

    int n=0;
    
    #if LOCAL
        n = 3;
    #else
        cin>>n;
    #endif

    if(n<=1)
    {
        cout<<n<<endl;
        return 0;
    }
    // 读取输入的第 i个排列
    vector<int> Q_permutation;
    int tmp=0;
    #if LOCAL
        Q_permutation = {1,2,3};
    #else
        while(cin>>tmp) Q_permutation.push_back(tmp);
    #endif

    // 验证
    if(Q_permutation.empty())return 0;

    // 存储 输入 n的值 // 存储  1 - n  的初始排列
    vector<int> input(n);
    for(int i=0;i<n;i++)
        input[i] = i+1;

    vector<vector<int>> res;

    // 记录给出 排列的位置 和位置值
    int Q_local= -1,cnt = 0;;
    // 使用 STL 的库 来生成 全排列 数组结果
    // 记录 排列所在的位置 
    do
    {
        res.push_back(input);
        cnt ++; // 计数结果 值

// 本地调试
#if LOCAL 
    cout<<"P:"<<cnt;
    coutVec(input);
#endif
        if(input == Q_permutation)
            Q_local = cnt;
    }
    while(next_permutation(input.begin( ), input.end( )));


    // 比对 找到
    
    #if LOCAL
        cout<<"Q:"<<cnt;
        coutVec(Q_permutation);
        cout<<"res:"<<cnt;
        coutVec(res[cnt]);
        cout<<"out:"<<res.size()-1-cnt;
        coutVec(res[res.size()-1-cnt]);
    #endif
    
    // coutVec(res[res.size()-1-cnt]);




    
    
}