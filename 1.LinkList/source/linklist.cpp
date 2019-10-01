//
// Created by xh on 2019/10/1.
//

#include "linklist.h"

//根据已经有的数组创建链表,并且返回头结点地址
ListNode* CreateListFromVector(const std::vector<int>& v,int type){
    if(v.empty()){return nullptr;}
    switch(type)
    {
        //尾插法
        case 0:
        {
            ListNode* head= new ListNode;
            head->next_node= nullptr;
            ListNode* r=head;
            for(int i=0;i<v.size();i++)
            {
                ListNode* temp_node=new ListNode;
                temp_node->value=v[i];
                r->next_node=temp_node;
                r=temp_node;
            }
            r->next_node= nullptr;
            return head;
        }
        case 1:
        {
            ;
        }

    }
}

bool DisplayLinkList(const ListNode* head){
    if((head== nullptr)||(head->next_node== nullptr)) {return false;}
    ListNode* r=head->next_node;
    while(r!= nullptr)
    {
        std::cout<<r->value<<std::endl;
        r=r->next_node;
    }
    return true;
}
