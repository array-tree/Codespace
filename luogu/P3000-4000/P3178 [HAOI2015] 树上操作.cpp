#include <bits/stdc++.h>
using namespace std;
const int min_ = -999999999;
int n, m, dfn;

long long yuan[1000000];
struct tree
{
    int l, r;
    long long num;
    long long tag;
};
tree t[1900000];
struct node
{
    int top;
    vector<int> son;
    int fa;
    int vis;
    int id;
    int deep;
    int siz;
    long long quan;
    int hson;
};
node nodes[1000000];
void update(int p)
{
    t[p].num = t[p << 1].num + t[p << 1 | 1].num;
}
void pushdown(int p)
{
    if (t[p].tag)
    {
        t[p << 1].num += (t[p << 1].r - t[p << 1].l + 1) * t[p].tag;
        t[p << 1].tag += t[p].tag;
        t[p << 1 | 1].num += (t[p << 1 | 1].r - t[p << 1 | 1].l + 1) * t[p].tag;
        t[p << 1 | 1].tag += t[p].tag;
        t[p].tag = 0;
    }
}
void build(int p, int l, int r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].num = yuan[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    update(p);
}
void change(int p, int l, int r, long long delt)
{
    if (l <= t[p].l && r >= t[p].r)
    {
        t[p].num += (t[p].r - t[p].l + 1) * delt;
        t[p].tag += delt;
        return;
    }
    pushdown(p);
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
long long query(int p, int l, int r)
{
    if (l <= t[p].l && r >= t[p].r)
    {
        return t[p].num;
    }
    long long ans = 0;
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
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

void build_tree(int x)
{
    nodes[x].deep = nodes[nodes[x].fa].deep + 1;
    nodes[x].siz = 1;
    int to, max_ = min_, wma = 0;
    for (int ww = 0; ww < nodes[x].son.size(); ww++)
    {
        to = nodes[x].son[ww];
        if (to != nodes[x].fa)
        {
            nodes[to].fa = x;
            build_tree(to);
            nodes[x].siz += nodes[to].siz;
            if (nodes[to].siz > max_)
            {
                max_ = nodes[to].siz;
                wma = to;
            }
        }
    }
    nodes[x].hson = wma;
}

void get_top(int x, int top)
{
    nodes[x].id = ++dfn;
    yuan[dfn] = nodes[x].quan;
    nodes[x].top = top;
    if (nodes[x].hson == 0)
    {
        return;
    }
    get_top(nodes[x].hson, top);
    int to;
    for (int ww = 0; ww < nodes[x].son.size(); ww++)
    {
        to = nodes[x].son[ww];
        if (to != nodes[x].hson && to != nodes[x].fa)
        {
            get_top(to, to);
        }
    }
}

void change_path(int a, int b, long long delt)
{
    while (nodes[a].top != nodes[b].top)
    {
        if (nodes[nodes[a].top].deep < nodes[nodes[b].top].deep)
        {
            swap(a, b);
        }
        change(1, nodes[nodes[a].top].id, nodes[a].id, delt);
        a = nodes[nodes[a].top].fa;
    }
    change(1, min(nodes[a].id, nodes[b].id), max(nodes[a].id, nodes[b].id), delt);
}

void change_tree(int a, long long delt)
{
    change(1, nodes[a].id, nodes[a].id + nodes[a].siz - 1, delt);
}

long long query_path(int a, int b)
{
    long long ans = 0;
    while (nodes[a].top != nodes[b].top)
    {
        if (nodes[nodes[a].top].deep < nodes[nodes[b].top].deep)
        {
            swap(a, b);
        }
        ans += query(1, nodes[nodes[a].top].id, nodes[a].id);
        a = nodes[nodes[a].top].fa;
        //   cout<<ans<<"\n";
    }
    ans += query(1, min(nodes[a].id, nodes[b].id), max(nodes[a].id, nodes[b].id));
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int ww = 1; ww <= n; ww++)
    {
        cin >> nodes[ww].quan;
    }
    int a, b;
    for (int ww = 1; ww < n; ww++)
    {
        cin >> a >> b;
        nodes[a].son.push_back(b);
        nodes[b].son.push_back(a);
    }
    int c;
    build_tree(1);
    get_top(1, 1);
    build(1, 1, n);
    for (int ww = 1; ww <= m; ww++)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c;
            change_path(b, b, c);
        }
        if (a == 2)
        {
            cin >> b >> c;
            change_tree(b, c);
        }
        if (a == 3)
        {
            cin >> b;
            cout << query_path(b, 1) << "\n";
        }
    }
    return 0;
}