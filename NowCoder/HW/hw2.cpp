#include <iostream>
#include <string>

using namespace std;

// 判断是否相等
bool isEqual(char &ch1,char &ch2)
{
    if(ch1 == ch2)
      return true;
    if(ch1 == (ch2-32))
        return true;
    if(ch1 == (ch2+32))
        return true;
    
    
    return false;
    
    
}


int main(void)
{
    // 获取字符串
    std::string str;
    // std::getline(std::cin,str);

    str = "nhrwlbcc8m7c5hih9mhalw98k0322wf2jjm47kk3ntm9snfrflzzundn7d608usy049asxalzjk7izj6amcqhr8uubc04g52mcjboj2fmge2l6iarizfu4yve5o4i3srf5zgqbg82ckcotdeqp760mc9gzei5dzk5gj9x9yj05o3hle0ii64krkkp5i7blh7nbu3gu5vgi2scyn4yqx3z4vcjbyzhnqkh887izotjkg2l0mit0k14vyn39";

    
    // 获取字符
    // char chA = cin.get();
    
    char chA = 't';
    
    if(str.empty())
        cout<< 0<<endl;
    // 计数
    int cnt=0;
    for(int i=0;i<str.size();i++)
    {
        if(isEqual(str[i],chA))
        {
            cout<<str[i]<<":"<<chA<<endl;
            cnt++;
        }
            
    }
    
    cout<<cnt<<endl;
    
    return 0;
}
