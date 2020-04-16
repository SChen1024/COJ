/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int sum) {
        // 空节点 不存在
        if(root == nullptr)
            return false;
        
        // 当前节点 等于和  则存在
        if(root->left == nullptr && root->right == nullptr && root->val == sum)
            return true;
        
        return hasPathSum(root->left,sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
// @lc code=end

