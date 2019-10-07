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
//建堆,完成在数组v上面从v[left]到v[high]的范围内对在位置left上面的节点进行调整
void buildHeap(std::vector<int>& v,int left,int right){
    int i=left;
    int j=left*2;   //说明v[j]是v[i]的左孩子
    int temp=v[i];
    std::cout<<"---v["<<i<<"]:"<<v[i]<<std::endl;
    std::cout<<"---v["<<j<<"]:"<<v[j]<<std::endl;
    std::cout<<"---temp:"<<temp<<std::endl;
    while(j<right)
    {
        //要是右孩子比较大,那么把j指向右孩子(即2*i变为2*i+1)
        if((j<right)&&(v[j]<v[j+1]))    {++j;}  //j变为2*i+1
        if(temp<v[j])
        {
            v[i]=v[j];              //将v[j]调整到父节点
            //修改i和j的值,以方便继续向下调整
            i=j;
            j=2*i;
            std::cout<<"---v["<<i<<"]:"<<v[i]<<std::endl;
            std::cout<<"---v["<<j<<"]:"<<v[j]<<std::endl;
        }
        else
        {
            break;
        }
    }
    v[i]=temp;
}
std::vector<int> heap_sort(std::vector<int>& v)
{
    //auto temp=v;
    std::cout<<v.size()<<std::endl;
    std::cout<<"v[1]'s left child:"<<v[2]<<std::endl;
    std::cout<<"v[2]'s left child:"<<v[4]<<std::endl;

    //建立初始堆
    for(int i=v.size()/2;i>=1;--i)
    {
        std::cout<<"v["<<i<<"]:"<<v[i]<<std::endl;
        buildHeap(v,i,v.size()-1);
    }

    //进行n-1次循环,完成堆排序
    for(int i=v.size()-1;i>=2;--i){
        std::swap(v[1],v[i]);
        buildHeap(v,1,i-1);
    }

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
    //边界条件
    if(left>=right) {return ;}

    int temp;
    int i=left,j=right;
    temp=v[left];
    while(i<j)
    {
        while((i<j)&&(v[j]>=temp))   {--j;}   //从右边往左边扫描找到一个小于temp的元素
        if(i<j)         //这里很重要的一点就是随时保证i<j这个大小关系
        {
            v[i]=v[j];      //把v[j]放到左边去了
            ++i;
        }
        while((i<j)&&(v[i]<temp))   {++i;}   //从左边往右边扫描找到一个大于temp的元素
        if(i<j)          //这里很重要的一点就是随时保证i<j这个大小关系
        {
            v[j]=v[i];      //把v[i]放到右边去了
            --j;
        }
    }

    //这个时候i==j,跳出循环,并且把temp放在最终位置
    v[i]=temp;
    quick_sort(v,left,i-1);     //递归对temp左边的元素进行排序
    quick_sort(v,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    i+1,right);    //递归对temp右边元素进行排序
}


/*插入类排序*/
//直接插入排序,返回一个拍好序的序列
std::vector<int> insert_sort(const std::vector<int>& v)
{
    std::vector<int> temp=v;
    int storage; //暂存元素
    //从第二个元素开始,因为第一个元素是有序的
    for(int i=1;i<temp.size();i++)
    {
        storage=temp[i];
        int j=i-1;
        //在前面"有序"的部分移动元素(为了插入)
        while(j>=0&&storage<temp[j])
        {
            temp[j+1]=temp[j];
            --j;
        }
        //把存的数放到应该的位置(插入)
        temp[j+1]=storage;
    }
    return temp;
}






