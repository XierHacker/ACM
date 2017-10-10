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

//��β��ͷ��ӡ����
void reverse_traversal(ListNode* head);

//β������һ��Ԫ��
void addToTail(ListNode* &head,int value);

//�ҵ�ĳ��ֵ,���ص�һ�γ��ֵĵ�ַ
ListNode* find_value(ListNode* head,int value);


//ɾ��ĳ��ֵ,���ҷ����Ƿ�ɹ�
bool remove_value(ListNode* head,int value);


//��K���ڵ�
ListNode* k_th_node(ListNode* head,int k);

//������K���ڵ�
ListNode* re_k_th_node(ListNode* head,int k);

//��ת����,���ҷ����µ�ͷ����ַ
ListNode* reverseList(ListNode* head);

//�ϲ�������������
ListNode* mergeList(ListNode* head1,ListNode* head2);

//�ж������Ƿ��л�
bool hasCircle(ListNode* head);
#endif // LINK_LIST_H_


