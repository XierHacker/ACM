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
    std::cout<<std::endl;

}

//β������һ��Ԫ��(ͷ����п��ܸı�)
void addToTail(ListNode* &head,int value)
{
    //Ϊ��ֵ�����ռ�
    ListNode* s=new ListNode;
    s->value=value;
    s->next=nullptr;

    //���ͷ��㱾����ǿ�ֵ
    if(head==nullptr)
    {
        head=s;
    }
    else
    {
        ListNode* r=head;
        //���±���
        while(r->next!=nullptr)
        {
            r=r->next;
        }
        r->next=s;
    }
}


//�ҵ�ĳ��ֵ,���ص�һ�γ��ֵ�ǰһ���ڵ��ַ
ListNode* find_value(ListNode* head,int value)
{
    //�ж�head�Ƿ��ǿ�
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

//ɾ��ĳ��ֵ,���ҷ����Ƿ�ɹ�
bool remove_value(ListNode* head,int value)
{
    //���ҵ�ĳ��ֵ
    ListNode* p=find_value(head,value);
    //ֵ������
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
















































