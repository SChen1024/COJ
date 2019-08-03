#include <iostream>
#include <string>
#include <vector>

typedef std::string sstr;
typedef std::vector<int> vint;
typedef std::vector<std::string> vstr;

using namespace std;
// 输出 vec
void coutVec(std::vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
        std::cout<<vec[i]<<std::endl;    
}
void coutVec(std::vector<std::string> &vec)
{
    for(int i=0;i<vec.size();i++)
        std::cout<<vec[i]<<std::endl;    
}

// 将字符转换成数字
int hex2num(char ch) 
{
    return ((ch>='A')?ch-'A'+10:ch-'0');
}

char num2str(int num)
{
    return(num+'0');
}

// 将字符串格式化为8位格式 样式
std::string hex2dec(std::string &str)
{
    // 获取后面的值
    std::string hex = str.substr(2,str.size()-2);
    int hex_cnt=0;
    int dec = 0;
    // 从前往后移动
    for(auto i = 0; i<hex.size(); i++)
    {
        int n = hex2num(hex[i]);
        dec = (dec << 4) + n;
    }


    string decStr="";
    
    // 从前往后获取各位数字
    vint v;
    do
    {
        v.push_back(dec%10);
        dec /= 10;
    } while(dec);

    // cout << decStr<< endl;

    for(int i=v.size()-1;i>=0;i--)
    {    
        decStr += num2str(v[i]);

        // cout<<i<<"/"<<v.size()<<":"<< v[i]<<":"<<num2str(v[i])<<":"<<decStr<<endl;
    }

    // cout << decStr<< endl;

    return decStr;

}


int main(void)
{
    int num=0;

    #if TEST
        vstr vec_in{"abc","123456789"};
    #else
        vstr vec_in;
        
        //将字符串 加入 列表中
        string str;

        str = "0xAF";
        
        // while(cin>>str)
        // cin>>str;
        vec_in.push_back(str);
    #endif

    
    vstr vec_res;

    for(auto i=0;i<vec_in.size();i++)
    {
        vec_res.push_back( hex2dec(vec_in[i]));
    }
    
    // 输出
    // coutVec(vec);
    for(auto i=0;i<vec_res.size();i++)
        std::cout<<vec_res[i]<<std::endl;    

    return 0;
}
