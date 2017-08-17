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