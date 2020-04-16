/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;

        if(root == nullptr)
            return res;
        
        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty())
        {
            vector<int> curLevel;

            // 取出现有队列元素 找寻各自的左右子树
            for(int i=Q.size();i>0;--i)
            {
                TreeNode *cur = Q.front();Q.pop();
                curLevel.push_back(cur->val);

                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
            // 首部插入值
            res.insert(res.begin(),curLevel);
        }


        return res;
        
    }
};

