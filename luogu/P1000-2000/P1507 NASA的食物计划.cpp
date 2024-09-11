#include<bits/stdc++.h>
using namespace std;
int h,t;
int n;
int hh[100],tt[100],kk[100];
int dp[51][401][401];
int main()
{
    cin>>h>>t;
    cin>>n;
    for(int ww=1;ww<=n;ww++)
    {
        cin>>hh[ww]>>tt[ww]>>kk[ww];
    }
    for(int hx=0;hx<=h;hx++)
    {
        for(int tx=0;tx<=t;tx++)
        {
            for(int wx=1;wx<=n;wx++)
            {
                if(hx>=hh[wx]&&tx>=tt[wx])
                {
                    dp[wx][hx][tx]=max(dp[wx][hx][tx],max(dp[wx-1][hx][tx],dp[wx-1][hx-hh[wx]][tx-tt[wx]]+kk[wx]));

                }
                else
                {
                    dp[wx][hx][tx]=max(dp[wx][hx][tx],dp[wx-1][hx][tx]);
                }
            }
        }
    }
    cout<<dp[n][h][t];

    return 0;
}