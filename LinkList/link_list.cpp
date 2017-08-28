#include <iostream>
#include <vector>
#include "link_list.h"

//�����Ѿ��е����鴴������,���ҷ���ͷ����ַ
//type=0,��ʾβ�巨.type=1,��ʾͷ�巨
ListNode* createList(const std::vector<int>& v,int type)
{
    switch(type)
    {
        //β�巨
        case 0:
            {
                //����ͷ����һЩ��Ҫ��ָ��
                ListNode *head,*s,*r; //sָ��������Ľڵ�,rָ���ն˽ڵ�
                head=new ListNode;
                head->next=nullptr;
                r=head;    //rָ��ͷ���,��Ϊ��ʱͷ�������ն˽ڵ�

                //����vector��������
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

        //ͷ�巨
        case 1:
            {
                //����ͷ����һЩ��Ҫ��ָ��
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

//��������
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
