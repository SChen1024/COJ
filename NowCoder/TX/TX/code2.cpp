// 腾讯第二题 
// 区间 最小值和区间和最大值的考虑
// 单调栈问题


#include <iostream> 
#include <vector>
#include <queue>
#include <stack>

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

// 获取数组子区间最小值与和值乘积的最大值

// 记录递增区间的元素
struct Node
{
    int val;
    int start;
    int end;
    // Node(int v,int s,int e) :val(v),start(s),end(e) {};
};


#define LOCAL_ 1
int main(void)
{
    int n=0;
    vector<int> test = {7,2,4,6,5};
    
    // 处理输入数据
    #if LOCAL_ 
        n = 5;
    #else
        cin>>n;
    #endif
    

    // 输入数据 更新值 
    vector<Node> Input(n+1);

    // 递增区间 计算累加和
    vector<long long> incSum(n+1,0);
    // incSum[-1] = 0;

    for(int i=0;i<n;i++)
    {
        #if LOCAL_
        Input[i].val = test[i];
        #else 
        cin>>Input[i].val;
        #endif 

        // 首个输入直接复制 后面的直接累加 // 后面处理累加数组
        if(i==0)
            incSum[i] = Input[i].val;
        else
        {
            incSum[i] = incSum[i-1]+Input[i].val;
        }

        Input[i].start = i;
        Input[i].end = i;
    }

    // 利用单调栈 得到每个元素的 峰区间  // 谷区间
    // 得到 左边界
    stack<int> St;
    int i=0;
    while(i<Input.size())
    {
        if(St.empty() || Input[i].val >Input[St.top()].val)
        {
            St.push(i++);
        }
        else
        {
            // 如果出现了非递增区间  更新袁元素值
            Input[i].start = Input[St.top()].start;
            St.pop();
        }
        
    }


    // 获取 右边界
    while(!St.empty())
        St.pop();
    
    i = n-1;
    while(i>=0)
    {
        if(St.empty() || Input[i].val >Input[St.top()].val)
        {
            St.push(i--);
        }
        else
        {
            // 如果出现了非递增区间  更新袁元素值
            Input[i].end = Input[St.top()].end;
            St.pop();
        }
    }

    // 找到每个区间的最大值

    long long res = 0;

    int idx_start=0,idx_end= 0;
    for(int i=0;i<n;i++)
    {
        // 使用累加区间 获取 和值 与 最小值的
        long long cur = Input[i].val*(incSum[Input[i].end] - incSum[Input[i].start-1]);
        
        // 更新最大值和区间
        if(cur > res)
        {
            res = cur;
            idx_start = Input[i].start;
            idx_end = Input[i].end;
        }
    }

    cout<<res<<endl;

    return 0;
}