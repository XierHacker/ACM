#include <iostream>
#include <vector>
#include <algorithm>
#include "sort.h"

//��ѡ������
std::vector<int> select_sort(const std::vector<int>& v)
{
    auto temp=v;
    for(int i=0;i<temp.size();i++)
    {
        //�������е���Сֵ
        std::vector<int>::iterator min_itor=std::min_element(temp.begin()+i,temp.end());

        //����Сֵ�����򲿷ֵ�һ��Ԫ��(����i������Ԫ��)����
        std::swap(*min_itor,*(temp.begin()+i));
    }
    return temp;
}

