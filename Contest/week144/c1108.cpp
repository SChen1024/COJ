#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        std::string str = "";

        for(int i=0;i<address.size();i++)
        {
            char ch = address[i];
            if('.' == ch)
                str+= "[.]";
            else
            {
                str += ch;
            }
            
        }


        return str;
    }
};


// 输出 vec 内部的值
void coutVec(const std::vector<int> &vec)
{
    if(vec.empty())
        cout<<"-1"<<endl;
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<endl;

}

int main(void)
{
    std::string address ="255.100.50.0";

    Solution s1;
    std::string str = s1.defangIPaddr(address);

    cout<<str<<endl;

    return 0;
}
