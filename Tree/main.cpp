#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
    //����������
    BTNode* root=example();
    cout<<root->lchild->value<<endl;

    //�����������
    pre_order(root);
    cout<<endl;

    //�����������
    in_order(root);
    cout<<endl;

    //�����������
    post_order(root);
    cout<<endl;

    //Ҷ�ӽ���������
    int num=0;
    count_leaf(root,num);
    std::cout<<num<<endl;

    //��Ȳ���
    std::cout<<"depth:"<<getDepth(root)<<std::endl;
    return 0;
}
