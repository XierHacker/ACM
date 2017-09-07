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







#endif // BINARY_TREE_H_
