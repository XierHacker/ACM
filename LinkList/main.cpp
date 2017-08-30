#include <iostream>
#include <vector>
#include "link_list.h"
using namespace std;

int main()
{
    //�����������
    vector<int> vec={1,2,3,4,5,6};
    //cout << "Hello world!" << endl;
    ListNode* head=createList(vec,0);
    traversal(head);

    //����һ��ֵ����
    addToTail(head,10);
    traversal(head);

    //����ĳ��ֵ����
    ListNode* p=find_value(head,10);
    if(p==nullptr)
        std::cout<<"can't find"<<std::endl;
    else
        std::cout<<p->next->value<<std::endl;

    //ɾ��ĳ��ֵ����
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

    //�����������
    reverse_traversal(head);

    //������k���ڵ����
    std::cout<<re_k_th_node(head,3)->value<<std::endl;

    //�ַ�����ת����
    ListNode* newHead=reverseList(head);
    traversal(newHead);


    //�����������
    vector<int> vec1={1,3,5,6,9};
    vector<int> vec2={2,4,5,6};

    ListNode* head1=createList(vec1,0);
    ListNode* head2=createList(vec2,0);

    ListNode* mergedHead=mergeList(head1,head2);
    traversal(mergedHead);

    return 0;
}
