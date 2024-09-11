#include <bits/stdc++.h>
using namespace std;
int quan[100][100];
int dp[20][20][20][20];
int n;
int main()
{
    cin >> n;
    int a, b, c;
    while (1)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }
        quan[a][b] = c;
    }
    for (int xx1 = 1; xx1 <= n; xx1++)
    {
        for (int yy1 = 1; yy1 <= n; yy1++)
        {
            for (int xx2 = 1; xx2 <= n; xx2++)
            {
                for (int yy2 = 1; yy2 <= n; yy2++)
                {
                    dp[xx1][yy1][xx2][yy2] = max(max(dp[xx1 - 1][yy1][xx2 - 1][yy2], dp[xx1 - 1][yy1][xx2][yy2 - 1]), max(dp[xx1][yy1 - 1][xx2 - 1][yy2], dp[xx1][yy1 - 1][xx2][yy2 - 1]))+quan[xx1][yy1]+quan[xx2][yy2];
                    if(xx1==xx2&&yy1==yy2)
                    {
                        dp[xx1][yy1][xx2][yy2]-=quan[xx1][yy1];
                    }
                }
            }
        }
    }

    cout<<dp[n][n][n][n];
    return 0;
}