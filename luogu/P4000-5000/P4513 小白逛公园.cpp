#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node
{
    int l, r;
    long long maxr, maxl, maxt, sum;
    void clear()
    {
        this->l=0;
        this->r=0;
        this->maxl=0;
        this->maxr=0;
        this->maxt=0;
        this->sum=0;
    }
};
node t[2100000];
int bul[1000000];
void update(int p)
{
    t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
    t[p].maxl = max(t[p << 1].maxl, t[p << 1].sum + t[p << 1 | 1].maxl);
    t[p].maxr = max(t[p << 1].maxr + t[p << 1 | 1].sum, t[p << 1 | 1].maxr);
    t[p].maxt = max(t[p].maxl, t[p].maxr);
    t[p].maxt = max(t[p << 1].maxr + t[p << 1 | 1].maxl, t[p].maxt);
    t[p].maxt = max(t[p].maxt, max(t[p << 1].maxt, t[p << 1 | 1].maxt));
}
void build(int p, int l, int r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].maxl = bul[l];
        t[p].maxr = bul[l];
        t[p].maxt = bul[l];
        t[p].sum = bul[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    update(p);
}
void change(int p, int l, int r, long long delt)
{
    if (l <= t[p].l && r >= t[p].r && l == r)
    {
        t[p].maxl = delt;
        t[p].maxr = delt;
        t[p].maxt = delt;
        t[p].sum = delt;
        return;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
    {
        change(p << 1, l, r, delt);
    }
    if (r > mid)
    {
        change(p << 1 | 1, l, r, delt);
    }
    update(p);
}
node usee;
node query(int p, int l, int r)
{
    //	cout<<p<<endl;
    if (l <= t[p].l && r >= t[p].r)
    {
        return t[p];
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (r <= mid)
    {
        return query(p << 1, l, r);
    }
    else
    {
        if (l > mid)
        {
            return query(p << 1 | 1, l, r);
        }
        else
        {
            node oo, ll, rr;
            oo.clear();
            ll.clear();
            rr.clear();

            ll = query(p << 1, l, r);
            rr = query(p << 1 | 1, l, r);
            
            

            oo.l = l;
            oo.r = r;
            oo.maxl = max(ll.maxl, ll.sum + rr.maxl);
            oo.maxr = max(rr.maxr, rr.sum + ll.maxr);
            oo.maxt = max(max(oo.maxl, oo.maxr), ll.maxr + rr.maxl);
            oo.maxt = max(oo.maxt, max(ll.maxt, rr.maxt));
            
         //   cout<<" oo "<<oo.maxt<<endl;
            return oo;
            
        }
    }
}
int main()
{
    // freopen("P4513_2.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int ww = 1; ww <= n; ww++)
    {
        cin >> bul[ww];
    }
    int k, a, b, c, x;
    build(1, 1, n);
    for (int yy = 1; yy <= m; yy++)
    {
        cin >> k;
        if (k == 1)
        {
            cin >> a >> b;
            if (a > b)
            {
                swap(a, b);
            }
            cout << query(1, a, b).maxt << endl;
        }
        else
        {
            cin >> a >> b;
            change(1, a, a, b);
        }
    }

    return 0;
}
