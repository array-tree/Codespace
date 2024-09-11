#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200000];
bool cmp(int a,int b)
{
    return a<b;
}
int max_;
bool check(int x)
{
    int zu=1,be=1;
    for(int ty=2;ty<=n;ty++)
    {
        if(a[ty]-a[be]>=x)
        {
            zu++;
            be=ty;
        }
    }
    return zu>=m;
}
int main()
{
    cin>>n>>m;
    for(int qq=1;qq<=n;qq++)
    {
        cin>>a[qq];
        max_=max(max_,a[qq]);
    }
    sort(a+1,a+1+n,cmp);
    int l=1;
    int r=max_;
    int mid=(l+r+1)/2;
    while(l<r)
    {
        mid=(l+r+1)/2;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }

    cout<<l;
    return 0;
}