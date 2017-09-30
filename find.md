# 一.基本概念
# 二.顺序类查找
## Ⅰ.顺序查找
顺序查找就是我们平时最常见到的查找方法,思路很简单,就是从前到后扫描一遍,要是里面有的话,
就返回找到了.要是没有,就返回查找不成功.

代码如下:
```c++
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
```

## Ⅱ.折半查找
折半查找的话,首先是要求线性表是有序的.折半差查找的基本思路是:设`R[low,....,high]`是当前的查找区间,
首选确定该区间的中间位置`mid=(low+high)/2`,然后把待查的`k`与`R[mid]`比较.要是相等的话,那么查找成功.
要是`k<R[mid]`,那么就从mid左半边重新查找;要是`k>R[mid]`,那么就从mid右半边重新查找.一直到找到或者查找失败.
```c++
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
```

# 四.Hash查找