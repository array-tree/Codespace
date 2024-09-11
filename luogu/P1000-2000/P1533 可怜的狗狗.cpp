#include <bits/stdc++.h>
using namespace std;
mt19937 rnd;
int m;

struct node
{
    int l, r;
    int key;
    int val;
    int size;
};
node tr[400000];
struct query
{
    int l, r;
    int k;
    int yuan;
};
query querys[300000];
int ans[300000];
bool cmp(query a, query b)
{
    if (a.l == b.l)
    {
        return a.r < b.r;
    }
    return a.l < b.l;
}
int root, idx, n;
int newnode(int v)
{
    tr[++idx].val = v;
    tr[idx].key = abs(int(rnd()));
    tr[idx].size = 1;
    return idx;
}
void update(int p)
{
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + 1;
}
void split(int p, int v, int &x, int &y)
{
    if (p == 0)
    {
        x = 0;
        y = 0;
        return;
    }
    if (tr[p].val <= v)
    {
        x = p;
        split(tr[x].r, v, tr[x].r, y);
    }
    else
    {
        y = p;
        split(tr[y].l, v, x, tr[y].l);
    }
    update(p);
}
int merge(int x, int y)
{
    if (!x || !y)
    {
        return x + y;
    }
    if (tr[x].key < tr[y].key)
    {
        tr[x].r = merge(tr[x].r, y);
        update(x);
        return x;
    }
    else
    {
        tr[y].l = merge(x, tr[y].l);
        update(y);
        return y;
    }
}
void insert(int v)
{
    int x, y, z;
    split(root, v, x, y);
    z = newnode(v);
    root = merge(merge(x, z), y);
}
void del(int v)
{
    int x, y, z;
    split(root, v, x, z);
    split(x, v - 1, x, y);
    y = merge(tr[y].l, tr[y].r);
    root = merge(merge(x, y), z);
}
int get_k(int p, int k)
{
    if (k <= tr[tr[p].l].size)
    {
        return get_k(tr[p].l, k);
    }
    if (k == tr[tr[p].l].size + 1)
    {
        return p;
    }
    return get_k(tr[p].r, k - tr[tr[p].l].size - 1);
}
int bul[10000];
int main()
{
    freopen("P1533_1.in","r",stdin);
    ios::sync_with_stdio(false);
    srand(time(NULL));
    rnd.seed(rand());
    cin >> n >> m;
    for (int ee = 1; ee <= n; ee++)
    {
        cin >> bul[ee];
    }
    int a, b, c;
    for (int ee = 1; ee <= m; ee++)
    {
        cin >> a >> b >> c;
        querys[ee].l = a;
        querys[ee].r = b;
        querys[ee].k = c;
        querys[ee].yuan=ee;
    }
    sort(querys + 1, querys + 1 + m, cmp);
    for (int ww = 1; ww <= m; ww++)
    {
        a = querys[ww].l;
        b = querys[ww].r;
        if (a <= querys[ww - 1].r)
        {
            for (int ee = querys[ww - 1].l; ee < querys[ww].l; ee++)
            {
                del(bul[ee]);
            }
            for (int ee = querys[ww - 1].r + 1; ee <= querys[ww].r; ee++)
            {
                insert(bul[ee]);
            }
        }
        else
        {
            for (int ee = querys[ww - 1].l; ee <= querys[ww - 1].r; ee++)
            {
                del(bul[ee]);
            }
            for (int ee = querys[ww].l; ee <= querys[ww].r; ee++)
            {
                insert(bul[ee]);
            }
        }
        ans[querys[ww].yuan] = tr[get_k(root, querys[ww].k)].val ;
    }
    for(int yy=1;yy<=m;yy++)
    {
        cout<<ans[yy]<<"\n";
    }
    return 0;
}