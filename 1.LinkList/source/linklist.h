//
// Created by xh on 2019/10/1.
//

#ifndef ACM_LINKLIST_H
#define ACM_LINKLIST_H

#include <iostream>
#include <vector>

struct ListNode{
    int value;
    ListNode* next_node;
};

//根据已经有的数组创建链表,并且返回头结点地址
ListNode* CreateListFromVector(const std::vector<int>& v,int type);
bool DisplayLinkList(const ListNode* head);


#endif //ACM_LINKLIST_H
