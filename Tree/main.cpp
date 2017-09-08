#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
    //二叉树例子
    BTNode* root=example();
    cout<<root->lchild->value<<endl;

    //先序遍历测试
    pre_order(root);
    cout<<endl;

    //中序遍历测试
    in_order(root);
    cout<<endl;

    //后序遍历测试
    post_order(root);
    cout<<endl;

    //叶子结点个数测试
    int num=0;
    count_leaf(root,num);
    std::cout<<num<<endl;

    //深度测试
    std::cout<<"depth:"<<getDepth(root)<<std::endl;

    //拷贝测试
    BTNode* new_root=copyTree(root);
    pre_order(root);
    std::cout<<std::endl;
    pre_order(new_root);
    std::cout<<std::endl;
    return 0;
}
