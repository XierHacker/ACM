#include <iostream>
#include <stack>
#include <string>
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

//�������������(�ǵݹ���ʽ)
BTNode* goLeft(BTNode* root,std::stack<BTNode*> &s)   //һֱ����������,ֱ���õ����Է��ʵĽ��
{
    //�߽�����[�ж�
    if(root==nullptr)
        return nullptr;

    //һֱ������,Ҫ��rootһֱ������,��ô��root��ջ.
    while(root->lchild!=nullptr)
    {
        s.push(root);
        root=root->lchild;
    }

    //��rootû��������,�ͷ���root
    return root;
}
void in_order2(BTNode* root)
{
    BTNode* t=nullptr;
    //�洢ջ
    std::stack<BTNode*> s;

    //һֱ����ֱ��û������
    t=goLeft(root,s);

    while(t!=nullptr)
    {
        //����ýڵ������
        std::cout<<t->value<<" ";

        //Ҫ��t��������,�ظ�����1
        if(t->rchild!=nullptr)
        {
            t=goLeft(t->rchild,s); //���������ҵ�����������
        }
        else if(!s.empty())     //Ҫ��tû��������,ջ��Ϊ��
        {
            t=s.top();
            s.pop();
        }
        else                    //Ҫ��tû��������,ջΪ��
        {
            t=nullptr;          //�˳�ѭ��
        }
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


//ͨ��ǰ��������������������һ����
//��������Ǵ������ĺ��ĵݹ麯��(������ǵ�����)
BTNode* construct_core(std::string::iterator pre_order_begin,
                       std::string::iterator pre_order_end,
                       std::string::iterator in_order_begin,
                       std::string::iterator in_order_end)
{
    //ǰ��������еĵ�һ�������Ǹ��ڵ��ֵ
    BTNode* root=new BTNode;
    root->value=*pre_order_begin;
    root->lchild=root->rchild=nullptr;

    //�߽����������ʱ��ֻ��һ���ڵ���
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


    //����������ҵ����ڵ��ֵ
    auto temp_itor=in_order_begin;
    while((temp_itor<=in_order_end) && (*temp_itor!=root->value))
    {
        ++temp_itor;
    }

    if((temp_itor==in_order_end) && (*temp_itor!=root->value))  //�����ж�
    {
        std::cout<<"invalid input"<<std::endl;
        return nullptr;
    }


    int left_length=temp_itor-in_order_begin; //������������ж�����������

    auto left_pre_order_end=pre_order_begin+left_length; //��������ĩ�˵�����

    if(left_length>0)
    {
        //����������
        root->lchild=construct_core(pre_order_begin+1,left_pre_order_end,in_order_begin,temp_itor-1);
    }
    if(left_length<pre_order_end-pre_order_begin)
    {
        //����������
        root->rchild=construct_core(left_pre_order_end+1,pre_order_end,temp_itor+1,in_order_end);
    }
    return root;
}

//����ֱ�Ӵ���һ��������������к�һ��������������о�����
BTNode* construct_tree(std::string& PreOrder,std::string& InOrder)
{
    //�����ж�
    if(PreOrder.size()<=0||InOrder.size()<=0)  //û��Ԫ�ص�ʱ��,��ô���ܹ�����
    {
        std::cout<<"no element!"<<std::endl;
        return nullptr;
    }

    if(PreOrder.size()!=InOrder.size())        //Ҫ��ǰ����������������Ԫ�ظ�����һ������ôҲ�Ǵ����
    {
        std::cout<<"invalid input!"<<std::endl;
        return nullptr;
    }
    //���õݹ麯��
    return construct_core(PreOrder.begin(),PreOrder.end()-1,InOrder.begin(),InOrder.end()-1);
}
