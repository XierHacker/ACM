# 一.动态规划概念
## 前导技能
- **递归**，
- **暴力搜索**

https://cloud.tencent.com/developer/article/1406947
https://www.jianshu.com/p/56749e928d2b
https://blog.csdn.net/liukcqu/article/details/81545845

https://www.jianshu.com/p/600428224e04
https://blog.csdn.net/zhoubin1992/article/details/45201199
https://blog.csdn.net/ns_code/article/details/20227303
https://www.cnblogs.com/dudududu/p/8567883.html
https://blog.csdn.net/qq_40795475/article/details/89592082
https://www.cnblogs.com/simplepaul/p/7702655.html
https://www.nowcoder.com/discuss/95737


https://blog.csdn.net/charles_r_chiu/article/details/48227281
https://segmentfault.com/a/1190000003745529
https://github.com/huihut/interview#-cc
https://blog.csdn.net/wangruitao1991/article/details/51678815
https://www.cnblogs.com/ALINGMAOMAO/p/9884527.html
https://www.cnblogs.com/daoluanxiaozi/archive/2012/03/29/2423087.html
https://blog.csdn.net/qq508618087/article/details/52694720




## 套路
一般看到**最优**，**最大**，**最小**，**最长**，**计数**这些字眼或者这些类型的题目。要是暴力方法解决不了，
就可以试试动态规划了。

# 二.常见例题/模板

### 例题1(leetcode 121买卖股票的最佳时机)
这道题目的本质就是:给定一个整数数组，找出两个下标，要求：后面下标所指的数减前面下标所指的数之差最大.

首先考虑暴力搜索的方式,我们写一个搜索函数,其中参数index表示在当前index下面最大的差值,所以为了得到最大的差值,我们
每次只需要找index后面最大的值就行,便一定能够得到最大差值.

```c++
int search(int index,std::vector<int>& prices){
    if(index==prices.size())  {return 0;}

    //选择一个最小的买和一个最大的卖,index表示买入时间
    int max=0;
    for(int i=index+1;i<prices.size();i++){
        if(prices[i]>max)  {max=prices[i];}
    }
    int a=max-prices[index]>0?max-prices[index]:0;  //当前差值
    int b=search(index+1,prices);           //下一个的差值
    return std::max(a,b);
}


int maxProfit(std::vector<int>& prices) {
    int result=search(0,prices);
    return result;
}

int main(){
    std::vector<int> input={7,1,5,3,6,4};
    std::cout<<"max_profit:"<<maxProfit(input)<<std::endl;

    return 0;
}
```
然后提交这个结果,用时696ms,内存消耗16.2M.

然后我们可以把这个改为DP形式,具体步骤如下:
```c++
int search(int index,std::vector<int>& prices){
    if(index==prices.size())  {return 0;}

    //选择一个最小的买和一个最大的卖,index表示买入时间
    int max=0;
    for(int i=index+1;i<prices.size();i++){
        if(prices[i]>max)  {max=prices[i];}
    }
    int a=max-prices[index]>0?max-prices[index]:0;  //当前差值
    int b=search(index+1,prices);           //下一个的差值
    return std::max(a,b);
}

int DP(int index,std::vector<int>& prices,std::vector<int>& recorder){
    if(index==prices.size())  {return 0;}

    if(recorder[index]>=0)  {return recorder[index];}   //要是存在,直接返回

    //选择一个最小的买和一个最大的卖,index表示买入时间
    int max=0;
    for(int i=index+1;i<prices.size();i++){
        if(prices[i]>max)  {max=prices[i];}
    }
    int a=max-prices[index]>0?max-prices[index]:0;  //当前差值
    int b=DP(index+1,prices,recorder);           //下一个的差值
    recorder[index]=std::max(a,b);
    return recorder[index];
}


int maxProfit(std::vector<int>& prices) {
    std::vector<int> recorder(prices.size(),-1);
    int result=DP(0,prices,recorder);
    return result;

}

int main(){
    std::vector<int> input={7,1,5,3,6,4};
    std::cout<<"max_profit:"<<maxProfit(input)<<std::endl;

    return 0;
}

```


## 例题2(leetcode 746. 使用最小花费爬楼梯)
数组的每个索引做为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。
您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。

示例 1:
```
输入: cost = [10, 15, 20]
输出: 15
解释: 最低花费是从cost[1]开始，然后走两步即可到阶梯顶，一共花费15。
```
就是从开头走到结尾的时候花费的最小值.因为思想差不多,直接给代码了.其中暴力搜索以及暴力搜索引申出来的DP都给出来了,可以看一下
暴力搜索怎么变成DP形式的.
```c++
int search(int index,const std::vector<int>& cost){
    if(index>=cost.size())  {return 0;}

    //index向下一步或者两步
    int a=cost[index]+search(index+1,cost);
    int b=cost[index]+search(index+2,cost);
    return std::min(a,b);
}

int DP(int index,const std::vector<int>& cost,std::vector<int>& recorder){
    if(index>=cost.size())  {return 0;}
    if(recorder[index]>=0)  {return recorder[index];}

    //index向下一步或者两步
    int a=cost[index]+DP(index+1,cost,recorder);
    int b=cost[index]+DP(index+2,cost,recorder);

    recorder[index]=std::min(a,b);
    return recorder[index];
}


int minCostClimbingStairs(vector<int>& cost) {
    std::vector<int> recoder0(cost.size(),-1);
    std::vector<int> recoder1(cost.size(),-1);

    int min_cost_0=DP(0,cost,recoder0);
    int min_cost_1=DP(1,cost,recoder1);
    int min_cost=(min_cost_0<min_cost_1)?min_cost_0:min_cost_1;
    return min_cost;
}


int main(){
    std::vector<int> input={1,100,1,1,1,100,1,1,100,1};
    //std::cout<<"max_profit:"<<maxProfit(input)<<std::endl;
    std::cout<<"min_cost:"<<minCostClimbingStairs(input)<<std::endl;

    return 0;
}
```

## 例题3(leetcode70 爬楼梯)
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：
```
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
```
思想也都差不多,直接给代码了,如下.
这里需要注意一下,就是非递归方式下面的各种便捷条件的处理.
```c++
int DP(int index,const int& n,std::vector<int>& recorder){
    if(index>=n)    {return 1;}
    if(recorder[index]>=0)  {return recorder[index];}
    int sum=DP(index+1,n,recorder)+DP(index+2,n,recorder);
    recorder[index]=sum;
    return recorder[index];
}

int DP_NOneRecursive(const int& n,std::vector<int>& recorder){
    if(n==0)    {return 0;}
    if(n==1)    {return 1;}
    recorder[n-1]=1;
    recorder[n-2]=2;
    for(int index=n-3;index>=0;index--){
        int sum=recorder[index+1]+recorder[index+2];
        recorder[index]=sum;
    }
    return recorder[0];
}


int climbStairs(int n) {
    std::vector<int> recorder(n,-1);
    int result=DP_NOneRecursive(n,recorder);
    return result;
}

int main(){
    int input=5;
    std::cout<<climbStairs(input)<<std::endl;

    return 0;
}
```

## 例题3(leetcode 198.House Robber)
思考：题目意思很简单，就是相当于一个数组，数组中有数值，你可以从数组中取值，但是两个值不能够是相邻的，怎么取，使得取得的值最多。

这样的题目一开始就想一下是不是可以用暴力来做，发现有太多情况，暴力做不了。于是可以采用暴力搜索的方式来做。

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

在DP这个方法中，只是小小的改变了一点点，就是加入了一个数组，记录下了已经计算过的值，然后就直接返回，就省得计算了。

其实到这里，算是已经完成了一道动态规划的题目了。作为扩展，我们可以去掉递归，就是把递归改为非递归的形式。怎么改呢？
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
int search(int index,const std::vector<int>& nums){
    if(index>=nums.size())  {return 0;}
    int a=nums[index]+search(index+2,nums);
    int b=search(index+1,nums);
    cout<<"a:"<<a<<" "<<"b:"<<b<<" "<<max(a,b)<<endl;
    return std::max(a,b);
}

int DP(int index,const std::vector<int>& nums,std::vector<int>& recorder){
    if(index>=nums.size())  {return 0;}
    if(recorder[index]>=0)  {return recorder[index];}
    int a=nums[index]+DP(index+2,nums,recorder);
    int b=DP(index+1,nums,recorder);
    recorder[index]=std::max(a,b);
    return recorder[index];
}

int DP_NoneRecursive(vector<int>& nums,std::vector<int>& recorder){
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
    //边界条件需要好好判断
    if(nums.empty())    {return 0;}
    if(nums.size()==1)  {return nums[0];}
    //后两个结果记录下来,这是因为我们的写法需要记录后面的结果
    recorder[nums.size()-1]=nums[nums.size()-1];
    recorder[nums.size()-2]=std::max(nums[nums.size()-1],nums[nums.size()-2]);
    
    //照抄递归的转移方程,for的话就要反向遍历了,
    for(int index=nums.size()-3;index>=0;index--){
        int a=nums[index]+recorder[index+2];
        int b=recorder[index+1];
        recorder[index]=std::max(a,b);
    }
    return recorder[0];
}


int rob(vector<int>& nums) {
    std::vector<int> recorder(nums.size(),-1);
//    return DP(0,nums,recorder);
    return DP_NoneRecursive(nums,recorder);
}


int main(){
    std::vector<int> input={183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
    std::cout<<rob(input)<<std::endl;

    return 0;
}

```


到这里，就算是说完了动态规划的基本套路了。但是更多的细节性的东西不能够忽视。下面继续
看常见的动态规划问题。掌握常见的问题怎么设置状态。


## 例题3.(leetcode53 最大子序和)
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:
```asm
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```

动态规划，用dp[i]表示以i结尾的最大子序列和。初始值 dp[0] = nums[0]，然后从第二个数开始遍历

if 当前数加上前一个最大序列和大于当前数，则将当前数加到序列和中，nums[i] + dp[i-1] > nums[i]，则 dp[i] = nums[i] + dp[i-1];
else 以当前数结尾的最大序列和即为当前数本身 dp[i] = nums[i]
然后判断以当前数结尾的最大序列和是否大于最大序列和。

代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();        
        int max = nums[0];
        int dp[size];
        dp[0] = nums[0];
        for (int i = 1; i < size; ++i) {
            if (nums[i] + dp[i-1] >= nums[i]) {
                dp[i] = nums[i] + dp[i-1];
            } else {
                dp[i] = nums[i];                
            }
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }
};
```










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

那么DP的方法也就是在其中加入了一个二维数组，很简单。
```c++
#include <iostream>
#include <vector>
using namespace std;

//暴力搜索
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

//动态规划
int DP(int index,int amount,const vector<int>& coins,vector<vector<int>>& temp)
{
    //首先把暴力搜索的直接抄下来就行。然后改一些条件就行

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

    //要是计算过,因为要直接使用amount,
    if(temp[index][amount]>-1)
    {
        return temp[index][amount];
    }

    //在一个index上面，要么选择，要么不选择,而且可以一直选择。
    //选择这个index
    int a=DP(index,amount-coins[index],coins,temp)+1;
    //不选择这个index
    int b=DP(index+1,amount,coins,temp);
    temp[index][amount]=min(a,b);
    return temp[index][amount];

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

    //暴力搜索
  //  int res=search(0,amount,coins);
 //   if(res<10000000)
   //     cout<<res<<endl;
   // else
   //     cout<<"-1"<<endl;


    //构造出一个存储值的二维数组
    //因为amount是有值的，所以开数组的时候要格外小心
    vector<vector<int>> temp(num,vector<int>(amount+1));
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<amount+1;j++)
        {
            temp[i][j]=-1;
        }
    }

    int res_dp=DP(0,amount,coins,temp);
    if(res_dp<10000000)
        cout<<res_dp<<endl;
    else
        cout<<"-1"<<endl;


    //输出temp 内容
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<amount+1;j++)
        {
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
```
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//暴力搜索
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

//动态规划
int DP(int index,int amount,const vector<int>& coins,vector<vector<int>>& temp)
{
    //首先把暴力搜索的直接抄下来就行。然后改一些条件就行

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

    //要是计算过,因为要直接使用amount,
    if(temp[index][amount]>-1)
    {
        return temp[index][amount];
    }

    //在一个index上面，要么选择，要么不选择,而且可以一直选择。
    //选择这个index
    int a=DP(index,amount-coins[index],coins,temp)+1;
    //不选择这个index
    int b=DP(index+1,amount,coins,temp);
    temp[index][amount]=min(a,b);
    return temp[index][amount];

}

//贪心算法
void greedy(int amount, vector<int> coins)
{
    int result=0;
    //排序一下
    sort(coins.begin(),coins.end());

    for(int i=coins.size()-1;i>=0;i++)
    {
        if(coins[i]<amount)
        {
            result+=(amount/coins[i]);
            amount=amount%coins[i];
        }
    }
    if(amount!=0)
        cout<<"-1"<<endl;
    else
        cout<<result<<endl;
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

    //暴力搜索
    int res=search(0,amount,coins);
    if(res<10000000)
    cout<<res<<endl;
    else
    cout<<"-1"<<endl;


    //构造出一个存储值的二维数组
    //因为amount是有值的，所以开数组的时候要格外小心
    vector<vector<int>> temp(num,vector<int>(amount+1));
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<amount+1;j++)
        {
            temp[i][j]=-1;
        }
    }

    int res_dp=DP(0,amount,coins,temp);
    if(res_dp<10000000)
        cout<<res_dp<<endl;
    else
        cout<<"-1"<<endl;


    //输出temp 内容
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<amount+1;j++)
        {
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }

    //贪心
    greedy(amount,coins);
    return 0;
}
```




## 最长公共子序列
一个给定序列的子序列是在该序列中删去若干元素之后得到的序列。给定两个序列Ｘ和Ｙ，当
一个序列Ｚ既是Ｘ的子序列，又是Ｙ的子序列时，那么叫做Ｚ是Ｘ和Ｙ的公共子序列。

那么最长公共子序列就是子序列中最长的那个子序列.
```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int max_value(int a,int b,int c)
{
    int temp=max(a,b);
    return max(temp,c);
}

//暴力搜索
int search(int index_s1,int index_s2,const string& s1,const string& s2)
{
    //边界条件
    //有一个超出
    if(index_s1>s1.size()||index_s2>s2.size())
    {
        return -1;
    }

    //都刚好取到末尾
    if(index_s1==s1.size()&&index_s2==s2.size())
    {
        return 0;
    }

    //决策条件
    //表示在某个位置刚好匹配，那么两个都往下移一位继续
    int a=0;
    if(s1[index_s1]==s2[index_s2])
        a=search(index_s1+1,index_s2+1,s1,s2)+1;
    //没有找到，尝试一个不变，另一个搜索
    int b=search(index_s1,index_s2+1,s1,s2);
    int c=search(index_s1+1,index_s2,s1,s2);
    return max_value(a,b,c);
}


//动态规划
int DP(int index_s1,int index_s2,const string& s1,const string& s2,vector<vector<int>>& temp)
{
    //边界条件
    //有一个超出
    if(index_s1>s1.size()||index_s2>s2.size())
    {
        return -1;
    }

    //都刚好取到末尾
    if(index_s1==s1.size()&&index_s2==s2.size())
    {
        return 0;
    }

    //要是算过
    if(temp[index_s1][index_s2]>-1)
    {
        return temp[index_s1][index_s2];
    }
    //决策条件
    //表示在某个位置刚好匹配，那么两个都往下移一位继续
    int a=0;
    if(s1[index_s1]==s2[index_s2])
        a=DP(index_s1+1,index_s2+1,s1,s2,temp)+1;
    //没有找到，尝试一个不变，另一个搜索
    int b=DP(index_s1,index_s2+1,s1,s2,temp);
    int c=DP(index_s1+1,index_s2,s1,s2,temp);

    temp[index_s1][index_s2]=max_value(a,b,c);
    return temp[index_s1][index_s2];
   // return max_value(a,b,c);
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    //暴力搜索
    cout<<search(0,0,s1,s2)<<endl;

    //记录矩阵
    vector<vector<int>> temp(s1.size()+1,vector<int>(s2.size()+1,-1));

    //动态规划
    cout<<DP(0,0,s1,s2,temp)<<endl;

    for(int i=0;i<s1.size();i++)
    {
        for(int j=0;j<s2.size();j++)
        {
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
```

## 最长上升子序列
题目描述】

给定N个数，求这N个数的最长上升子序列的长度。

【样例输入】
 
7

2 5 3 4 1 7 6

【样例输出】

4

 

什么是最长上升子序列？ 就是给你一个序列，请你在其中求出一段不断严格上升的部分，它不一定要连续。

就像这样：2,3,4,7和2,3,4,6就是序列2 5 3 4 1 7 6的两种选取方案。最长的长度是4.

![](http://images2015.cnblogs.com/blog/1099135/201707/1099135-20170702205902789-1941127012.png)

```c++
#include<cstdio>
const int MAX=1001;
int a[MAX];
int lis(int x)
{
    int num[MAX];
    for(int i=0;i<x;i++)
    {
        num[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i]&&num[j]+1>num[i])
                   num[i]=num[j]+1;
        }
    }
    int maxx=0;
    for(int i=0;i<x;i++)
        if(maxx<num[i])
            maxx=num[i];
    return maxx;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    return !printf("%d\n",lis(n));
}
```

那么，有没有更快的方法呢？当然有。这回要用到二分。

我们回想一下，在上面O（n2）的程序中，哪些地方看起来比较费时？

没错，就是内层用于更新i的循环。因为每一次他都要查找一遍，效率并不高。

回到题目，我们发现，他只要我们求长度，所以？

我们可以模拟一个栈。

所以每遇到一个比栈顶元素大的数，就放进栈里，遇到比栈顶元素小的就二分查找前边的元素，找到一个“最应该被换掉的元素”，用新数去更新前边的元素。

这个算法不难证明也是正确的。因为前面每一次的枚举都换成了二分，内层的复杂度从n降到了log2，外层不变。所以总的复杂度是O(nlog2n)。

```c++
#include<cstdio>
#include<algorithm>
const int MAXN=200001;

int a[MAXN];
int d[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    d[1]=a[1];
    int len=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>d[len])
            d[++len]=a[i];
        else
        {
            int j=std::lower_bound(d+1,d+len+1,a[i])-d;
            d[j]=a[i]; 
        }
    }
    printf("%d\n",len);    
    return 0;
}
```

## 连续子数组的最大和
 这是一道考的烂的不能再烂的题目，但是依然有很多公司乐于将这样的题目作为笔试或面试题，足见其经典。
 问题是这样的：一个整数数组中的元素有正有负，在该数组中找出一个连续子数组，要求该连续子数组中各元素的和最大，这个连续子数组便被称作最大连续子数组。比如数组{2,4,-7,5,2,-1,2,-4,3}的最大连续子数组为{5,2,-1,2}，最大连续子数组的和为5+2-1+2=8。

代码:
```c++
/* 
最优方法，时间复杂度O（n） 
和最大的子序列的第一个元素肯定是正数 
因为元素有正有负，因此子序列的最大和一定大于0 
*/  
int MaxSubSum3(int *arr,int len)  
{  
    int i;  
    int MaxSum = 0;  
    int CurSum = 0;  
    for(i=0;i<len;i++)  
    {  
        CurSum += arr[i];  
        if(CurSum > MaxSum)  
            MaxSum = CurSum;  
        //如果累加和出现小于0的情况，  
        //则和最大的子序列肯定不可能包含前面的元素，  
        //这时将累加和置0，从下个元素重新开始累加  
        if(CurSum < 0)  
            CurSum = 0;  
    }  
    return MaxSum;  
}  
```


# 三.深度思考