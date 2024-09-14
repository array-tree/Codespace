#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int line[30][30];
int lowbit[1 << 25], dp[1 << 25];
struct pig
{
    double x;
    double y;
};
pig pigs[1000];
double eps = 0.0000001;
void count(double &x, double &y, double a1, double b1, double c1, double a2, double b2, double c2)
{ //解方程
    y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
    x = (c1 - b1 * y) / a1;
}
int change_1(int x, int w)
{
    x |= (1 << (w - 1));
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i < (1 << 19); i++)
    {
        int j = 0;
        i++;
        int kk = -i & i;
        i--;
        while (kk)
        {
            kk >>= 1;
            j++;
        }
        lowbit[i] = j;
    }

    // for (int yy = 0; yy <= 20; yy++)
    // {
    //     cout << lowbit[yy] << " ";
    // }
    cin >> t;

    for (int qq = 1; qq <= t; qq++)
    {
        memset(line, 0, sizeof(line));
        memset(dp, 0x3f, sizeof(dp));
        cin >> n >> m;
        for (int ww = 1; ww <= n; ww++)
        {
            cin >> pigs[ww].x >> pigs[ww].y;
        }
        double a, b;
        for (int i = 1; i <= n; i++)
        {
            line[i][i] = change_1(line[i][i], i);
            for (int j = 1; j <= n; j++)
            {
                if (fabs(pigs[i].x - pigs[j].x) > eps)
                {
                    count(a, b, pigs[i].x * pigs[i].x, pigs[i].x, pigs[i].y, pigs[j].x * pigs[j].x, pigs[j].x, pigs[j].y);
                    if (a >= 0.0000)
                    {
                        continue;
                    }
                    for (int yy = 1; yy <= n; yy++)
                    {
                        if (fabs(a * pigs[yy].x * pigs[yy].x + b * pigs[yy].x - pigs[yy].y) < eps)
                        {
                            line[i][j] = change_1(line[i][j], yy);
                        }
                    }
                }
            }
        }
        dp[0] = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            int kk = lowbit[i];
            dp[change_1(i, kk)] = min(dp[change_1(i, kk)], dp[i] + 1);
            for (int k = 1; k <= n; k++)
            {
                dp[i | line[kk][k]] = min(dp[i | line[kk][k]], dp[i] + 1);
            }
        }
        cout << dp[(1 << n) - 1] << endl;
    }

    return 0;
}