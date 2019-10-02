//
// Created by xh on 2019/10/1.
//

#include "linklist.h"
#include <iostream>
#include <vector>
#include <stack>

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
    ListNode *temp_node = prev_node->next_node;
    prev_node->next_node = prev_node->next_node->next_node;
    delete temp_node;
    return true;
}

//反向打印链表
void ReverseTraversal(ListNode *head) {
    if (head == nullptr || head->next_node == nullptr) { return; }
    std::stack<ListNode *> storage;
    ListNode *temp_node = head->next_node;
    while (temp_node->next_node != nullptr) {
        storage.push(temp_node);
        temp_node = temp_node->next_node;

    }
    std::cout << "Reverse Traversal:";
    while (!storage.empty()) {
        temp_node = storage.top();        //获得最上面元素
        std::cout << temp_node->value << " ";
        storage.pop();                  //弹出元素
    }
    std::cout << std::endl;
}


//链表整数相加
ListNode* AddTwoNumbers(ListNode* head1,ListNode* head2){
    if((head1== nullptr)&&(head2== nullptr)){return nullptr;}
    ListNode* new_head=new ListNode;
    new_head->next_node= nullptr;
    ListNode* temp1=head1->next_node;
    ListNode* temp2=head2->next_node;
    int d=0;        //进位
    while(temp1||temp2||d){
        int sum=0;
        //求和
        sum+=(temp1?temp1->value:0);
        sum+=(temp2?temp2->value:0);
        sum+=d;
        d=sum/10;
        sum%=10;

        //头插法创建链表
        ListNode* new_temp=new ListNode;
        new_temp->value=sum;
        new_temp->next_node=new_head->next_node;
        new_head->next_node=new_temp;

        //记得转移到下一个节点,不然死循环
        temp1=temp1?temp1->next_node: nullptr;
        temp2=temp2?temp2->next_node: nullptr;
    }
    return new_head;
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
