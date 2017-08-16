# 一.动态规划概念
前导技能
>**递归**，**暴力搜索**


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





# 三.深度思考