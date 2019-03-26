/**********************************************************************************************//**
 * @file    Code\offer\06_minimun_depth_of_binary_tree.cpp.
 *
 * @brief   Implements the 06 minimun depth of binary tree class  计算 二叉树最小深度
 * @changelog   2019/2/16    IRIS_Chen  Created.
 *************************************************************************************************/

#ifndef CLION_REPLACESPACE_H
#define CLION_REPLACESPACE_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <list>

using namespace std;

// 头文件不用动, 每次将下面的内容提交即可
/**********************************************************************************************/

// Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution
{

    public:
    typedef TreeNode* tree;

    int run(TreeNode *root)
    {
        if (!root)
            return 0;

        // 迭代 计算左右子树的深度
        int d_left = run(root->left);
        int d_right = run(root->right);

        // 当跌倒到 左右 子树其中一个为0的时候 表示进入了叶节点
        // 当形成只有一个分枝的形状的时候 深度应该是2 而不是1  否则没法计算
        if (d_left == 0)
            return 1 + d_right;
        if (d_right == 0)
            return 1 + d_left;

        // 当两侧分枝都不为0 的时候
        // 应该选择 最小的那一侧的分枝值
        
        return  d_left>d_right?(1+d_right):(1+d_left);



    }



};
/*************************************************************************************************/




#endif //CLION_REPLACESPACE_H
#pragma once
