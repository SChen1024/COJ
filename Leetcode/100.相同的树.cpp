/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
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

        // 全是空
        if(!p && !q) {
            return true;
        }
        // 只有一个节点为空
        if(!p || !q) {
            return false;
        }
        // 值不相等
        if(p->val != q->val) {
            return false;
        }

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);        
    }
};
// @lc code=end

