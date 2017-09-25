

/*

#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    //std::vector<double> v {1.0, 2.0, 3.0, 4.0, 5.0, 1.0, 2.0, 3.0, 4.0, 5.0};

   // std::vector<double>::iterator biggest = std::max_element(std::begin(v), std::end(v));
    //std::cout << "Max element is " << *biggest<< " at position " << std::distance(std::begin(v), biggest) << std::endl;

   // auto smallest = std::min_element(std::begin(v), std::end(v));
    //std::cout << "min element is " << *smallest<< " at position " << std::distance(std::begin(v), smallest) << std::endl;
    std::vector<int> v={1,2,3,4,5,6,8,7,0,4};
    std::vector<int>::iterator min_itor=std::min_element(v.begin(),v.end());
    std::cout<<"min value is:"<<*min_itor<<std::endl;

    std::vector<int>::iterator max_itor=std::max_element(v.begin(),v.end());
    std::cout<<"max value is:"<<*max_itor<<std::endl;

    std::swap(*min_itor,*(v.begin()+3));
    for(int i=0;i<v.size();i++)
        std::cout<<v[i]<<" ";
}


*/


#include <iostream>
#include <vector>
#include "sort.h"
using namespace std;

void show(const std::vector<int>& v)
{
    for(int i=0;i<v.size();i++)
        std::cout<<v[i]<<" ";

    std::cout<<std::endl;
}

int main()
{
    //构造出一个vector出来
    vector<int> v={1,2,5,6,4,3,9,11,24,0,8,43,42,22};

    //选择排序测试
    auto v1=select_sort(v);
    show(v1);

    //冒泡排序测试
    auto v2=bubble_sort(v);
    show(v2);

    //快速排序测试
    auto v3=v;
    quick_sort(v3,0,v3.size()-1);
    show(v3);


    return 0;
}




