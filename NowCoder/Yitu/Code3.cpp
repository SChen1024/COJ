// 简历邻接表 查询得到相应的值

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int judge(vector<vector<int>> & vec,int p,int q)
{



    return 3;
}


int main(void)
{
    int N=0,M=0,K=0;
    cin>>N>>M>>K;
    // 简历表 存储关系
    vector<vector<int>> vec(N,vector<int>(N,-1));

    int a=0,b=0,c=0;
    for(int i=0;i<M;i++)
    {
        cin>>a>>b>>c;
        vec[a][b] = c;
        vec[b][a] = 
    }

    // 输入后 判定输出
    int p=0,q=0;
    for(int i=0;i<K;i++)
    {
        cin>>p>>q;
        cout<<judge(vec,p,q)<<endl;
    }
    



    return 0;
}

