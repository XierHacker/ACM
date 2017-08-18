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