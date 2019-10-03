#include <iostream>
#include "binary_tree.h"

using namespace std;

int main() {
    //-----------------二叉树例子-------------------------
    //创建一个简单的二叉树例子
    BTNode *root = CreateExample();
    std::cout << "root->value:" << root->value << std::endl;
    std::cout << "root->lchild->value:" << root->lchild->value << std::endl;

    //先序遍历测试
    std::cout << "PreOrder Traversal:";
    PreOrderTraversal(root);
    std::cout << std::endl;

    //中序遍历测试
    std::cout << "InOrder Traversal With Recursive:";
    InOrderTraversal(root);
    std::cout << std::endl;


    //中序遍历非递归

    //层次遍历
    std::cout << "Level Traversal:";
    LevelTraversal(root);
    std::cout << std::endl;

    //计算整棵树的叶节点数量
    int num=0;
    CountLeaf(root,num);
    std::cout<<"num_leaf of whole tree:"<<num<<std::endl;

    //计算左子树的叶节点数量
    int num2=0;
    CountLeaf(root->lchild,num2);
    std::cout<<"num_leaf of left child tree:"<<num2<<std::endl;

    //计算树的深度
    std::cout<<"Tree Depth:"<<CountTreeDepth(root)<<std::endl;




//    //中序遍历测试
//    in_order(root);
//    cout<<endl;
//    //中序遍历非递归
//    in_order2(root);
//    cout<<endl;
//
//    //后序遍历测试
//    post_order(root);
//    cout<<endl;
//
//    //叶子结点个数测试
//    int num=0;
//    count_leaf(root,num);
//    std::cout<<num<<endl;
//
//    //深度测试
//    std::cout<<"depth:"<<getDepth(root)<<std::endl;
//
//    //拷贝测试
//    BTNode* new_root=copyTree(root);
//    pre_order(root);
//    std::cout<<std::endl;
//    pre_order(new_root);
//    std::cout<<std::endl;
//
//
//    //前序遍历和后序遍历创建树的测试
//    string PreOrder="12473568";
//    string InOrder="47215386";
//    BTNode* cons_root=construct_tree(PreOrder,InOrder);
//    pre_order(cons_root);
//    std::cout<<std::endl;
//    in_order(cons_root);
//    std::cout<<std::endl;
//    post_order(cons_root);
//    std::cout<<std::endl;
//
//    //层次遍历测试
//    level_traversal(root);
//
//    //翻转二叉树测试
//    tree_mirror(root);
//    level_traversal(root); //层次遍历
    return 0;
}
