//
// Created by xh on 2019/10/1.
//

#ifndef ACM_LINKLIST_H
#define ACM_LINKLIST_H

#include <iostream>
#include <vector>

struct ListNode {
    int value;
    ListNode *next_node;
};

//根据已经有的数组创建链表,并且返回头结点地址
ListNode *CreateListFromVector(const std::vector<int> &v, int type);


//链表尾部插入元素,其中头结点有可能改变
bool AddToTail(ListNode *&head, int value);

//查找链表中某个元素,并且返回这个元素的前一个元素的地址，要是找不到，返回nullptr
ListNode *FindValue(ListNode *head, int value);

//删除链表中某个元素
bool DeleteValue(ListNode *head, int value);


//反向打印链表
void ReverseTraversal(ListNode *head);

//翻转链表
ListNode *ReverseList(ListNode *head);

//链表整数相加
ListNode *AddTwoNumbers(ListNode *head1, ListNode *head2);


//打印链表内容
bool DisplayLinkList(const ListNode *head);


#endif //ACM_LINKLIST_H
