#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//int max_value(int a,int b,int c)
//{
//    int temp=max(a,b);
//    return max(temp,c);
//}
//
////暴力搜索
//int search(int index_s1,int index_s2,const string& s1,const string& s2)
//{
//    //边界条件
//    //有一个超出
//    if(index_s1>s1.size()||index_s2>s2.size())
//    {
//        return -1;
//    }
//
//    //都刚好取到末尾
//    if(index_s1==s1.size()&&index_s2==s2.size())
//    {
//        return 0;
//    }
//
//    //决策条件
//    //表示在某个位置刚好匹配，那么两个都往下移一位继续
//    int a=0;
//    if(s1[index_s1]==s2[index_s2])
//        a=search(index_s1+1,index_s2+1,s1,s2)+1;
//    //没有找到，尝试一个不变，另一个搜索
//    int b=search(index_s1,index_s2+1,s1,s2);
//    int c=search(index_s1+1,index_s2,s1,s2);
//    return max_value(a,b,c);
//}
//
//
////动态规划
//int DP(int index_s1,int index_s2,const string& s1,const string& s2,vector<vector<int>>& temp)
//{
//    //边界条件
//    //有一个超出
//    if(index_s1>s1.size()||index_s2>s2.size())
//    {
//        return -1;
//    }
//
//    //都刚好取到末尾
//    if(index_s1==s1.size()&&index_s2==s2.size())
//    {
//        return 0;
//    }
//
//    //要是算过
//    if(temp[index_s1][index_s2]>-1)
//    {
//        return temp[index_s1][index_s2];
//    }
//    //决策条件
//    //表示在某个位置刚好匹配，那么两个都往下移一位继续
//    int a=0;
//    if(s1[index_s1]==s2[index_s2])
//        a=DP(index_s1+1,index_s2+1,s1,s2,temp)+1;
//    //没有找到，尝试一个不变，另一个搜索
//    int b=DP(index_s1,index_s2+1,s1,s2,temp);
//    int c=DP(index_s1+1,index_s2,s1,s2,temp);
//
//    temp[index_s1][index_s2]=max_value(a,b,c);
//    return temp[index_s1][index_s2];
//   // return max_value(a,b,c);
//}
//
//int main()
//{
//    string s1,s2;
//    cin>>s1>>s2;
//    //暴力搜索
//    cout<<search(0,0,s1,s2)<<endl;
//
//    //记录矩阵
//    vector<vector<int>> temp(s1.size()+1,vector<int>(s2.size()+1,-1));
//
//    //动态规划
//    cout<<DP(0,0,s1,s2,temp)<<endl;
//
//    for(int i=0;i<s1.size();i++)
//    {
//        for(int j=0;j<s2.size();j++)
//        {
//            cout<<temp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//
//    return 0;
//}

int search(int index,std::vector<int>& prices){
    if(index==prices.size())  {return 0;}

    //选择一个最小的买和一个最大的卖,index表示买入时间
    int max=0;
    for(int i=index+1;i<prices.size();i++){
        if(prices[i]>max)  {max=prices[i];}
    }
    int a=max-prices[index]>0?max-prices[index]:0;
    int b=search(index+1,prices);
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