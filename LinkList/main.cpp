#include <iostream>
#include <vector>
#include "link_list.h"
using namespace std;

int main()
{
    vector<int> vec={1,2,3,4,5,6};
    //cout << "Hello world!" << endl;
    ListNode* head=createList(vec,0);
    traversal(head);

    //插入一个值测试
    addToTail(head,10);
    traversal(head);

    //查找某个值测试
    ListNode* p=find_value(head,10);
    if(p==nullptr)
        std::cout<<"can't find"<<std::endl;
    else
        std::cout<<p->next->value<<std::endl;

    //删除某个值测试
    bool flag=remove_value(head,10);
    if(flag)
    {
        std::cout<<"success!"<<std::endl;
        traversal(head);
    }
    else
    {
        std::cout<<"no such value"<<std::endl;
    }
    return 0;
}
