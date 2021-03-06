#ifndef SORT_H_
#define SORT_H_

#include <iostream>

//选择排序
std::vector<int> select_sort(const std::vector<int>& v);

//堆排序
//建堆,完成在数组v上面从v[left]到v[high]的范围内对在位置left上面的节点进行调整
void buildHeap(std::vector<int>& v,int left,int right);
std::vector<int> heap_sort(std::vector<int>& v);

//冒泡排序
std::vector<int> bubble_sort(const std::vector<int>& v);

//快速排序
void quick_sort(std::vector<int>& v,int left,int right); //对从v[left]到v[right]的元素进行排序

//直接插入排序,返回一个拍好序的序列
std::vector<int> insert_sort(const std::vector<int>& v);

#endif // SORT_H_

