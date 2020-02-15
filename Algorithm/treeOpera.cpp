// 二叉树 操作结果

#include <iostream>
#include <vector>

using namespace std;



// 定义 二叉树结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        
        // 前序遍历的 第一个节点表示根, 
        // 找到中序遍历中的根的位置, 左侧的是左子树,右侧的是右子树
        if(pre.empty())    return nullptr;
        
        return reConstruct(pre,0,pre.size()-1,vin,0,vin.size()-1);// 迭代计算
    }
    
    TreeNode* reConstruct(vector<int> &pre,int pre_start,int pre_end,vector<int> &vin,int in_start,int in_end)
    {
        if(pre_start > pre_end || in_start > in_end)
            return nullptr;
        
        // 根据前序 节点的首位作为 根节点
        TreeNode *root = new TreeNode(pre[pre_start]);
        
        // 找到中序 中 与首位一致的节点 左侧是左子树 右侧是右子树
        for(int i=in_start;i<=in_end;i++)
        {
            if(vin[i] == pre[pre_start])
            {
                // 构建左侧子树和右侧子树
                root->left = reConstruct(pre,
                                        pre_start+1,
                                        pre_start + (i - in_start),
                                        vin,
                                        in_start,
                                        i-1);
                root->right = reConstruct(pre,
                                         pre_start + (i - in_start)+1,
                                         pre_end,
                                         vin,
                                         i+1,
                                         in_end);
                return root;
            }
        }
        
        return root;
        
    }

    // 先序遍历
    void preOrder(TreeNode* root,vector<int> &vec)
    {
        if(root)
        {
            vec.push_back(root->val);
            preOrder(root->left, vec);
            preOrder(root->right,vec);
        }
    }

    // 中序遍历
    void inOrder(TreeNode* root,vector<int> &vec)
    {
        if(root)
        {
            inOrder(root->left, vec);
            vec.push_back(root->val);
            inOrder(root->right,vec);
        }
    }

    // 后序遍历
    void postOrder(TreeNode* root,vector<int> &vec)
    {
        if(root)
        {
            postOrder(root->left, vec);
            postOrder(root->right,vec);
            vec.push_back(root->val);
        }
    }


};
