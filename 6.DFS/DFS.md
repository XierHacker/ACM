# leetcode高频题
## 树相关

#






## 数学相关(排列,组合,子集等等)
下面首先通过三道题目来讲一下深度优先搜索的框架,然后再根据这个框架进行深度优先搜索的实战.这三道题目分别表示三类问题:
- **排列**
- **组合**
- **子集**

### 排列问题

**例题1(leetcode 46.全排列)**

给定一个没有重复数字的序列，返回其所有可能的全排列。

输入:
```
[1,2,3]
```

输出:
```asm
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

下面的代码就是进行全排列的一般框架了
```c++
static std::vector<int> path(20,-1);
static std::vector<bool> visited(20,false);     //用来判断重复

void search(int index,vector<int>& nums,std::vector<std::vector<int>>& result){
    //到达边界，开始记录路径结果
    if(index>=nums.size())
    {
        //把路径下标转换为vector中的内容
        std::vector<int> temp;
        for(int j=0;j<nums.size();j++)
            temp.push_back(nums[path[j]]);
        result.push_back(temp);
        return ;
    }
    for(int i=0;i<nums.size();++i)
    {
        if(visited[i]==false)
        {
            path[index]=i;
            visited[i]=true;
//        for(int i=0;i<path.size();i++) {
//            std::cout << path[i] << " ";
//        }
//        std::cout<<std::endl;
            search(index+1,nums,result);
            visited[i]=false;           //因为是全局变量,记得重置为false
        }

    }
}


vector<vector<int>> permute(vector<int>& nums) {
    static std::vector<std::vector<int>> result;
    search(0,nums,result);
    return result;
}

int main(){
    std::vector<int> input={1,2,3};
    vector<vector<int>> result=permute(input);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++)
        {
            std::cout<<result[i][j]<<" ";
        }
        std::cout<<std::endl;
    }


    return 0;
}


```
出来的结果为：
```asm
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1
```

也就是注意对于框架的理解，同时还要注意下标是否访问过的状态的设置和重置。

同时，这个题目可以演变出非常多的题目，一般在终止条件的地方写上相应的逻辑就行。



### 组合问题

**例题2(leetcode 77.组合)**
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

输入: 
```asm
n = 4, k = 2
```

输出:
```asm
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

代码如下：
```c++
static std::vector<int> path(20,-1);
static std::vector<bool> visited(20,false);

void search(int index,int n,int k,int K,std::vector<std::vector<int>>& result){
    if(k<=0)
    {
        //把路径下标转换为vector中的内容
        std::vector<int> temp;
        for(int j=0;j<K;j++)
            temp.push_back(path[j]);
        result.push_back(temp);
        return ;
    }
    for(int i=index+1;i<=n;++i)
    {
        path[k-1]=i;
        search(i,n,k-1,K,result);
    }

}


vector<vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> result;
    search(0,n,k,k,result);
    return result;
}

int main(){
    vector<vector<int>> result=combine(4,2);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++)
        {
            std::cout<<result[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}

```

要是这里不是告诉你n，而是给定一个数组的k个数字的组合呢？也很简单，记录下标了在转回去就行。

整个代码如下
```
static std::vector<int> path(20,-1);
static std::vector<bool> visited(20,false);

void search(int index,std::vector<int>& nums,int k,int K,std::vector<std::vector<int>>& result){
    if(k<=0)
    {
        //把路径下标转换为vector中的内容
        std::vector<int> temp;
        for(int j=0;j<K;j++)
            temp.push_back(nums[path[j]]);
        result.push_back(temp);
        return ;
    }
    for(int i=index+1;i<nums.size();++i)
    {
        path[k-1]=i;
        search(i,nums,k-1,K,result);
    }

}


vector<vector<int>> combine(std::vector<int>& nums, int k) {
    std::vector<std::vector<int>> result;
    search(-1,nums,k,k,result);
    return result;
}



int main(){
    std::vector<int> input={1,2,3,4,5,6,7,8,9};
    vector<vector<int>> result=combine(input,2);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++)
        {
            std::cout<<result[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
```


###　子集
例题(leetcode 78.子集)
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:
```asm
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```


代码如下：
```c++
static std::vector<int> path(20,-1);
static std::vector<bool> visited(20,false);

void search(int index,std::vector<int>& nums,std::vector<std::vector<int>>& result){
    if(index>=nums.size())
    {
        std::vector<int> temp;
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]) {
                //std::cout<<nums[i]<<" ";
                temp.push_back(nums[i]);
            }
        }
        result.push_back(temp);
        return ;
    }
    visited[index]=true;
    search(index+1,nums,result);
    visited[index]=false;
    search(index+1,nums,result);
}


vector<vector<int>> subsets(vector<int>& nums) {
    std::vector<std::vector<int>> result;
    search(0,nums, result);
    return result;

}

int main(){
    std::vector<int> input={1,2,3,4,5,6,7,8,9};
    vector<vector<int>> result=subsets(input);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            std::cout<<result[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}

```

