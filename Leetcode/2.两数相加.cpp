/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


        int flg = 0;    // 进位标志位

        ListNode* head = new ListNode(-1);
        ListNode *res = head;

        // 一直遍历到最后一个
        while(l1!=nullptr || l2!= nullptr)
        {
            // 如果当前链表不空， 加上当前值 后移
            if(l1 != nullptr)
            {
                flg += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr)
            {
                flg += l2->val;
                l2 = l2->next;
            }

            // 计算余数 作为最后一位 同时后移 flg 复位
            head->next = new ListNode(flg%10);
            head = head->next;
            flg /= 10;
        }

        // 如果仍有进位 处理结果
        if(flg != 0)
            head->next = new ListNode(flg);
        

        return res->next;

        
    }
};
// @lc code=end

