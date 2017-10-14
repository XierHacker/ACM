#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "binarySearchTree.h"

//����������ת˫���������ҷ���ͷ���
//�������������֮���ת��
void convertNode(BSTNode* root,BSTNode** LastNodeInList)
{
    //������������ע�������������
    //�߽��ж�
    if(root==nullptr)
        return nullptr;

    //����һ��ָ��ָ��ǰ�ڵ�
    BSTNode* current=root;

    //��
    if(current->lchild!=nullptr)
        convertNode(current->lchild,LastNodeInList);

    //��
    current->lchild=*LastNodeInList;
    if(*LastNodeInList!=nullptr)
        (*LastNodeInList)->rchild=current;
    *LastNodeInList=current;

    //��
    if(current->rchild!=nullptr)
        convertNode(current->rchild,LastNodeInList);
}

BSTNode* convertToList(BSTNode* root)
{
    BSTNode* LastNodeInList=nullptr;
    convertNode(root,&LastNodeInList);

    //����һ��ͷ���
    BSTNode* head=LastNodeInList;
    while(head!=nullptr&&head->lchild!=nullptr)
    {
        head=head->lchild;
    }
    return head;
}

