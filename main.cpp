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