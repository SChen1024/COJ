/**********************************************************************************************//**
 * @file    Code\offer\05_stackList\stackList.h.
 *
 * @brief   使用两个 栈 stack实现队列
 * @changelog   2019/1/19    IRIS_Chen  Created.
 *************************************************************************************************/

#ifndef CLION_REPLACESPACE_H
#define CLION_REPLACESPACE_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <stack>

using namespace std;

// 头文件不用动, 每次将下面的内容提交即可
/**********************************************************************************************/

class Solution
{
    
    public:
    //对于 队列进入 则 直接将A 压入 S1 中 
    void push(int node) {
        stack1.push(node);
    }

    // 首先判断是否为空, 
    // 如果2中的不为空, 直接返回2的最上面的值
    // 否则 判断1 是否为空, 并进行倒装,
    // 1 是stack 倒序 2是输出值的正序, 实现队列
    int pop() {
        int res = 0;
        int tmp = 0;
        if (!stack2.empty())
        {
            // 此处可以不执行  放在后面一起执行
        }
        else if (stack1.empty ())
        {
            // 将1中的数值全部 压入2中 倒置了,同时删除1中的数据
            while (!stack1.empty())
            {
                tmp = stack1.top();
                stack2.push(tmp);
                stack1.pop();
            }
        }

        // 指向2 的第一个值 返回之后 删除掉这个值
        res = stack2.top();
        stack2.pop();


        return res;


    }

    private:
    stack<int> stack1;
    stack<int> stack2;
};

/*************************************************************************************************/




#endif //CLION_REPLACESPACE_H
#pragma once
