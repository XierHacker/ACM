//
// Created by xh on 2019/10/1.
//

#include <iostream>
#include "linklist.h"


int main(){
    std::vector<int> a={1,2,3,4,5,6,7};
    ListNode* head=CreateListFromVector(a,0);
    DisplayLinkList(head);

    return 0;
}
