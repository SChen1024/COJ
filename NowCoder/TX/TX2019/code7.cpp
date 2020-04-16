
// https://www.cnblogs.com/steven_oyj/archive/2010/05/23/1741975.html
// 腾讯面试题：位运算——用位存储40亿个40亿以内的整数
// 

#include <iostream>  
#include <stdlib.h>
#include <memory>
#include <string.h>
using namespace std;  
   
typedef unsigned int Bit32;  // 能表示42亿+的无符号整数  

const Bit32 maxLen=125000001; //数组长度,0-40亿  
const Bit32 thirtytwo=32;  

void createArray(Bit32 *&arr)  
{  
    arr=new Bit32[maxLen];  
    memset(arr,(Bit32)0,sizeof(arr));  
}  
 
bool setBit(Bit32 *arr,Bit32 num)  
{  
    if(((arr[num/thirtytwo])&(1<<(thirtytwo-num%thirtytwo-1)))==0)  
    {  
        arr[num/thirtytwo]|=1<<(thirtytwo-num%thirtytwo-1);  
        return true;  
    }  
    else  
    {  
        return false;  
    }  
}  
  
int main()  
{  
    Bit32 *s;  
    createArray(s);  
    if(!setBit(s,5))  
    {  
        cout<<"标记失败"<<endl;  
    }  
    if(!setBit(s,64))  
    {  
        cout<<"标记失败"<<endl;  
    }  
    if(!setBit(s,1))  
    {  
        cout<<"标记失败"<<endl;  
    }  

    return 0;  
}  