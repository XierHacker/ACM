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

//int search(int index,const std::vector<int>& cost){
//    if(index>=cost.size())  {return 0;}
//
//    //index向下一步或者两步
//    int a=cost[index]+search(index+1,cost);
//    int b=cost[index]+search(index+2,cost);
//    return std::min(a,b);
//}
//

//int DP(int index,const int& n,std::vector<int>& recorder){
//    if(index>=n)    {return 1;}
//    if(recorder[index]>=0)  {return recorder[index];}
//    int sum=DP(index+1,n,recorder)+DP(index+2,n,recorder);
//    recorder[index]=sum;
//    return recorder[index];
//}
//
//int DP_NOneRecursive(const int& n,std::vector<int>& recorder){
//    if(n==0)    {return 0;}
//    if(n==1)    {return 1;}
//    recorder[n-1]=1;
//    recorder[n-2]=2;
//    for(int index=n-3;index>=0;index--){
//        int sum=recorder[index+1]+recorder[index+2];
//        recorder[index]=sum;
//    }
//    return recorder[0];
//}

//int DP(int index1,int index2,const vector<int>& nums,std::vector<std::vector<int>>& recorder){
//    if((index1>=nums.size())||(index2>=nums.size()))    {return 0;}
//    int sum=0;
//    for(int i=index1;i<=index2;i++)
//    {
//        if(index1==index2){
//            sum=nums[index1];
//            break;
//        }
//        sum+=nums[i];
//    }
//    int a=DP(index1,index2+1,nums,recorder);
//    int b=DP(index1+1,index2+1,nums,recorder);
//}

//int DP(int index,const vector<int>& nums,std::vector<int>& recorder){
//    if(index>=nums.size())  {return 0;}
//    if(recorder[index]>=0)  {return recorder[index];}
//    recorder[index]=std::max(nums[index],DP(index+1,nums,recorder));
//    return recorder[index];
//}
//
//
//int maxSubArray(vector<int>& nums) {
//    std::vector<int> recorder(nums.size(),-1);
//    return DP(5,nums,recorder);
//
//
//}

static std::vector<int> path(20,-1);

void search(int index,vector<int>& nums){
    if(index>=nums.size())  {return ;}
    for(int i=0;i<nums.size();++i)
    {
        path[index]=i;
        //print path
//        for(int j=0;j<path.size();j++)
//        {
//            std::cout<<path[j]<<" ";
//        }
        std::cout<<std::endl;
        search(index+1,nums);
    }

}


vector<vector<int>> permute(vector<int>& nums) {
    search(0,nums);



}



int main(){
    std::vector<int> input={1,2,3};
    permute(input);
    return 0;
}