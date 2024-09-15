#include <bits/stdc++.h>
using namespace std;
// #define long long long long
long long num[1009000];
struct tree
{
    long long ops;
    long long num;
    long long sum;
    long long l, r;
};
tree t[2000000];
void update(long long p)
{
    t[p].ops = max(t[p << 1].ops, t[p << 1 | 1].ops);
    t[p].num = t[p << 1].num + t[p << 1 | 1].num;
}
void build(long long p, long long l, long long r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].num = num[l];
        t[p].ops = num[l];
        return;
    }
    long long mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    update(p);
    return;
}
void change(long long p, long long l, long long r)
{

    if (t[p].l == t[p].r)
    {
        t[p].num = sqrt(t[p].num);
        t[p].ops = sqrt(t[p].ops);
        return;
    }
    long long mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid && t[p << 1].ops > 1)
    {
        change(p << 1, l, r);
    }
    if (r > mid && t[p << 1 | 1].ops > 1)
    {
        change(p << 1 | 1, l, r);
    }
    update(p);
}
long long query(long long p, long long l, long long r)
{
    if (l <= t[p].l && r >= t[p].r)
    {
        return t[p].num;
    }
    long long mid = (t[p].l + t[p].r) >> 1;
    long long ans = 0;
    if (l <= mid)
    {
        ans += query(p << 1, l, r);
    }
    if (r > mid)
    {
        ans += query(p << 1 | 1, l, r);
    }
    return ans;
}
long long n, m;
signed main()
{
    // freopen("P4145_3.in","r",stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (long long ew = 1; ew <= n; ew++)
    {
        cin >> num[ew];
    }
    build(1, 1, n);
    long long k, aa, bb;
    cin >> m;
    for (long long qq = 1; qq <= m; qq++)
    {
        cin >> k >> aa >> bb;
        if (k == 1)
        {
            cout << query(1, min(aa, bb), max(aa, bb)) << endl;
        }
        else
        {
            change(1, min(aa, bb), max(aa, bb));
        }
    }
    return 0;
}