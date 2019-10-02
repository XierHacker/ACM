#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
#include <iostream>

struct BSTNode
{
    int value;
    BTNode* lchild;
    BTNode* rchild;
};

//二叉搜索树转双向链表
BSTNode* convertToList(BSTNode* root);

#endif // BINARY_SEARCH_TREE_H_
