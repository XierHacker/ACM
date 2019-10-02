#include <iostream>
#include <vector>
#include "find.h"


//顺序查找(返回关键字位置索引,要是没有的话返回-1)
int ordinary_search(int key,std::vector<int>& keys)
{
    for(int i=0;i<keys.size();i++)
    {
        if(keys[i]==key)
        {
            return i;
        }
    }
    //查找不成功
    return -1;
}

//折半查找
int bi_search(int key,std::vector<int>& keys)
{
    int low=0;
    int high=keys.size()-1;
    while(low<=high)
    {
        //中间位置
        int mid=(low+high)/2;

        if(key==keys[mid])        //查找成功
        {
            return mid;
        }
        else if(key<keys[mid])   //key在左边位置
        {
            high=mid-1;
        }
        else                    //key在右边位置
        {
            low=mid+1;
        }
    }
    return -1;
}
