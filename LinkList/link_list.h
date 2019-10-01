#ifndef LINK_LIST_H_
#define LINK_LIST_H_

#include <iostream>
#include <vector>

struct ListNode
{
    int value;
    ListNode* next;
};

//根据已经有的数组创建链表,并且返回头结点地址
ListNode* createList(const std::vector<int>& v,int type);

//遍历链表
int traversal(ListNode* head);

//从尾到头打印链表
void reverse_traversal(ListNode* head);

//尾部插入一个元素
void addToTail(ListNode* &head,int value);

//找到某个值,返回第一次出现的地址
ListNode* find_value(ListNode* head,int value);


//删除某个值,并且返回是否成功
bool remove_value(ListNode* head,int value);


//第K个节点
ListNode* k_th_node(ListNode* head,int k);

//倒数第K个节点
ListNode* re_k_th_node(ListNode* head,int k);

//反转链表,并且返回新的头结点地址
ListNode* reverseList(ListNode* head);

//合并两个有序链表
ListNode* mergeList(ListNode* head1,ListNode* head2);

//判断链表是否有环
bool hasCircle(ListNode* head);
#endif // LINK_LIST_H_


