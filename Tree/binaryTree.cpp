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

