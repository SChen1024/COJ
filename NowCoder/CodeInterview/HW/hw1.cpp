#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    std::string str;
    // std::getline(std::cin,str);
    
    str = "hello world";
    if(str.empty())
        return 0;
    
    // 正常模式  从后往前遍历得到空格之后
    char ch=str[0];
    int i=str.size()-1;
    // 一直遍历到 空格或者到了最开始的地方
    while(ch != ' ' &&i>=0)
    {
        ch = str[i--];
    }
    
    // 判断状态  到了最开始的地方
    
    int res=0;
    
    if(i<0)
    {
        res = str.size()-i-1;
    }
    
    cout<< (str.size()-i-1)<<endl;
    
    return (str.size()-i-1);
}
