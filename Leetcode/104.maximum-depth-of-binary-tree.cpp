/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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

    // 返回节点的深度
    int flgBalance = 1;
    int dfs(TreeNode * root)
    {   

        if(root == nullptr)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        return max(left,right)+1;

    }



    int maxDepth(TreeNode* root) {
        int depth = dfs(root);
        return depth;
    }
};

