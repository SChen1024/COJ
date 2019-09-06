// 常见排序算法的 C++ 实现

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
typedef vector<int> vint;


class Solution
{
    public:

    enum
    {
        SELECT_SORT = 1,
        BUBBLE_SORT = 2,
        INSERT_SORT = 3,
        SHELL_SORT  = 4,
        HEAP_SORT   = 5,
        MERGE_SORT  = 6,
        QUICK_SORT  = 7

    };

    float sort_(const vint &vec,int SORT)
    {
        vint tmpVec(vec);

        clock_t start_ = clock();
        switch (SORT)
        {
            case SELECT_SORT :  selectSort(tmpVec); break;
            case BUBBLE_SORT :  bubbleSort(tmpVec); break;
            case INSERT_SORT :  insertSort(tmpVec); break;
            case SHELL_SORT  :  shellSort(tmpVec); break;
            case HEAP_SORT   :  heapSort(tmpVec); break;
            case MERGE_SORT  :  mergeSort(tmpVec); break;
            case QUICK_SORT  :  quickSort(tmpVec); break;
            case 8:selectSort(tmpVec); break;
            case 9:selectSort(tmpVec); break;
            
            default:
                break;
        }
        clock_t end_ = clock();
        float time = (end_ -start_)*1000.0f/CLOCKS_PER_SEC;

        return time;

    }

    // 选择排序
    void selectSort(vint & vec)
    {
        // 遍历找到最小值 放到最前面
        for(int i=0;i<vec.size()-1;i++)
        {
            int min_ = i;

            for(int j=i+1;j<vec.size();++j)
            {
                if(vec[j]<vec[min_])
                {
                    min_ = j;
                }
            }

            // 如果不是本位就进行交换
            if(min_!=i)
                swap(vec[i],vec[min_]);
        }
    }

    // 依次相比 小的上浮
    void bubbleSort(vint &vec)
    {
        for(int i=0;i<vec.size()-1;i++)
        {
            bool flg_change = false;

            for(int j=0;j<vec.size()-1-i;j++)
            {
                if(vec[j]>vec[j+1])
                {
                    swap(vec[j],vec[j+1]);
                    flg_change = true;
                }
            }

            // 如果没有交换 则已经排序
            if(!flg_change)
                break;
        }
    }

    // 插入排序
    void insertSort(vint &vec)
    {
        for(int i=1;i<vec.size();i++)
        {
            int j=i;

            while(j>0 && vec[j]<vec[j-1])
            {
                swap(vec[j],vec[j-1]);
                j--;
            }
        }

    }

    // 希尔排序
    void shellSort(vint &vec)
    {
        // 增量 shell
        for(int gap = vec.size()/2;gap>0;gap /=2)
        {
            for(int i=gap;i<vec.size();i++)
            {
                int j=i;
                while(j-gap>=0 && vec[j]<vec[j-gap])
                {
                    swap(vec[j],vec[j-gap]);
                    j-=gap;
                }
            }
        }
    }

    
    // 堆排序
    void heapSort(vint &vec)
    {

    }
    // 归并排序
    void mergeSort(vint &vec)
    {

    }    
    // 快速排序
    void quickSort(vint &vec)
    {

    }  


};

// 输出数组
std::string coutVec(const vint &vec)
{
    std::string str="";
    for(int i=0;i<vec.size();i++)
    {
        // cout<<vec[i]<<",";
        str += to_string(vec[i]) +",";
    }
    // cout<<vec[vec.size()-1]<<endl;

    return str.substr(0,str.size()-1);

}



#define NUM 30000

int main(void)
{
    vint vec; // = {8,9,1,7,2,3,5,4,6,0};
    for(int i=0;i<NUM;i++) vec.push_back(rand()%NUM);



    Solution s1;
    
    // cout<<"src:\t\t"<<coutVec(vec)<<endl;

    for(int i=0;i<10;i++)
    {
        cout<<"sort:\t"<<i<<"time:\t"<<to_string(s1.sort_(vec,i))<<endl;
    }

    return 0;


}