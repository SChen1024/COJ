#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        // 记录下来每次操作的 值 最后累加操作的值 变能够得到最后结果
        std::vector<int> vec(n+1,0);
        for(int i=0;i<bookings.size();i++)
        {
            vec[bookings[i][0]-1] += bookings[i][2];  //起始位置 加上值
            vec[bookings[i][1]] -= bookings[i][2]; //结束的后一位 减去相应的值
        }

        std::vector<int> res(n);
        int cur=0; // 计算当前操作的值

        for(int i=0;i<n;i++)
        {
            cur += vec[i];
            res[i] = cur;
        }


        return res;
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
    std::vector<std::vector<int>> bookings = {{1,2,10},{2,3,20},{2,5,25}};
    int n=5;

    
    Solution s1;
    std::vector<int> vec= s1.corpFlightBookings(bookings,n);

    coutVec(vec);

    return 0;
}
