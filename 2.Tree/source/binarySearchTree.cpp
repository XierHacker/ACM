#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "binarySearchTree.h"

//二叉搜索树转双向链表，并且返回头结点
//二叉搜索树，注定采用中序遍历
//二叉搜索树结点之间的转换
void convertNode(BSTNode* root,BSTNode** LastNodeInList)
{
    if(root==nullptr)   {return nullptr;}       //边界判断

    BSTNode* current=root;      //设立一个指针指向当前节点

    //左
    if(current->lchild!=nullptr)    {convertNode(current->lchild,LastNodeInList);}

    //中(这个时候左子树应该已经遍历完了)
    current->lchild=*LastNodeInList;
    if(*LastNodeInList!=nullptr)    {(*LastNodeInList)->rchild=current;}
    *LastNodeInList=current;

    //右
    if(current->rchild!=nullptr)    {convertNode(current->rchild,LastNodeInList);}
}

BSTNode* convertToList(BSTNode* root)
{
    BSTNode* LastNodeInList=nullptr;
    convertNode(root,&LastNodeInList);

    //创建一个头结点
    BSTNode* head=LastNodeInList;
    while(head!=nullptr&&head->lchild!=nullptr)
    {
        head=head->lchild;
    }
    return head;
}

