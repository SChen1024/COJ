/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        // 反转链表
    ListNode * newHead = nullptr;

    // 临时节点 存储节点后续节点
    ListNode *tmp;
    while(head)
    {
        // 获取原节点的后续节点, 然后将原节点链接到当前节点前面
        tmp = head->next;
        head->next = newHead;
        newHead = head;

        head = tmp;
    }

    return newHead;

    }
};
// @lc code=end

