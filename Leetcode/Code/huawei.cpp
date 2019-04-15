#include <iostream>
#include <vector>
using namespace std;
// 比较两个字符串 按照ascii 排序 还是按照字母顺序排序? ?
// a > B ?? 
// 如果前一个大 返回true 否则返回 false
bool str_compare(std::string s1,std::string s2)
{
    // 由于提前做了比较, 所以前后字符串长度一致
    
    for(int i=0;i<s1.size();i++)
    {
        // 如果以为不满足 立马结束比较
        if(s1[i]<s2[i])
            return false;
    }
    
    return true;
    
}



int main() 
{
    
    int n=0;
    string str="";
    vector<string> vecs;
    
    cin>>n;
    
    // 拆分数据段  进行 置入 向量中  可以分为多个段
    for(int i=0;i<n;i++)
    {
        string tmps="";
        cin>>tmps;
        
        if(tmps.size()<9)
            vecs.push_back(tmps);
        else
        {
            for(int j=0;j<tmps.size()/8;j++)
            {
                vecs.push_back(tmps.substr(8*j,8));
            }
        }
            
        
    }
    cout<<n<<":"<<vecs.size()<<endl;
    
    cout<<str_compare("a","A")<<endl;
    
    cout<<str_compare("0","a")<<endl;
    
    // 根据每个段落进行首字母排序处理
    for(int i=0;i<vecs.size();i++)
    {
        if(vecs[i].size()>8)
        {
            cerr<<"排序错误"<<endl;
        }
        else if(vecs[i].size()<8)
        {
            for(int j=vecs[i].size();j<=8;j++)
                vecs[i] += "0";
        }
        
        
        
    }
    
    for(int i=0;i<vecs.size();i++)
    {
        for(int j=i+1;j<vecs.size();j++)
        {
            if(! str_compare(vecs[i],vecs[j]))
            {
                string tmp = vecs[i];
                vecs[i] = vecs[j];
                vecs[j] = tmp;
            }
        }
    }
    
    
    for(int i=0;i<vecs.size();i++)
    {
        cout<<vecs[i]<<" ";
    }

    return 0;
    
}