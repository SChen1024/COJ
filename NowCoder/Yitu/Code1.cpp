#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 对于每一个区间

//  二分查找到符合一个位置满足插入值
// 对于左值返回最左侧的 不等于
// 右侧返回右侧的值
int binarySearch(std::vector<int> &vec,int l,int r,int data,int flg)
{
    int mid = l+(r-l)/2;
    // 表示是寻找左值的情况
    if(flg)
    {
        while (r > l)
        {
            if (vec[mid] >= data)
                r = mid;
            else
                l = mid + 1;
            
            mid = l+(r-l)/2;
        }
    }
    else
    {
        while (r > l)
        {
            if (vec[mid] > data)
                r = mid;
            else
                l = mid + 1;
            
            mid = l+(r-l)/2;
        }
    }
    
    return mid;
    
}


#define LOCAL 1



int main() {
    int T=0;
    #if LOCAL 
        T = 2;
    #else
        cin>>T;
    #endif
    for(int i=0;i<T;i++)
    {
        cout<<"Case #"<<i+1<<":"<<endl;

        // 输入 n m
        int n=0,m=0;
        #if LOCAL 
            n = 10,m=5;
        #else
            cin>>n>>m;
        #endif


        #if LOCAL
            
        std::vector<int> vecN = {0,1,2,3,4,5,6,7,8,9};
        std::vector<int> vecL = {0,10,-5,7,100};
        std::vector<int> vecR = {5,20,-3,7,105};

        #else
            // 读取数据
            std::vector<int> vecN(n);
            for(int j=0;j<n;j++)
                cin>>vecN[i];
        #endif
        // 排序
        sort(vecN.begin(),vecN.end());


        // 输入 m个区间
        int left =0,right = 0;
        for(int j=0;j<m;j++)
        {
            #if LOCAL
                left = vecL[j];
                right = vecR[j];
            #else
            cin>>left>>right;

            #endif
            // 判断输入值的大小 避免区间不存在
            if(left>right)
            {
                swap(left,right);
            }

            // 分别对于左右区间进行查找适合的插入位置, 座标差值就是 数目

            int tmp_l = binarySearch(vecN,0,vecN.size()-1,left,1);
            int tmp_r = binarySearch(vecN,0,vecN.size()-1,right,0);

            cout<<tmp_r-tmp_l<<endl;

        }

        
    }
}