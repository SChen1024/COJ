/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

    // 变成判断两个树是否相等 leetcode 100
    bool isSymmetric(TreeNode* node1, TreeNode * node2) {
        if(!node1 && !node2) return true;
        if(!node1 || !node2) return false;
        if(node1->val != node2->val) return false;
        return isSymmetric(node1->left,node2->right) && isSymmetric(node2->left,node1->right);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) {
            return true;
        }

        return isSymmetric(root->left,root->right);
        
    }
};
// @lc code=end

