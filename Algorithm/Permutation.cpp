
// 全排列问题 总结

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// 输出一个 数组, 一行, 逗号分割
void coutVec(vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<",";
    }
    cout<<endl;
}


// 输出一个 二维数组, 每次输出一行得到结果
void coutVec(vector<vector<int>> &vec,string str="")
{
    for(int i=0;i<vec.size();i++)
    {
        cout<<str<<":"<<i<<"\t";
        coutVec(vec[i]);
    }

    cout<<"Size:\t"<<vec.size()<<endl;
}



// 所有全排列问题 总结 
// 全排列问题 主要有
class Solution
{
    public:
    vector<vector<int>> vec;


    public: 
    // 生成全排列数列   // 默认使用方式1 
    void generate(vector<int> &dat,int flg = 1)
    {
        switch(flg)
        {
            case 0: 
            case 1: generateRe(vec,0,dat); break;
            case 2: generateReNoRepeat(vec,0,dat);break;
            case 3: generateByNext(vec,dat);break;
            default: break;
        }
        
    }

    // 1. 迭代方式 生成全排列
    // 按照顺序值 生成全排列 // 无法处理重复数字
    //  生成的顺序 不是字典顺序 需要调整
    /*
        0       1,2,3,
        1       1,3,2,
        2       2,1,3,
        3       2,3,1,
        4       3,2,1,
        5       3,1,2,
    */
    void generateRe(vector<vector<int>> &res, int n,vector<int> &num)
    {
        if(n == num.size())
        {
            res.push_back(num);
        }
        else
        {
            // 从第一个数字开始, 每个数字分别和后面的数字交换
            for(int i=n;i<num.size();i++)
            {
                swap(num[n],num[i]);
                generateRe(res,n+1,num);
                swap(num[n],num[i]);
            }
        }
    }

    /*
        2. 有重复数字的全排列, 如果全排列里面存在重复数字, 相应的排列不会生成
    */
    // 判断一个数组的子区间有相同字符存在 // 是否存在与
    bool isRepeat(vector<int> &num,int l,int r)
    {
        for(int i=l;i<r;i++)
        {
            if(num[i] == num[r])
                return false;
        }
        return true;
    }
    void generateReNoRepeat(vector<vector<int>> &res, int n,vector<int> &num)
    {
        if(n == num.size())
        {
            res.push_back(num);
        }
        else
        {
            // 从第一个数字开始, 每个数字分别和后面的数字交换
            for(int i=n;i<num.size();i++)
            {
                // 如果存在重复字符
                if(isRepeat(num,n,i))
                {
                    swap(num[i],num[n]);
                    generateReNoRepeat(res,n+1,num);
                    swap(num[i],num[n]);
                }
            }
        }
    }

    /*
        3.  下一个全排列 
            获取 num 排列的下一个全排列, 如果已经是最后一个全排列 则返回第一个全排列
    */
    bool nextPermutation(vector<int> &num)
    {
        // 从后面开始找到一个非递增点 A1, 找到从该点到最后 的不小于A1的最小值 A2,
        // 交换A2 后全排列

        // 找到第一个非逆序点
        int pos = num.size()-1;
        while(pos &&num[pos] <= num[pos-1])
            pos--;
        // 找到第一位都没找到
        if(pos ==0)
        {
            sort(num.begin(),num.end());
            return false;
        }

        // 找到比 当前值大的最小值 交换后 后面的值 排序
        int second_min = INT_MAX,second_pos = INT_MAX;
        
        for(int i=num.size()-1;i>=pos-1;--i)
        {
            if(num[i] >num[pos-1])
                if(num[i] < second_min)
                {
                    second_min = num[i];
                    second_pos = i;
                }
        }
        swap(num[pos-1],num[second_pos]);
        sort(num.begin()+pos,num.end());

        return true;
    }


    // 3.1 循环下一个排列 获取所有全排列
    void generateByNext(vector<vector<int>> &res,vector<int> &num)
    {
        sort(num.begin(),num.end());
        do {
            res.push_back(num);
        }while(nextPermutation(num));
    }


    /*
        4. 上一个全排列
    
    */
    bool prePermutation(vector<int> &num)
    {
        // 从 

        // 找到第一个非逆序点
        int pos = num.size()-1;
        while(pos &&num[pos] <= num[pos-1])
            pos--;
        // 找到第一位都没找到
        if(pos ==0)
        {
            sort(num.begin(),num.end());
            return false;
        }

        // 找到比 当前值大的最小值 交换后 后面的值 排序
        int second_min = INT_MAX,second_pos = INT_MAX;
        
        for(int i=num.size()-1;i>=pos-1;--i)
        {
            if(num[i] >num[pos-1])
                if(num[i] < second_min)
                {
                    second_min = num[i];
                    second_pos = i;
                }
        }
        swap(num[pos-1],num[second_pos]);
        sort(num.begin()+pos,num.end());

        return true;
    }


};





int main(void)
{
    // 初始化 数组,
    vector<vector<int>> data = {{1,2,3},
                                 {1,2,2},
                                 {2,2,2}};

    Solution s1;
    s1.generate(data[0]);  // 生成全排列数组
    coutVec(s1.vec,"cnt1");
    s1.vec.clear();

    s1.generate(data[2],2);  // 生成全排列数组 // 有重复数字的全排列
    coutVec(s1.vec,"cnt2");
    s1.vec.clear();

    s1.generate(data[1],3);  // 生成全排列数组 // 有重复数字的全排列
    coutVec(s1.vec,"cnt3");
    s1.vec.clear();

    

    return 0;
}








