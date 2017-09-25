#include <iostream>
#include <vector>
#include <algorithm>
#include "sort.h"

/*选择类排序
    1.简单选择排序
    2.堆排序
*/
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


//堆排序
//建堆
void buildHeap()
{

}
std::vector<int> heap_sort(const std::vector<int>& v)
{
    auto temp=v;
}



/*交换类排序
    1.冒泡排序
    2.快速排序

*/

//冒泡排序
std::vector<int> bubble_sort(const std::vector<int>& v)
{
    auto temp=v;
    int flag; //用来标识是否发生了交换
    for(int i=temp.size()-1;i>1;i--)
    {
        flag=0;
        //从前到后比较
        for(int j=0;j<i;j++)
        {
            if(temp[j]>temp[j+1])
            {
                //交换元素
                std::swap(temp[j],temp[j+1]);
                flag=1;
            }
        }
        //要是一次都没有交换
        if(flag==0)
            return temp;
    }
}

//快速排序
void quick_sort(std::vector<int>& v,int left,int right) //对从v[left]到v[right]的元素进行排序
{
    int temp;
    int i=left,j=right;

    //边界条件
    if(left>=right)
        return ;
    else
    {
        temp=v[left];
        while(i!=j)
        {
            //从右边往左边扫描找到一个小于temp的元素
            //这里很重要的一点就是随时保证i<j这个大小关系
            while((i<j)&&(v[j]>temp))
                --j;

            if(i<j)
            {
                //把v[j]放到左边去了
                v[i]=v[j];
                ++i;
            }

            //从左边往右边扫描找到一个大于temp的元素
            //这里很重要的一点就是随时保证i<j这个大小关系
            while((i<j)&&(v[i]<temp))
                ++i;

            if(i<j)
            {
                //把v[i]放到右边去了
                v[j]=v[i];
                --j;
            }
        }

        //这个时候i==j,跳出循环,并且把temp放在最终位置
        v[i]=temp;
        quick_sort(v,left,i-1);     //递归对temp左边的元素进行排序
        quick_sort(v,i+1,right);    //递归对temp右边元素进行排序
    }
}



