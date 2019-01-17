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
    void replaceSpace(char *str,int length) {
        if(str==NULL)
            return ;

        string str1 ="";
        int countOfBlank=0;// 计数 空格数目
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]==' ')
                countOfBlank ++;
        }

        for(int i=0;i<20;i++ )
            str[i] = 'A';


        cout<<str<<endl;


    }





    void replaceSpace2(char *str,int length) {
        if(str==NULL)
            return ;
        int CountOfBlanks=0;
        int Originallength=0;
        for(int i=0;str[i]!='\0';i++)
        {
            Originallength++;
            if(str[i]==' ')
                ++CountOfBlanks;
        }
        int len =Originallength+2*CountOfBlanks;
        if(len+1>length)
            return ;

        char*pStr1=str+Originallength;//复制结束符‘\0’
        char*pStr2=str+len;
        while(pStr1<pStr2)
        {
            if(*pStr1==' ')
            {
                *pStr2--='0';
                *pStr2--='2';
                *pStr2--='%';
            }
            else
            {
                *pStr2--=*pStr1;
            }
            --pStr1;
        }
    }
};
////////////////////////////////////////////////////////////////////////



#endif //CLION_REPLACESPACE_H
