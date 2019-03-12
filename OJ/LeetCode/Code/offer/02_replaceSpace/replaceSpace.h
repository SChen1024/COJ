//
// Created by hugoc on 2019/1/13.
//

#ifndef CLION_REPLACESPACE_H
#define CLION_REPLACESPACE_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:

    // 题目不知道怎么处理. 但是感觉问题很多, * 传递 指针不一致, length 没有说明是干什么用的

    void replaceSpace(char *str,int length) {
        if(str==NULL)
            return ;

        int countOfBlank=0;// 计数 空格数目
        int strlength = strlen(str);  // 字符串长度

        for(int i=0;i<strlength;i++)
        {
            if(str[i]==' ')
                countOfBlank ++;
        }

        // 因为传递进来的是 *str 与原始地址不同, 但是指向的位置一致, 所以要改变指向位置的结果值


        char *pstr1 = str + strlength; //指向字符串最后面的 /0
        char *pstr2 = str + strlength + countOfBlank * 2; // 每个空格的位置编程%20  
                                                          // 多出来两倍的空格位置

        // 操作存在问题, 不能判断 字符串后面的值 内存存储的内容,直接改写会造成错误, 但是没有别的方法
        while (pstr1 < pstr2)
        {
            if (*pstr1 == ' ')
            {
                *pstr2-- = '0';
                *pstr2-- = '2';
                *pstr2-- = '%';
            }
            else
            {
                *pstr2-- = *pstr1;
            }
            --pstr1;
        }
        //cout<<str<<endl;


    }



};
////////////////////////////////////////////////////////////////////////



#endif //CLION_REPLACESPACE_H
