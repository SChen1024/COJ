/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        // 根节点为 空
        if(root == nullptr) 
            return 0;

        // 分别计算左右子树
        if(!root->left) 
            return minDepth(root->right)+1;     //左子树为空，则只计算右子树深度
        if(!root->right) 
            return minDepth(root->left)+1;      //右子树为空，则只计算左子树深度
            
        return std::min(minDepth(root->left), minDepth(root->right)) + 1;



    }
};
// @lc code=end

