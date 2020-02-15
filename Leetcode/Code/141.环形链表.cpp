/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {

        if(!head) return false;       
        // 使用快慢指针判断环的存在以及环的位置
        ListNode *fast = head,*slow = head;

        while(fast && fast->next) {
            if(fast == slow)    return true;
            // 一个一步, 一个两步 最终相遇
            slow = slow->next;
            fast = fast->next->next;
        }
        return fast == nullptr?false:true;

        
        
    }
};
// @lc code=end

