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

## 例题2.小兵向前冲
在nxm的棋盘上面，小兵要从左下角走到右上角，只能够向上或者向右走，问有多少种走法.
```c++
#include <iostream>
#include <vector>
using namespace std;

//暴力搜索，返回走法
int f(int n,int m)
{
    //边界条件
    //没有棋盘
    if(n==0||m==0)
        return 0;

    //条状棋盘
    if(n==1||m==1)
        return 1;

    return f(n-1,m)+f(n,m-1);
}

int main()
{
    int n,m;
    cin>>n>>m;

    cout<<f(n,m)<<endl;
    return 0;
}
```

## 例题3(0-1背包问题)
小偷有一个容量为W的背包，有ｎ件物品，第i个价值为vi,且重wi.
目标就是找到xi使得对于所有`xi={0,1}`,`sum(wi*xi)<=W`,且`sum(xi*vi)`最大

这道题目应该是非常常见的一道题目了。看到了**最大**这个词汇，脑袋里面首先可以联想到是不是可以用动态规划。
```c++
#include <iostream>
#include <vector>

using namespace std;

//暴力搜索(返回最大的重量),S表示已经选好的重量
int search(int index,const vector<int>& v,const vector<int>& w,int W,int S)
{
    //边界条件,表示重量上面已经满足了。
    if(S>=W)
    {
        return 0;
    }
    //边界条件，选到最后一个了，也就不能够继续选择了
    if(index>=v.size())
    {
        return 0;
    }

    //要是选择index这个位置上面的物品的话,那么下一次搜索就是index+1开始,其中Ｓ增加了重量w[index],同时这个价值增加v[index].
    // 至于后面的，就不用管了,这是递归搜索的任务。
    //ａ都表示价值，因为我们函数的目的是为了求价值嘛
    int a=search(index+1,v,w,W,S+w[index])+v[index];


    //要是不选择index这个位置上面物品的话，那就从下一次搜索，什么也不做。
    int b=search(index+1,v,w,W,S);

    //我们的目的，就是得到最大值，所以直接return max就行
    return max(a,b);

}




int main()
{
    int num;
    int weight;
    cin>>num;
    vector<int> v(num);//价值
    vector<int> w(num);//重量

    for(int i=0;i<num;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<num;i++)
    {
        cin>>w[i];
    }
    cin>>weight;

    cout<<search(0,v,w,weight,0);
    return 0;
}
```


## 例题4(leetcode322.Coin Change)
You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
>coins = [1, 2, 5], amount = 11

>return 3 (11 = 5 + 5 + 1)

Example 2:
>coins = [2], amount = 3

>return -1.

题目的意思很简单，就是给了不同面额的硬币，要你凑成一个数。并且硬币数量要最少。
这里看到了**最少**这个字眼了，可以联想到动态规划。

```c++
#include <iostream>
#include <vector>
using namespace std;

int search(int index,int amount,const vector<int>& coins)
{
    //边界条件,amount刚好找零
    if(amount==0)
    {
        return 0;
    }

    //有负数，说明搜索到了不合法状态
    if(amount<0)
    {
        return 10000000;
    }

    if(index>=coins.size())
    {
        return 10000000;
    }
    //在一个index上面，要么选择，要么不选择,而且可以一直选择。
    //选择这个index
    int a=search(index,amount-coins[index],coins)+1;
    //不选择这个index
    int b=search(index+1,amount,coins);
    return min(a,b);
}



int main()
{
    int num;
    int amount;
    cin>>num;
    vector<int> coins(num);
    for(int i=0;i<num;i++)
        cin>>coins[i];
    cin>>amount;
    int res=search(0,amount,coins);
    if(res<10000000)
        cout<<res<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}
```


# 三.深度思考