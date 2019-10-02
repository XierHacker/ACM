#include <iostream>
#include <vector>
#include <algorithm>
#include "find.h"

using namespace std;

int main()
{
    std::vector<int> keys={4,3,5,0,1,2,9,7,12,8,14,30};

    //顺序查找测试
    std::cout<<ordinary_search(8,keys)<<std::endl;

    //二分查找测试
    auto v=keys;
    std::sort(v.begin(),v.end()); //先转为有序
    std::cout<<bi_search(8,v)<<std::endl;
    return 0;
}
