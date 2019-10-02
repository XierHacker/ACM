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
BTNode* CreateExample();

//先序遍历二叉树
void pre_order(BTNode* root);

//中序遍历二叉树(递归形式)
void in_order(BTNode* root);
//中序遍历二叉树(非递归形式)
void in_order2(BTNode* root);

//后序遍历二叉树
void post_order(BTNode* root);

//逐层遍历二叉树
void level_traversal(BTNode* root);

//计算叶子结点数量
void count_leaf(BTNode* root,int& sum);

//计算树的深度
int getDepth(BTNode* root);

//拷贝一棵二叉树,并且返回根节点
BTNode* copyTree(BTNode* root);

//通过前序遍历和中序遍历来创建一颗树
BTNode* construct_tree(std::string& PreOrder,std::string& InOrder);

//翻转二叉树
void tree_mirror(BTNode* root);

//二叉树中和为某一值的路径
void findPath(BTNode* root,int expectedSum,std::vector<int> path,int realSum);


#endif // BINARY_TREE_H_
