// 腾讯第三题
//  暴力

#include <iostream> 
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

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


struct personData
{
    int a;
    int b;
    // personData(int a_,int b_):a(a_),b(b_){}
    
    // 用于比较大小
    bool operator< (const personData &right) const 
    {
        return (a-b) > (right.a-right.b);
    }
};

#define LOCAL_ 1
int main(void)
{
    int n=0;
    // 处理输入数据
    cin>>n;
    vector<personData> Person(n);

    for(int i=0;i<n;i++)
    {
        cin>>Person[i].a>>Person[i].b;
    }

    // 按照 a-b 进行排序  得到的结果累加
    // 因为结果按照 a*i+b(n-i) = b*n + (a-b)i  按照a-b 排序即可
    sort(Person.begin(),Person.end());

    long long res = 0;

    for(int i=0;i<n;i++)
    {
        res += (long long)Person[i].a*i + (long long)Person[i].b*(n-i-1);
    }
    
    cout<<res<<endl;

    return 0;
}