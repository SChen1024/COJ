/**********************************************************************************************//**
 * @file    Code\offer\03_backList\backList.h.
 *
 * @brief   按照链表结果从尾部到头 返回一个结果值
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

// 头文件不用动, 每次将下面的内容提交即可

/**********************************************************************************************/
class Solution
{
    // 对于链表的节点, 包含了
    
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
        
        // 如果 节点不是最后一个节点
        if (head != NULL)
        {
            // 开始插入一个值
            result.insert(result.begin(), head->val);


            // 如果 下一个节点不是空的值, 将下一个节点放到开始的地方,循环在第一位插入一个值,
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
