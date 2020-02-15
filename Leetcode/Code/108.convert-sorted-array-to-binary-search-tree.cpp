/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
public:`w
    // 从数组中间开始  递归左右建立子树
    TreeNode * dfs(vector<int>&nums,int left,int right)
    {
        if(left>right) 
            return nullptr;
        int mid = left+(right-left)/2;
        TreeNode *root  = new TreeNode(nums[mid]);
        root->left = dfs(nums,left,mid-1);
        root->right = dfs(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }
};

