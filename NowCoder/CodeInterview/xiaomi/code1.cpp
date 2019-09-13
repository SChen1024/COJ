// 根据字符串 重建二叉树 然后中序遍历

/*****************************************************************/
// 包含必须的头文件

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

// 定义本地
#define LOCAL_ 1

typedef vector<int>             Vint;
typedef vector<string>          Vstr;
typedef vector<vector<int>>     VVint;


// 常用输出函数 
// 一维 数组输出
template <typename T>
std::string CoutVec(const T& vec,int flg =0)
{
    std::string str="";
    for(int i=0;i<vec.size();i++)
    {
        str += to_string(vec[i])  +", ";
    }

    // 默认不输出 换行
    if(flg)
        str += "\n";
    // cout<<str;
    
    return str;
}

// 二维数组输出
template <typename T>
std::string CoutVec2(const T& vec,int flg =1)
{
    std::string str="";
    for(int i=0;i<vec.size();i++)
    {
        str += CoutVec(vec[i],flg);
    }
    return str;
}


/*****************************************************************/

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int v):val(v),left(nullptr),right(nullptr) {}
};


// 递归简历二叉树
TreeNode* buildTree(string &str)
{
    if(str.empty())
        return nullptr;

    int pos = str.find('(');
    
    int val;
    if(pos == string::npos) 
        val = stoi(str);
    else
    {
        stoi(str.substr(0,pos));
    }

    
    


    
    // 当遍历到节点之后


}


// 建立节点
TreeNode* createNode(void)
{
    // 保证输入的str 为 { r(l,r)   }的形式


}

// 中序遍历二叉树
void inOrder(TreeNode * root,vector<int> &vec)
{
    if(root->left != nullptr)
        inOrder(root->left,vec);
    vec.push_back(root->val);
    if(root->right != nullptr)
        inOrder(root->right,vec);
}


int  main(void)
{
    string str ="";
    cin>>str;

    if(str.empty())
        return ;

    // TreeNode * root;
    TreeNode * root = buildTree(str);



    // 中序遍历
    vector<int> inOrderVec;
    inOrder(root,inOrderVec);

    // 遍历输出
    for(auto v:inOrderVec)
        cout<<v;
    cout<<endl;


    return 0
}