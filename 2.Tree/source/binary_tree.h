//
// Created by xh on 2019/10/2.
//

#ifndef TREE_BINARY_TREE_H
#define TREE_BINARY_TREE_H

struct BTNode {
    int value;
    BTNode *lchild;
    BTNode *rchild;
};

//创建一个二叉树例子,返回根节点地址
BTNode *CreateExample();

//先序遍历二叉树
void PreOrderTraversal(BTNode *root);

//中序遍历二叉树,递归版本和非递归版本
void InOrderTraversal(BTNode *root);

void InOrderTraversal2(BTNode *root);

//后序遍历二叉树
void PostOrderTraversal(BTNode *root);

//层次遍历二叉树
void LevelTraversal(BTNode *root);

#endif //TREE_BINARY_TREE_H
