
# １.最小公倍数
## 题目描述
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。

## 输入描述:
输入两个正整数A和B。
## 输出描述:
输出A和B的最小公倍数。
## 示例1
输入
>5
>7

输出

>35

思路：简单的暴力解法。也可以用算法。

```c++
#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=(a>b)?b:a;i<=a*b;i++)
    {
     	if((i%a==0)&&(i%b==0))
         {
            cout<<i<<endl;
            break;
        }
    }

	return 0;
}
```

# 2.字符逆序
## 题目描述
将一个字符串str的内容颠倒过来，并输出。str的长度不超过100个字符。 如：输入“I am a student”，输出“tneduts a ma I”。



## 输入参数：
inputString：输入的字符串


## 返回值：
输出转换好的逆序字符串


## 输入描述:
输入一个字符串，可以有空格
## 输出描述:
输出逆序的字符串
## 示例1
输入

>I am a student

输出

>tneduts a ma I

思路：投机取巧，从后面输出就行了。注意带有空格的字符串的接收。

```c++
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    for(int i=s.size()-1;i>=0;i--)
    {
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}
```

# 3.字符统计
## 题目描述
输入一个字符串，对字符中的各个英文字符，数字，空格进行统计（可反复调用）
按照统计个数由多到少输出统计结果，如果统计的个数相同，则按照ASII码由小到大排序输出
清空目前的统计结果，重新统计
调用者会保证：
输入的字符串以‘\0’结尾。


## 输入描述:
输入一串字符。
## 输出描述:
对字符中的各个英文字符（大小写分开统计），数字，空格进行统计，并按照统计个数由多到少输出,如果统计的个数相同，则按照ASII码由小到大排序输出 。如果有其他字符，则对这些字符不用进行统计。
## 示例
输入

>aadddccddc

输出

>dca

思考：这道题目也是很简单的一道题目。
但是其中涉及到了map的使用，map和vector之间的相互存储，map排序，构造pair.
所以这道题目的代码很值得认真消化一下。

```c++
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

```

## 矩阵和数组相关
### 1.顺时针打印矩阵
https://www.cnblogs.com/wanglei5205/p/8617424.html