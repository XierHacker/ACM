#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>

struct BTNode
{
    char value;
    BTNode* lchild;
    BTNode* rchild;
};


//����һ������������,���ظ��ڵ��ַ
BTNode* example();

//�������������
void pre_order(BTNode* root);

//�������������(�ݹ���ʽ)
void in_order(BTNode* root);
//�������������(�ǵݹ���ʽ)
void in_order2(BTNode* root);

//�������������
void post_order(BTNode* root);

//����Ҷ�ӽ������
void count_leaf(BTNode* root,int& sum);

//�����������
int getDepth(BTNode* root);

//����һ�ö�����,���ҷ��ظ��ڵ�
BTNode* copyTree(BTNode* root);

#endif // BINARY_TREE_H_
