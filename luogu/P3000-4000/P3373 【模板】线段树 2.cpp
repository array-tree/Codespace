#include <bits/stdc++.h>
using namespace std;
struct tree
{
    long long l, r;
    long long num;
    long long tagj, tagc; // j-加法tag c-乘法tag
};
tree t[400005];
long long n, q, m;
long long aa[1000000];
void startup()
{
    for (long long ww = 0; ww < 400005; ww++)
    {
        t[ww].tagc = 1;
    }
}
void update(long long p)
{
    t[p].num = (t[p * 2].num + t[p * 2 + 1].num) % m;
}
void build(long long p, long long l, long long r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].num = aa[l];
        return;
    }
    long long mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    update(p);
}
void pushdown(long long p)
{
    if (t[p].tagj || t[p].tagc != 1)
    {
        t[p * 2].num = (t[p * 2].num * t[p].tagc + ((t[p * 2].r - t[p * 2].l + 1) * t[p].tagj) % m) % m;
        t[p * 2 + 1].num = (t[p * 2 + 1].num * t[p].tagc + ((t[p * 2 + 1].r - t[p * 2 + 1].l + 1) * t[p].tagj) % m) % m;
        t[p * 2].tagc = (t[p * 2].tagc * t[p].tagc) % m;
        t[p * 2].tagj = ((t[p * 2].tagj * t[p].tagc) % m + t[p].tagj) % m;
        t[p * 2 + 1].tagc = (t[p * 2 + 1].tagc * t[p].tagc) % m;
        t[p * 2 + 1].tagj = ((t[p * 2 + 1].tagj * t[p].tagc) % m + t[p].tagj) % m;
        t[p].tagc = 1;
        t[p].tagj = 0;
    }
}
void changej(long long p, long long l, long long r, long long delt) //加法
{
    if (l <= t[p].l && r >= t[p].r)
    {
        t[p].num = (t[p].num + (t[p].r - t[p].l + 1) * delt) % m;
        t[p].tagj = (t[p].tagj + delt) % m;
        return;
    }
    pushdown(p);
    long long mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
    {
        changej(p * 2, l, r, delt);
    }
    if (r > mid)
    {
        changej(p * 2 + 1, l, r, delt);
    }
    update(p);
}
void changec(long long p, long long l, long long r, long long delt) //乘法
{
    if (l <= t[p].l && r >= t[p].r)
    {
        t[p].num = (t[p].num * delt) % m;
        t[p].tagj = (t[p].tagj * delt) % m;
        t[p].tagc = (t[p].tagc * delt) % m;
        return;
    }
    pushdown(p);
    long long mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
    {
        changec(p * 2, l, r, delt);
    }
    if (r > mid)
    {
        changec(p * 2 + 1, l, r, delt);
    }
    update(p);
}
long long query(long long p, long long l, long long r)
{
    if (l <= t[p].l && r >= t[p].r)
    {
        return t[p].num % m;
    }
    pushdown(p);
    long long ans = 0;
    long long mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
    {
        ans += query(p * 2, l, r);
        ans %= m;
    }
    if (r > mid)
    {
        ans += query(p * 2 + 1, l, r);
        ans %= m;
    }
    ans %= m;
    return ans;
}
signed main()
{
    // freopen("P3373_2.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> q >> m;
    for (long long ww = 1; ww <= n; ww++)
    {
        cin >> aa[ww];
    }
    startup();      //初始化
    build(1, 1, n); //建树
    long long ll, x, y, k;
    for (long long ww = 1; ww <= q; ww++)
    {
        cin >> ll;
        if (ll == 1)
        {
            cin >> x >> y >> k;
            changec(1, x, y, k);
        }
        else if (ll == 2)
        {
            cin >> x >> y >> k;
            changej(1, x, y, k);
        }
        else
        {
            cin >> x >> y;
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}