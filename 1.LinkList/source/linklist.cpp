//
// Created by xh on 2019/10/1.
//

#include "linklist.h"

//根据已经有的数组创建链表,并且返回头结点地址
ListNode *CreateListFromVector(const std::vector<int> &v, int type) {
    if (v.empty()) { return nullptr; }
    switch (type) {
        //尾插法
        case 0: {
            ListNode *head = new ListNode;
            head->next_node = nullptr;
            ListNode *r = head; //r指向头结点,因为此时头结点就是终端节点,且r不断变化
            //遍历vector创建链表
            for (int i = 0; i < v.size(); i++) {
                ListNode *temp_node = new ListNode;
                temp_node->value = v[i];
                r->next_node = temp_node;
                r = temp_node;
            }
            r->next_node = nullptr;
            return head;
        }
            //头插法
        case 1: {
            ListNode *head = new ListNode;
            head->next_node = nullptr;
            for (int i = 0; i < v.size(); i++) {
                ListNode *temp_node = new ListNode;
                temp_node->value = v[i];
                temp_node->next_node = head->next_node;
                head->next_node = temp_node;
            }
            return head;
        }

    }
}

//链表尾部插入元素,其中头结点有可能改变
bool AddToTail(ListNode *&head, int value) {
    ListNode *new_node = new ListNode;
    new_node->value = value;
    new_node->next_node = nullptr;

    //要是头节点本身是个nullptr
    if (head == nullptr) {
        head = new_node;
        return true;
    }
    ListNode *temp_node = head;
    while (temp_node->next_node != nullptr) {
        temp_node = temp_node->next_node;
    }
    temp_node->next_node = new_node;
    return true;
}

//查找链表中某个元素,并且返回这个元素的前一个元素的地址，要是找不到，返回nullptr
ListNode *FindValue(ListNode *head, int value) {
    if (head == nullptr) { return nullptr; }
    ListNode *temp_node = head;
    while (temp_node->next_node != nullptr) {
        if (temp_node->next_node->value == value) {
            return temp_node;
        }
        temp_node = temp_node->next_node;
    }
    return nullptr;
}


//删除链表中某个元素,删除成功返回true,否则返回false
bool DeleteValue(ListNode *head, int value) {
    if (head == nullptr) { return false; }
    ListNode *prev_node = FindValue(head, value);
    if (prev_node == nullptr) { return false; }

    //delete node
    ListNode* temp_node=prev_node->next_node;
    prev_node->next_node=prev_node->next_node->next_node;
    delete temp_node;
    return true;
}


bool DisplayLinkList(const ListNode *head) {
    if ((head == nullptr) || (head->next_node == nullptr)) { return false; }
    ListNode *r = head->next_node;
    while (r != nullptr) {
        std::cout << r->value << " ";
        r = r->next_node;
    }
    std::cout << std::endl;
    return true;
}
