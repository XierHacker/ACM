#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*bool ascent(int x,int y)
{
    return x<y;
}*/
/*
bool descent(int x,int y)
{
    return x>y;
}*/
int main()
{
    int num;
    int kind;
    cin>>num;
    vector<int> v(num);
    for(int i=0;i<num;i++)
        cin>>v[i];

    cin>>kind;
    sort(v.begin(),v.end());
    if(kind==0)
    {
        for(int i=0;i<num-1;i++)
            cout<<v[i]<<" ";
        cout<<v[num-1]<<endl;
    }

    else
    {
        for(int i=v.size()-1;i>0;i--)
            cout<<v[i]<<" ";
        cout<<v[0]<<endl;
    }
    return 0;
}