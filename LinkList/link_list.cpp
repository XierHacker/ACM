#include <iostream>
#include <vector>
#include <stack>
#include "link_list.h"

//根据已经有的数组创建链表,并且返回头结点地址
//type=0,表示尾插法.type=1,表示头插法
ListNode* createList(const std::vector<int>& v,int type)
{
    switch(type)
    {
        //尾插法
        case 0:
            {
                //创建头结点和一些必要的指针
                ListNode* head=new ListNode;
                head->next=nullptr;

                ListNode* r=head;    //r指向头结点,因为此时头结点就是终端节点,且r不断变化

                //遍历vector创建链表
                for(int i=0;i<v.size();i++)
                {
                    ListNode* s=new ListNode;
                    s->value=v[i];
                    r->next=s;  //
                    r=s;
                }
                r->next=nullptr;

                return head;
            }

        //头插法
        case 1:
            {
                //创建头结点和一些必要的指针
                ListNode *head=new ListNode;
                head->next=nullptr;

                for(int i=0;i<v.size();i++)
                {
                    ListNode* s=new ListNode;
                    s->value=v[i];
                    s->next=head->next;
                    head->next=s;
                }
                return head;
            }
    }
}

//遍历链表
int traversal(ListNode* head)
{
    ListNode* r=head->next;
    if(r==nullptr)
    {
        return -1;
    }
    while(r!=nullptr)
    {
        std::cout<<r->value<<" ";
        r=r->next;
    }
    std::cout<<std::endl;

}

//从尾到头打印链表(反向遍历)
void reverse_traversal(ListNode* head)
{
    //判断为空
    if(head==nullptr||head->next==nullptr)
        return ;
    std::stack<ListNode*> nodes;
    //因为头结点不存储元素
    ListNode* r=head->next;
    //往stack里面存节点地址
    while(r!=nullptr)
    {
        nodes.push(r);
        r=r->next;
    }

    //打印
    while(!nodes.empty())
    {
        r=nodes.top();
        std::cout<<r->value<<" ";
        nodes.pop();
    }
    std::cout<<std::endl;
}

//尾部插入一个元素(头结点有可能改变)
void addToTail(ListNode* &head,int value)
{
    //为新值创建空间
    ListNode* s=new ListNode;
    s->value=value;
    s->next=nullptr;

    //如果头结点本身就是空值
    if(head==nullptr)
    {
        head=s;
    }
    else
    {
        ListNode* r=head;
        //往下遍历
        while(r->next!=nullptr)
        {
            r=r->next;
        }
        r->next=s;
    }
}


//找到某个值,返回第一次出现的前一个节点地址
ListNode* find_value(ListNode* head,int value)
{
    //判断head是否是空
    if(head==nullptr)
    {
        return nullptr;
    }

    ListNode* r=head;
    while(r->next!=nullptr)
    {
        if(r->next->value==value)
        {
            return r;
        }
        r=r->next;
    }
    return nullptr;
}

//删除某个值,并且返回是否成功
bool remove_value(ListNode* head,int value)
{
    //先找到某个值
    ListNode* p=find_value(head,value);
    //值不存在
    if(p==nullptr)
        return false;
    else
    {
        ListNode* r=p->next;
        p->next=p->next->next;
        delete r;
        return true;
    }
}


//倒数第K个节点
ListNode* re_k_th_node(ListNode* head,int k)
{
    //head为空和k为0没有意义
    if(head==nullptr||k==0)
        return nullptr;

    //两个指针
    ListNode* ahead=head;
    ListNode* behind=nullptr;

    //前面这个指针先走到K
    //要是出现了过早出现nullptr的情况,表示数量不够K
    for(int i=1;i<=k-1;i++)
    {
        if(ahead->next!=nullptr)
            ahead=ahead->next;
        else
            return nullptr;
    }
    behind=head;

    //一起遍历到末尾
    while(ahead->next!=nullptr)
    {
        ahead=ahead->next;
        behind=behind->next;
    }

    return behind;
}


//反转链表,并且返回新的头结点地址
ListNode* reverseList(ListNode* head)
{
    //判断是否有效
    if(head==nullptr)
        return nullptr;

    ListNode* newHead=nullptr; //新的头结点
    ListNode* r=head; //往下遍历的的指针
    ListNode* pre=nullptr; //保存前一个地址

    while(r!=nullptr)
    {
        ListNode* pNext=r->next; //保存后一个地址

        //要是到最后的节点了,那么这个地址就是新的头结点地址
        if(r->next==nullptr)
            newHead=r;

        //往前指
        r->next=pre;

        //更新
        pre=r;
        r=pNext;

    }
    return newHead;
}

//合并两个有序链表
ListNode* mergeList(ListNode* head1,ListNode* head2)
{
    //判断为空的情况
    //要是两个都为空,返回也是空
    if(head1==nullptr||head1->next==nullptr)
        return head2;
    if(head2==nullptr||head2->next==nullptr)
        return head1;

    ListNode* mergedHead=nullptr;

    //用递归来完成
    if(head1->next->value<head2->next->value)
    {
        mergedHead=head1;
        mergedHead->next=mergeList(head1->next,head2);
    }
    else
    {
        mergedHead=head2;
        mergedHead->next=mergeList(head1,head2->next);
    }
    return mergedHead;
}

//判断链表是否有环
bool hasCircle(ListNode* head)
{
    //要是不存在链表（细节需要判断）
    if(head==nullptr||head->next==nullptr)
        return false;

    //定义快指针和慢指针
    ListNode* pFast=head;
    ListNode* pSlow=head;

    while(pFast&&pFast->next)
    {
        pFast=pFast->next->next; //快指针一次性走两步
        pSlow=pSlow->next;        //慢指针一次性走一步

        if(pFast==pSlow)
            return true;
    }
    //有一个指针走到了尽头,说明没有环
    return false;
}


