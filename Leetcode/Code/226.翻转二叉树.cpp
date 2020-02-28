/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {

        // 判断根节点 非空
        if(root == nullptr)
            return nullptr;

        // 交换左右节点, 然后依次转换相应的节点
        std::swap(root->left,root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;

    }
};
// @lc code=end

