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

#endif // LINK_LIST_H_


