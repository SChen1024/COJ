// 腾讯第一题, 加强版 约瑟夫环
// 70 %


#include <iostream> 
#include <vector>
#include <queue>

using namespace std;

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



#define LOCAL_ 1
int main(void)
{
    int n=0,m=0,k=0;
    vector<int> input; // (k,0);  // 题目描述 n个数字 应该是 K轮游戏的值 补充人数

    #if LOCAL_ 
        n = 4,m=3,k=5;
        input = {2,1,3,1,1};
    #else
        cin>>n>>m>>k;
        for(int i=0;i<k;i++)
        {
            int  tmp = 0;
            cin>>tmp;
            input.push_back(tmp);

        }

        # if 0
        for(int i=0;i<input.size();i++)
            cout<<input[i]<<endl;
        #endif
    #endif 
    
    // 使用Vector 作为数组处理数据

    vector<int> posIndex(n,0);  // 初始化 n个位置 0 表示出局,  数字表示当前位置所在序号
    for(int i=0;i<n;i++)
        posIndex[i] = i+1;

    vector<int> res;    // 记录出局编号

    // 循环进行K轮
    int cur = 0;    // 记录当前执行值
    int inx_Cnt = n+1;    // 编号值 // 最开始 n+1 号
    for(int i=0;i<k;i++)
    {
        int n = posIndex.size();
        cur = (cur+m-1)%n;  // 计算出来数完之后的位置

        // res.push_back(posIndex[cur]);
        cout<<posIndex[cur]<<endl;
        // 填入新的值
        for(int j=0;j<input[i];j++)
            posIndex.insert(posIndex.begin()+cur+1+j, inx_Cnt ++);
        
        // 删除旧的值
        posIndex.erase(posIndex.begin()+cur);

        #if LOCAL_
        cout<<CoutVec(vector<int>{i,input[i],n,cur,inx_Cnt})<<"--"<<CoutVec(posIndex)<<endl;
        #endif
    }

    #if LOCAL_
    // 输出编号值
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    #endif

    return 0;
}