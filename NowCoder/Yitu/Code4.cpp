// 简历邻接表 查询得到相应的值

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

// 判断依次进行需要删除几个数字
int judge(string &str)
{
    //
    int cnt = 0;

    if(str.size()<2)    return -1;

    for(int i=1;i<str.size();i++)
    {
        if(str[i] != str[i-1])
            cnt++;
    }
    return cnt;
}


int main(void)
{
    int T=0;
    cin>>T;

    // 输入测试数据
    for(int t=0;t<T;t++)
    {   
        int N=0;
        string str;
        cin>>N;
        cin>>str;

        int tmp = judge(str);

        cout<<"Case #"<<t<<":"<<endl;
        for(int i=0;i<N;i++)
        {
            cout<<max(tmp-i,0)<<" ";
        }
        cout<<endl;





    }






    return 0;
}

