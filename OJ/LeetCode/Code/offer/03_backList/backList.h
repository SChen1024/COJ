/**********************************************************************************************//**
 * @file    Code\offer\03_backList\backList.h.
 *
 * @brief   ������������β����ͷ ����һ�����ֵ
 * @changelog   2019/1/17    IRIS_Chen  Created.
 *************************************************************************************************/

#ifndef CLION_REPLACESPACE_H
#define CLION_REPLACESPACE_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <list>

using namespace std;

// ͷ�ļ����ö�, ÿ�ν�����������ύ����

/**********************************************************************************************/
class Solution
{
    // ��������Ľڵ�, ������
    
     struct ListNode {
           int val;
           struct ListNode *next;
           ListNode(int x) :
                 val(x), next(NULL) {
           }
     };
    
    public:
    vector<int> printListFromTailToHead(ListNode* head) {


        vector<int> result;
        
        // ��� �ڵ㲻�����һ���ڵ�
        if (head != NULL)
        {
            // ��ʼ����һ��ֵ
            result.insert(result.begin(), head->val);


            // ��� ��һ���ڵ㲻�ǿյ�ֵ, ����һ���ڵ�ŵ���ʼ�ĵط�,ѭ���ڵ�һλ����һ��ֵ,
            while (head->next != NULL)
            {
                result.insert(result.begin(), head->next->val);
                head = head->next;
            }
        }


        return result;

    }
};
/*************************************************************************************************/




#endif //CLION_REPLACESPACE_H
#pragma once
