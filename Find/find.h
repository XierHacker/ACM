#ifndef FIND_H_
#define FIND_H_

//顺序查找(返回关键字位置索引,要是没有的话返回-1)
int ordinary_search(int key,std::vector<int>& keys);

//折半查找
int bi_search(int key,std::vector<int>& keys);







#endif // FIND_H_
