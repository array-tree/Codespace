#include<bits/stdc++.h>
using namespace std;
int s;
int w[100000];
int yushu(int x)
{
    int ans=0;
    for(int ww=1;ww<x;ww++)
    {
        if(x%ww==0)
        {
            ans+=ww;
        }
    }
    return ans;
}
int dp[1001][1001];
int main()
{
    for(int ww=1;ww<=1000;ww++)
    {
        w[ww]=yushu(ww);
    }
    cin>>s;
    for(int xx=0;xx<=s;xx++)
    {
        for(int yy=1;yy<=s;yy++)
        {
            if(xx>=yy)
            {
                dp[xx][yy]=max(dp[xx][yy],max(dp[xx][yy-1],dp[xx-yy][yy-1]+w[yy]));
            }
            else
            {
                dp[xx][yy]=max(dp[xx][yy],dp[xx][yy-1]);
            }
            
        }
    }
    cout<<dp[s][s];


    return 0;
}