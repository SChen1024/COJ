/**********************************************************************************************//**
 * @file    Code\offer\06_minimun_depth_of_binary_tree.cpp.
 *
 * @brief   Implements the 06 minimun depth of binary tree class  ���� ��������С���
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

// ͷ�ļ����ö�, ÿ�ν�����������ύ����
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

        // ���� �����������������
        int d_left = run(root->left);
        int d_right = run(root->right);

        // �������� ���� ��������һ��Ϊ0��ʱ�� ��ʾ������Ҷ�ڵ�
        // ���γ�ֻ��һ����֦����״��ʱ�� ���Ӧ����2 ������1  ����û������
        if (d_left == 0)
            return 1 + d_right;
        if (d_right == 0)
            return 1 + d_left;

        // �������֦����Ϊ0 ��ʱ��
        // Ӧ��ѡ�� ��С����һ��ķ�ֵ֦
        
        return  d_left>d_right?(1+d_right):(1+d_left);



    }



};
/*************************************************************************************************/




#endif //CLION_REPLACESPACE_H
#pragma once
