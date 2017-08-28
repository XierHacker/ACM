#ifndef LINK_LIST_H_
#define LINK_LIST_H_

#include <iostream>
#include <vector>

struct ListNode
{
    int value;
    ListNode* next;
};

//�����Ѿ��е����鴴������,���ҷ���ͷ����ַ
ListNode* createList(const std::vector<int>& v,int type);

//��������
int traversal(ListNode* head);

#endif // LINK_LIST_H_


