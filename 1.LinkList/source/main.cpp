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



    return 0;
}
