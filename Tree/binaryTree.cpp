#include <iostream>
#include "binaryTree.h"

//创建一个二叉树例子,返回根节点地址
BTNode* example()
{
    BTNode *p1,*p2,*p3,*p4,*p5;
    //分配空间并且返回地址
    p1=new BTNode;
    p2=new BTNode;
    p3=new BTNode;
    p4=new BTNode;
    p5=new BTNode;

    //写入结点内容
    p1->value='A';
    p2->value='B';
    p3->value='C';
    p4->value='D';
    p5->value='E';

    p1->lchild=p2;
    p1->rchild=p3;

    p2->lchild=p4;
    p2->rchild=nullptr;

    p3->lchild=p5;
    p3->rchild=nullptr;

    p4->lchild=nullptr;
    p4->rchild=nullptr;

    p5->lchild=nullptr;
    p5->rchild=nullptr;

    return p1;
}

//先序遍历二叉树
void pre_order(BTNode* root)
{
    if(root!=nullptr)
    {
        //访问根节点
        std::cout<<root->value<<" ";

        //先序遍历左子树
        pre_order(root->lchild);

        //先序遍历右子树
        pre_order(root->rchild);
    }
}

//中序遍历二叉树
void in_order(BTNode* root)
{
    if(root!=nullptr)
    {
        //中序遍历左子树
        in_order(root->lchild);
        //访问根节点
        std::cout<<root->value<<" ";
        //中序遍历右子树
        in_order(root->rchild);
    }
}

//后序遍历二叉树
void post_order(BTNode* root)
{
    if(root!=nullptr)
    {
        post_order(root->lchild);
        post_order(root->rchild);
        std::cout<<root->value<<" ";
    }
}


//计算叶子结点数量
//这里本身是按照先序遍历来的
void count_leaf(BTNode* root,int& sum)
{
    if(root!=nullptr)
    {
        //左右子树都是空,说明是叶子结点
        if((root->lchild==nullptr)&&(root->rchild==nullptr))
        {
            ++sum;
            std::cout<<root->value<<" ";
        }
        count_leaf(root->lchild,sum);
        count_leaf(root->rchild,sum);
    }
}

//计算树的深度
int getDepth(BTNode* root)
{
    //边界条件
    if(root==nullptr)
        return 0;

    int LD=getDepth(root->lchild);
    int RD=getDepth(root->rchild);
    return std::max(LD,RD)+1;
}

//拷贝一棵二叉树,并且返回根节点
BTNode* copyTree(BTNode* root)
{
    BTNode* newRoot=nullptr;
    BTNode* L_P=nullptr;
    BTNode* R_P=nullptr;

    //先copy左子树
    if(root->lchild!=nullptr)
    {
        L_P=copyTree(root->lchild);
    }

    //copy右子树
    if(root->rchild!=nullptr)
    {
        R_P=copyTree(root->rchild);
    }

    //弄出跟结点
    newRoot=new BTNode;
    newRoot->lchild=L_P;
    newRoot->rchild=R_P;
    newRoot->value=root->value;

    return newRoot;

}
