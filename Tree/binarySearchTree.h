#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
#include <iostream>

struct BSTNode
{
    int value;
    BTNode* lchild;
    BTNode* rchild;
};

//����������ת˫������
BSTNode* convertToList(BSTNode* root);

#endif // BINARY_SEARCH_TREE_H_
