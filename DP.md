# 一.动态规划概念
## 前导技能
>**递归**，

>**暴力搜索**

## 套路
一般看到**最优**，**最大**，**最小**，**最长**，**计数**这些字眼或者这些类型的题目。要是暴力方法解决不了，
就可以试试动态规划了。

# 二.常见例题/模板
## 例题１(leetcode 198.House Robber)
You are a professional robber planning to rob houses
along a street.

Each house has a certain amount of money stashed, the
only constraint stopping you from robbing each of them
is that **adjacent houses** have security system connected
and it will automatically contact the police
**if two adjacent houses** were broken into on the same night.

Given a list of non-negative integers representing the amount
of money of each house, determine the maximum amount of money
you can rob tonight without alerting the police.


思考：题目意思很简单，就是相当于一个数组，数组中有数值，你可以从数组中取值，
但是两个值不能够是相邻的，怎么取，使得取得的值最多。

这样的题目一开始就想一下是不是可以用暴力来做，发现有太多情况，暴力做不了。
于是可以采用暴力搜索的方式来做。

**第一步：暴力搜索**
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int index,const vector<int>& v)
{
    //我们的策略是从头到尾开始抢
    //先写搜索的边界条件
    //要是抢劫过头了
    if(index>v.size())
    {
        return 0;
    }

    //然后我们在一个index上面有两种决策，抢或者不抢
    //抢的话，你会得到当前的值，然后加上跳过一个位置继续搜索的值。
    int a=v[index]+solve(index+2,v);

    //不抢的话，就放弃当前的值，然后从下一个值开始搜索.
    int b=solve(index+1,v);

    {
        cout<<"a:"<<a<<" "<<"b:"<<b<<" "<<max(a,b)<<endl;
        return max(a,b);
    }

}

int main()
{
    //商店数量
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<solve(0,v)<<endl;
    return 0;
}
```
一般来说，暴力搜索基本上都会超时。可以提交一下看看。
然后再在暴力搜索的基础上面改成DP方法。

**第二步:DP方式**
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int index,const vector<int>& v)
{
    //我们的策略是从头到尾开始抢
    //先写搜索的边界条件
    //要是抢劫过头了
    if(index>v.size())
    {
        return 0;
    }

    //然后我们在一个index上面有两种决策，抢或者不抢
    //抢的话，你会得到当前的值，然后加上跳过一个位置继续搜索的值。
    int a=v[index]+solve(index+2,v);

    //不抢的话，就放弃当前的值，然后从下一个值开始搜索.
    int b=solve(index+1,v);
    {
        cout<<"a:"<<a<<" "<<"b:"<<b<<" "<<max(a,b)<<endl;
        return max(a,b);
    }
}

//假设商店的最大数量不超过100家


int DP(int index,const vector<int>& v, vector<int>& temp)
{
    //我们的策略是从头到尾开始抢
    //先写搜索的边界条件
    //要是抢劫过头了
    if(index>v.size())
    {
        return 0;
    }

    //这里要是算过，就不用多次计算了。直接返回算过的数字
    if(temp[index]>=0)
    {
        return temp[index];
    }

    //然后我们在一个index上面有两种决策，抢或者不抢
    //抢的话，你会得到当前的值，然后加上跳过一个位置继续搜索的值。
    int a=v[index]+DP(index+2,v,temp);

    //不抢的话，就放弃当前的值，然后从下一个值开始搜索.
    int b=DP(index+1,v,temp);

    temp[index]=max(a,b);
    return temp[index];
}



int main()
{
    //商店数量
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<solve(0,v)<<endl;

    //记录数组
    vector<int> temp(n);
    for(int i=0;i<n;i++)
    {
        temp[i]=-1;
    }

    cout<<DP(0,v,temp)<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<temp[i]<<" ";
    }
    return 0;
}
```

在DP这个方法中，只是小小的改变了一点点，就是加入了一个数组，
记录下了已经计算过的值，然后就直接返回，就省得计算了。

其实到这里，算是已经完成了一道动态规划的题目了。作为扩展，我们可以去掉递归，
就是把递归改为非递归的形式。怎么改呢？
上面的代码中有一句打印的话。
```c++
for(int i=0;i<n;i++)
    {
        cout<<temp[i]<<" ";
    }
    return 0;
```
也就是说，我们把DP之后的temp数组状态打印出来了。比如你输入为1 2 3的时候，temp的结果
是4 3 3.也就是说，其实在DP函数最终返回的，就是`temp[0]`,表示我们从最开始(索引为0)抢，
能够得到最大的价值为4.更加有意思的是，`temp[1]`表示从索引为1的位置开始抢，
能够得到的最大价值为3，也就是说，这个数组把所有过程都记录下来了。

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int index,const vector<int>& v)
{
    //我们的策略是从头到尾开始抢
    //先写搜索的边界条件
    //要是抢劫过头了
    if(index>v.size())
    {
        return 0;
    }

    //然后我们在一个index上面有两种决策，抢或者不抢
    //抢的话，你会得到当前的值，然后加上跳过一个位置继续搜索的值。
    int a=v[index]+solve(index+2,v);

    //不抢的话，就放弃当前的值，然后从下一个值开始搜索.
    int b=solve(index+1,v);
    {
        cout<<"a:"<<a<<" "<<"b:"<<b<<" "<<max(a,b)<<endl;
        return max(a,b);
    }
}

//假设商店的最大数量不超过100家


int DP(int index,const vector<int>& v, vector<int>& temp)
{
    //我们的策略是从头到尾开始抢
    //先写搜索的边界条件
    //要是抢劫过头了
    if(index>v.size())
    {
        return 0;
    }

    //这里要是算过，就不用多次计算了。直接返回算过的数字
    if(temp[index]>=0)
    {
        return temp[index];
    }

    //然后我们在一个index上面有两种决策，抢或者不抢
    //抢的话，你会得到当前的值，然后加上跳过一个位置继续搜索的值。
    int a=v[index]+DP(index+2,v,temp);

    //不抢的话，就放弃当前的值，然后从下一个值开始搜索.
    int b=DP(index+1,v,temp);

    temp[index]=max(a,b);
    return temp[index];
}

//非递归版本
int nonRecursion(const vector<int>& v,vector<int>& temp)
{
    //

   /*
    * 首先直接把递归版本的转移方程抄下来，然后把和递归相关的都去掉,变为下面的样子

    int a=v[index]+DP(index+2,v,temp);
    int b=DP(index+1,v,temp);
    temp[index]=max(a,b);

    变为：
    int a=v[index]+temp[index+2]
    int b=temp[index+1]
    temp[index]=max(a,b);

    然后根据需要，在前面加上for循环。比如我这里就需要从初始值size-3往下循环，变为
    for(int index=v.size()-3;index>=0;index--)
    {
        int a=v[index]+temp[index+2]
        int b=temp[index+1]
        temp[index]=max(a,b);
    }

    然后还有一些边界条件
    要是从尾端只有一家，没得选
    temp[v.size()-1]=v[v.size()-1]
    要是从尾端开始，只有两家，选最大的
    temp[v.size()-2]=max(v[v.size()-1],v[v.size()-2])

    */

    //边界
    temp[v.size()-1]=v[v.size()-1];
    temp[v.size()-2]=max(v[v.size()-1],v[v.size()-2]);

    for(int index=v.size()-3;index>=0;index--)
    {
        int a=v[index]+temp[index+2];
        int b=temp[index+1];
        temp[index]=max(a,b);
    }
    return temp[0];
}


int main()
{
    //商店数量
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    //暴力搜索
    cout<<solve(0,v)<<endl;

    //递归的DP
    //记录数组
    vector<int> temp(n);
    for(int i=0;i<n;i++)
    {
        temp[i]=-1;
    }
    cout<<DP(0,v,temp)<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;

    //非递归的DP
    vector<int> temp2(n);
    cout<<nonRecursion(v,temp2)<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<temp2[i]<<" ";
    }

    return 0;
}
```


到这里，就算是说完了动态规划的基本套路了。但是更多的细节性的东西不能够忽视。下面继续
看常见的动态规划问题。掌握常见的问题怎么设置状态。



# 三.深度思考