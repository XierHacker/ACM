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
}
