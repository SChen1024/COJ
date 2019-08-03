#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
               
        std::vector<int> res(num_people,0); // 初始化 全0 
        
        // 初始循环计数和结果值
        int i=0,loop_cnt=0;
        // 循环给每个人 糖果
        while(candies>0)
        {
            int tmp_cur = i+loop_cnt*num_people+1; //第一个孩子给一个 不是 0个
            
            // 如果已经不足 则证明到了最后一个 加上最后一个即可
            if(candies<tmp_cur)
            {
                res[i] += candies;
                break;
            }
            
            res[i++] +=tmp_cur ;
            candies -= tmp_cur;

            // 做再次循环
            if(i>num_people-1)
            {
                i = 0;
                loop_cnt ++;
            }

        }
            
           
        return res;
    }
};

int main(void)
{
    int candies =10;
    int num_people = 3;

    Solution s1;
    std::vector<int> vec = s1.distributeCandies(candies,num_people);

    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<endl;

    

    return 0;
}
