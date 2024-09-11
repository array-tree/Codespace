#include <bits/stdc++.h>
using namespace std;
int n, m;
int cost[100000];
int dp[11000][101]; //表示在有i元，前j件物品买空钱包的方案数
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int rr = 1; rr <= n; rr++)
    {
        cin >> cost[rr];
        dp[0][rr]=1;
    }
    dp[0][0]=1;
    for(int ee=1;ee<=m;ee++)
    {
        for(int ww=1;ww<=n;ww++)
        {
            dp[ee][ww]+=dp[ee][ww-1];
            if(ee>=cost[ww])
            {
                dp[ee][ww]+=dp[ee-cost[ww]][ww-1];
            }
        }
    }
    cout<<dp[m][n];
    return 0;
}