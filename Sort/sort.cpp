#include <iostream>
#include <vector>
#include <algorithm>
#include "sort.h"

//简单选择排序法
std::vector<int> select_sort(const std::vector<int>& v)
{
    auto temp=v;
    for(int i=0;i<temp.size();i++)
    {
        //找无序中的最小值
        std::vector<int>::iterator min_itor=std::min_element(temp.begin()+i,temp.end());

        //把最小值与无序部分第一个元素(就是i索引的元素)交换
        std::swap(*min_itor,*(temp.begin()+i));
    }
    return temp;
}

