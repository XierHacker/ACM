#include <iostream>
#include <vector>
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
                ListNode *head,*s,*r; //s指向新申请的节点,r指向终端节点
                head=new ListNode;
                head->next=nullptr;
                r=head;    //r指向头结点,因为此时头结点就是终端节点

                //遍历vector创建链表
                for(int i=0;i<v.size();i++)
                {
                    s=new ListNode;
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
                ListNode *head,*s;
                head=new ListNode;
                head->next=nullptr;

                for(int i=0;i<v.size();i++)
                {
                    s=new ListNode;
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
















































