#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
    //����������
    BTNode* root=example();
    cout<<root->lchild->value<<endl;
    return 0;
}
