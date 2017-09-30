#include <iostream>
#include <vector>
#include "find.h"

using namespace std;

int main()
{
    std::vector<int> keys={0,1,2,3,4,5,10};

    //顺序查找测试
    std::cout<<ordinary_search(8,keys)<<std::endl;
    //二分查找测试
    std::cout<<bi_search(8,keys)<<std::endl;
    return 0;
}
