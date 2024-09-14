#include <bits/stdc++.h>
using namespace std;
double ss[1000][1000];
int n, m;
double eps = 0.000000001;
bool gauss()
{
    for (int i = 1; i <= n; i++)
    {
        int r = i;
        for (int k = i; k <= n; k++)
        {
            if (fabs(ss[k][i]) > eps)
            {
                r = k;
                break;
            }
        }
        if (r != i)
        {
            swap(ss[r], ss[i]);
        }
        if (fabs(ss[i][i]) < eps)
        {
            return 0;
        }
        for (int j = n + 1; j >= i; j--)
        {
            ss[i][j] /= ss[i][i];
        }

        for (int k = i + 1; k <= n; k++)
        {
            for (int j = n + 1; j >= i; j--)
            {
                ss[k][j] -= ss[k][i] * ss[i][j];
            }
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ss[i][n + 1] -= ss[i][j] * ss[j][n + 1];
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int ee = 1; ee <= n; ee++)
    {
        for (int ww = 1; ww <= n + 1; ww++)
        {
            cin >> ss[ee][ww];
        }
    }
    bool kk = gauss();
    if (kk == 0)
    {
        cout << "No Solution" << endl;
        return 0;
    }
    else
    {
        for (int yy = 1; yy <= n; yy++)
        {
            printf("%.2lf\n", ss[yy][n + 1]);
        }
    }

    return 0;
}