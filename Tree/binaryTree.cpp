#include <iostream>
#include <stack>
#include <string>
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

//中序遍历二叉树(非递归形式)
BTNode* goLeft(BTNode* root,std::stack<BTNode*> &s)   //一直往左子树走,直到得到可以访问的结点
{
    //边界条件[判断
    if(root==nullptr)
        return nullptr;

    //一直往左走,要是root一直有左孩子,那么就root入栈.
    while(root->lchild!=nullptr)
    {
        s.push(root);
        root=root->lchild;
    }

    //当root没有左孩子了,就返回root
    return root;
}
void in_order2(BTNode* root)
{
    BTNode* t=nullptr;
    //存储栈
    std::stack<BTNode*> s;

    //一直往左直到没有左孩子
    t=goLeft(root,s);

    while(t!=nullptr)
    {
        //输出该节点的内容
        std::cout<<t->value<<" ";

        //要是t有右子树,重复步骤1
        if(t->rchild!=nullptr)
        {
            t=goLeft(t->rchild,s); //右子树中找到中序遍历起点
        }
        else if(!s.empty())     //要是t没有右子树,栈不为空
        {
            t=s.top();
            s.pop();
        }
        else                    //要是t没有右子树,栈为空
        {
            t=nullptr;          //退出循环
        }
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


//通过前序遍历和中序遍历来创建一颗树
//这个函数是创建树的核心递归函数(传入的是迭代器)
BTNode* construct_core(std::string::iterator pre_order_begin,
                       std::string::iterator pre_order_end,
                       std::string::iterator in_order_begin,
                       std::string::iterator in_order_end)
{
    //前序遍历序列的第一个数字是根节点的值
    BTNode* root=new BTNode;
    root->value=*pre_order_begin;
    root->lchild=root->rchild=nullptr;

    //边界条件，这个时候只有一个节点了
    if(pre_order_begin==pre_order_end)
    {
        if((in_order_begin==in_order_end)&&(*pre_order_begin==*in_order_begin))
            return root;
        else
        {
            std::cout<<"invalid input"<<std::endl;
            return nullptr;
        }
    }


    //中序遍历中找到根节点的值
    auto temp_itor=in_order_begin;
    while((temp_itor<=in_order_end) && (*temp_itor!=root->value))
    {
        ++temp_itor;
    }

    if((temp_itor==in_order_end) && (*temp_itor!=root->value))  //意外判断
    {
        std::cout<<"invalid input"<<std::endl;
        return nullptr;
    }


    int left_length=temp_itor-in_order_begin; //中序遍历序列判断左子树长度

    auto left_pre_order_end=pre_order_begin+left_length; //左子树的末端迭代器

    if(left_length>0)
    {
        //构建左子树
        root->lchild=construct_core(pre_order_begin+1,left_pre_order_end,in_order_begin,temp_itor-1);
    }
    if(left_length<pre_order_end-pre_order_begin)
    {
        //构建右子树
        root->rchild=construct_core(left_pre_order_end+1,pre_order_end,temp_itor+1,in_order_end);
    }
    return root;
}

//这里直接传入一个先序遍历的序列和一个中序遍历的序列就行了
BTNode* construct_tree(std::string& PreOrder,std::string& InOrder)
{
    //条件判断
    if(PreOrder.size()<=0||InOrder.size()<=0)  //没有元素的时候,那么不能够运行
    {
        std::cout<<"no element!"<<std::endl;
        return nullptr;
    }

    if(PreOrder.size()!=InOrder.size())        //要是前序遍历和中序遍历的元素个数不一样，那么也是错误的
    {
        std::cout<<"invalid input!"<<std::endl;
        return nullptr;
    }
    //调用递归函数
    return construct_core(PreOrder.begin(),PreOrder.end()-1,InOrder.begin(),InOrder.end()-1);
}
