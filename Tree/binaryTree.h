#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>

struct BTNode
{
    char value;
    BTNode* lchild;
    BTNode* rchild;
};


//创建一个二叉树例子,返回根节点地址
BTNode* example();

//先序遍历二叉树
void pre_order(BTNode* root);

//中序遍历二叉树(递归形式)
void in_order(BTNode* root);
//中序遍历二叉树(非递归形式)
void in_order2(BTNode* root);

//后序遍历二叉树
void post_order(BTNode* root);

//计算叶子结点数量
void count_leaf(BTNode* root,int& sum);

//计算树的深度
int getDepth(BTNode* root);

//拷贝一棵二叉树,并且返回根节点
BTNode* copyTree(BTNode* root);

#endif // BINARY_TREE_H_
