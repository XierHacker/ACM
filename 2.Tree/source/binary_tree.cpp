//
// Created by xh on 2019/10/2.
//

#include "binary_tree.h"

#include <iostream>

//创建一个二叉树例子,返回根节点地址
BTNode* CreateExample(){
    BTNode *p1,*p2,*p3,*p4,*p5;
    //分配空间并且返回地址
    p1=new BTNode;
    p2=new BTNode;
    p3=new BTNode;
    p4=new BTNode;
    p5=new BTNode;

    //写入结点内容
    p1->value=1;
    p2->value=2;
    p3->value=3;
    p4->value=4;
    p5->value=5;

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
void PreOrderTraversal(BTNode* root){
    if(root== nullptr) {return ;}       //地柜结束条件
    std::cout<<root->value<<" ";        //访问根节点
    PreOrderTraversal(root->lchild);    //先序遍历左子树
    PreOrderTraversal(root->rchild);    //先序遍历右子树
}

//中序遍历二叉树,递归版本和非递归版本
void InOrderTraversal(BTNode* root){
    if(root== nullptr) {return ;}
    InOrderTraversal(root->lchild);     //中序遍历左子树
    std::cout<<root->value<<" ";        //访问根节点
    InOrderTraversal(root->rchild);     //中序遍历右子树
}
void InOrderTraversal2(BTNode* root){


}

//后序遍历二叉树
void PostOrderTraversal(BTNode* root){
    if(root== nullptr) {return ;}
    PostOrderTraversal(root->lchild);     //中序遍历左子树
    PostOrderTraversal(root->rchild);     //中序遍历右子树
    std::cout<<root->value<<" ";        //访问根节点
}