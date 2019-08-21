#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

typedef std::string sstr;
typedef std::vector<int> vint;
typedef std::vector<std::string> vstr;

using namespace std;

int getInt1(int num);
int getInt1(int num)
{
    int cnt = 0;
    
    // 快速计算 1的个数
    while(num)
    {
        num &= (num-1);
        cnt ++;
    }
    
    return cnt;
}

int main(void)
{
    int num=0;
    cin>>num;
    
    cout<< getInt1(num) <<endl;

    return 0;
}
