//
// Created by hugoc on 2019/1/12.
//

#ifndef CLION_SOLUTION_H
#define CLION_SOLUTION_H

#include <vector>
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool Find(int target, vector<vector<int> > array)
    {
        // 判断 是否在一个行之中
        if(array.empty())
        {
            cout<<"Array empty"<<endl;
            return false;
        }


        int W = array[0].size();
        int H = array.size();

        // 寸换判断每一行是否为空
        for (int i = 0; i < H;i++)
        {
            if(array[i].empty())
            {
                cout<<"ArrayLineEmpty"<<endl;
                return false;
            }

            // 如果大于首行的值 依次判断
            if(target >= array[i][0])
            {
                cout<<i<<endl;
                // 判断是否小于当前行的最大值  如果不是 直接 开始另一行的循环 直到判断 设定值在一个确定行中
                if(target<= array[i][W-1])
                {
                    cout<<i<<endl;
                    // 循环判断当前值 是否存在, 如果出现大于设定值的时候 需要break 进入下一个i 的循环
                    for (int j = 0; j < W;j++)
                    {
                        if(target == array[i][j])
                            return true;
                        else if(target <array[i][j] )
                            break;
                    }
                }
                else
                    continue; // 进入下一次循环过程中
            }

        }

        return false;
    }
};

/*
vector<vector<int> > array= {{1,2,8,9},
                             {2,4,9,12},
                             {4,7,10,13},
                             {6,8,11,15}};


solution s1;
s1.find(7,array);
*/
////////////////////////////////////////////////////////////////////////







#endif //CLION_SOLUTION_H
