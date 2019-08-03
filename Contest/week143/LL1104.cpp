#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
                
        
        std::vector<int> vec;

        // 将相应的值 加入列表中
        int pLabel = label;

        while(pLabel != 1)
        {
            vec.push_back(pLabel);
            pLabel = findParentInZTree(pLabel);

        }


        
        vec.push_back(pLabel);

        return vec;

    }
    
    int findParentInZTree(int label)
    {
        // 计算出来第几层 0开始
        int rows = getLog2(label);
        
        if(rows==0)
            return 1;
        
        // 计算出来第几个 0开始 左侧开始 本身节点和父节点
        int cols =0;
        int pLeft=0;
        int pLabel = -1;
        // 此处的row 代表减1 的值 所以 奇偶相反
        if(rows & 1 )
        {
            cols = (1<<(rows+1))-label-1;
            pLabel = (1<<(rows-1)) + (cols>>1);
        }
        else      
        {
            cols = label-(1<<rows);
            pLabel = (1<<rows)-1-(cols>>1);
        }

        return pLabel;
        
    }

    // 快速 log2 
    // 参考 https://blog.csdn.net/ce123_zhouwei/article/details/16961615
    // https://blog.csdn.net/YanEast/article/details/78985819
    int FastLog2(int x)
    {
        float fx;
        unsigned long ix, exp;

        fx = (float)x;
        ix = *(unsigned long*)&fx;
        exp = (ix >> 23) & 0xFF;

        return exp - 127;
    }

    #define POW223	8388608.0f			// 2^23
    float __log2(float x)
    {
        long *a;
        float o;
        a = (long*)&x;					// 强制的位转换
        o = (float)*a;
        o = o - POW223 * 126.92807138f;	// 127.0f - sigem, ???实际证明那个0.04几的值误差非常大....
        o = o / POW223;
        return o;
    }

    int getLog2(int x)
    {
        int i=0;
        while(x)
        {
            x>>1;
            i++;
        }

        return i-1;
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

    Solution s1;
    std::vector<int> vec1 = s1.pathInZigZagTree(14);
    coutVec(vec1);

    return 0;
}

