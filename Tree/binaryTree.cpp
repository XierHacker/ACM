#include <iostream>
#include "binaryTree.h"

//����һ������������,���ظ��ڵ��ַ
BTNode* example()
{
    BTNode *p1,*p2,*p3,*p4,*p5;
    //����ռ䲢�ҷ��ص�ַ
    p1=new BTNode;
    p2=new BTNode;
    p3=new BTNode;
    p4=new BTNode;
    p5=new BTNode;

    //д��������
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

