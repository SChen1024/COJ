/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
        if(!flgBalance)
            return -1;

        if(root == nullptr)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        if(abs(left-right) > 1)
            flgBalance = 0;


        return max(left,right)+1;

    }



    bool isBalanced(TreeNode* root) {

        dfs(root);
        return flgBalance;
    }
};

