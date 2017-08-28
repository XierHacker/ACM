#include <iostream>
#include <vector>
#include "link_list.h"
using namespace std;

int main()
{
    vector<int> vec={1,2,3,4,5,6};
    //cout << "Hello world!" << endl;
    ListNode* head=createList(vec,1);
    traversal(head);
    return 0;
}
