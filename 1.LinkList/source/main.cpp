//
// Created by xh on 2019/10/1.
//

#include <iostream>
#include "linklist.h"


int main() {
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7};

    //创建链表
    ListNode *head = CreateListFromVector(a, 0);
    //显示链表
    DisplayLinkList(head);

    //链表尾部插入元素
    if (AddToTail(head, 5)) {
        DisplayLinkList(head);
    }

    //查找某个元素
    if (FindValue(head, 5) != nullptr) {
        std::cout << "Find Value:" << FindValue(head, 5)->value << std::endl;
    } else {
        std::cout << "Not Find!!" << std::endl;
    }

    //删除元素
    if (DeleteValue(head, 5)) {
        std::cout << "delete done:";
        DisplayLinkList(head);
    } else {
        std::cout << "delete Fail" << std::endl;
    }

    //反向打印链表
    ReverseTraversal(head);


    //两个整数相加
    std::vector<int> num1 = {1, 2, 3, 4, 5, 6, 7};
    ListNode *head1 = CreateListFromVector(num1, 1);
    std::cout << "head1:";
    DisplayLinkList(head1);
    std::vector<int> num2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *head2 = CreateListFromVector(num2, 1);
    std::cout << "head2:";
    DisplayLinkList(head2);

    ListNode *added_node = AddTwoNumbers(head1, head2);
    std::cout << "after tow number added" << std::endl;
    DisplayLinkList(added_node);


    //翻转链表
    std::cout << "ReverseList:";
    ListNode *reversed_head = ReverseList(head);
    DisplayLinkList(reversed_head);

    return 0;
}
