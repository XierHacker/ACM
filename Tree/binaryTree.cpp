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

//�������������
void pre_order(BTNode* root)
{
    if(root!=nullptr)
    {
        //���ʸ��ڵ�
        std::cout<<root->value<<" ";

        //�������������
        pre_order(root->lchild);

        //�������������
        pre_order(root->rchild);
    }
}

//�������������
void in_order(BTNode* root)
{
    if(root!=nullptr)
    {
        //�������������
        in_order(root->lchild);
        //���ʸ��ڵ�
        std::cout<<root->value<<" ";
        //�������������
        in_order(root->rchild);
    }
}

//�������������
void post_order(BTNode* root)
{
    if(root!=nullptr)
    {
        post_order(root->lchild);
        post_order(root->rchild);
        std::cout<<root->value<<" ";
    }
}


//����Ҷ�ӽ������
//���ﱾ���ǰ��������������
void count_leaf(BTNode* root,int& sum)
{
    if(root!=nullptr)
    {
        //�����������ǿ�,˵����Ҷ�ӽ��
        if((root->lchild==nullptr)&&(root->rchild==nullptr))
        {
            ++sum;
            std::cout<<root->value<<" ";
        }
        count_leaf(root->lchild,sum);
        count_leaf(root->rchild,sum);
    }
}

//�����������
int getDepth(BTNode* root)
{
    //�߽�����
    if(root==nullptr)
        return 0;

    int LD=getDepth(root->lchild);
    int RD=getDepth(root->rchild);
    return std::max(LD,RD)+1;
}

//����һ�ö�����,���ҷ��ظ��ڵ�
BTNode* copyTree(BTNode* root)
{
    BTNode* newRoot=nullptr;
    BTNode* L_P=nullptr;
    BTNode* R_P=nullptr;

    //��copy������
    if(root->lchild!=nullptr)
    {
        L_P=copyTree(root->lchild);
    }

    //copy������
    if(root->rchild!=nullptr)
    {
        R_P=copyTree(root->rchild);
    }

    //Ū�������
    newRoot=new BTNode;
    newRoot->lchild=L_P;
    newRoot->rchild=R_P;
    newRoot->value=root->value;

    return newRoot;

}
