#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
    //¶þ²æÊ÷Àý×Ó
    BTNode* root=example();
    cout<<root->lchild->value<<endl;
    return 0;
}
