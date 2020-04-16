/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {

        // 判断非空头节点 前查一个 然后依次判断是否相等即可
        if(head == nullptr) return head;


        // 保证前插节点不一样 // 可能出现溢出 但是肯定节点不一致
        ListNode *new_head = new ListNode(head->val - 1);
        new_head->next = head;

        // 如果后节点等于当前节点 删除后节点
        ListNode *p = new_head;
        while(p && p->next) {
            if(p->val == p->next->val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }

        return new_head->next;



        
    }
};
// @lc code=end

