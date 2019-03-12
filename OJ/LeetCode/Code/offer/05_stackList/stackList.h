/**********************************************************************************************//**
 * @file    Code\offer\05_stackList\stackList.h.
 *
 * @brief   ʹ������ ջ stackʵ�ֶ���
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

// ͷ�ļ����ö�, ÿ�ν�����������ύ����
/**********************************************************************************************/

class Solution
{
    
    public:
    //���� ���н��� �� ֱ�ӽ�A ѹ�� S1 �� 
    void push(int node) {
        stack1.push(node);
    }

    // �����ж��Ƿ�Ϊ��, 
    // ���2�еĲ�Ϊ��, ֱ�ӷ���2���������ֵ
    // ���� �ж�1 �Ƿ�Ϊ��, �����е�װ,
    // 1 ��stack ���� 2�����ֵ������, ʵ�ֶ���
    int pop() {
        int res = 0;
        int tmp = 0;
        if (!stack2.empty())
        {
            // �˴����Բ�ִ��  ���ں���һ��ִ��
        }
        else if (stack1.empty ())
        {
            // ��1�е���ֵȫ�� ѹ��2�� ������,ͬʱɾ��1�е�����
            while (!stack1.empty())
            {
                tmp = stack1.top();
                stack2.push(tmp);
                stack1.pop();
            }
        }

        // ָ��2 �ĵ�һ��ֵ ����֮�� ɾ�������ֵ
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
