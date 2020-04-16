/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // 如果全null 相等 // 一个null  失败
        if(p==nullptr && q == nullptr)
            return true;
        if(p==nullptr || q == nullptr)
            return false;

        if(p->val == q->val)
        {   
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
        else
            return false;
        

        
    }
};

