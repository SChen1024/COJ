#include <string>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */
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

        ListNode *p = head;
        while(p != nullptr && p->next != nullptr)
        {
            if(p->val ==p->next->val)
                p->next = p->next->next;
            else
                p = p->next;
        }

        return head;
        
    }
};

