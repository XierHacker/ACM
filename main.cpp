#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

//比较函数的写法
int compare(const pair<char,int> &x,const pair<char,int> &y)
{
    if(x.second==y.second)
        return (x.first<y.first);
    else
        return (x.second>y.second);
}

int main()
{
    string s;
    map<char,int> m;
    vector<pair<char,int>> v;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(isalpha(s[i])||isalnum(s[i])||isspace(s[i]))
            //这里注意map的用法
            m[s[i]]++;
    }

    //map中元素转移到vector中
    for(auto it=m.begin();it!=m.end();it++)
    {
        //cout<<it->first<<":"<<it->second<<endl;
        //注意怎么构造pair
        v.push_back(make_pair(it->first,it->second));
    }


    //排序
    sort(v.begin(),v.end(),compare);

    for(auto it=v.begin();it!=v.end();it++)
    {
        cout<<it->first;
    }
    cout<<endl;
    return 0;
}

