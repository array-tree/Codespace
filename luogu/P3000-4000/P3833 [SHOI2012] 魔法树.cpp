#include <bits/stdc++.h>
using namespace std;
const long long min_ = -99999999999;
int n, m;
struct tree
{
    int l, r;
    long long sum = 0;
    long long tag = 0;
};
tree t[1000000];
struct node
{
    int top;
    int hson;
    int fa;
    int siz;
    int deep;
    int id; //映射后的新权值
    vector<int> son;
};
node nodes[1000000];
int cnt = 0; // dfn序
long long nw[1000000];

void update(int p)
{
    t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}
void build(int p, int l, int r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    update(p);
}
void pushdown(int p)
{
    if (t[p].tag)
    {
        t[p << 1].sum += (t[p << 1].r - t[p << 1].l + 1) * t[p].tag;
        t[p << 1].tag += t[p].tag;
        t[p << 1 | 1].sum += (t[p << 1 | 1].r - t[p << 1 | 1].l + 1) * t[p].tag;
        t[p << 1 | 1].tag += t[p].tag;
        t[p].tag = 0;
    }
}
void change(int p, int l, int r, long long  delt)
{
    if (l <= t[p].l && r >= t[p].r)
    {
        t[p].sum += (t[p].r - t[p].l + 1) * delt;
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
    return;
}
long long query(int p, int l, int r)
{
    if (l <= t[p].l && r >= t[p].r)
    {
        return t[p].sum;
    }
    pushdown(p);
    long long sum = 0;
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
    {
        sum += query(p << 1, l, r);
    }
    if (r > mid)
    {
        sum += query(p << 1 | 1, l, r);
    }
    return sum;
}

void build_tree(int x)
{
    nodes[x].deep = nodes[nodes[x].fa].deep+1;
    nodes[x].siz = 1;
    long long to, max_ = min_, wma = 0;
    for (int yy = 0; yy < nodes[x].son.size(); yy++)
    {
        to = nodes[x].son[yy];
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
void get_top(int x, int top_)
{
    cnt++;
    nodes[x].id = cnt;
    nodes[x].top = top_;
    if (nodes[x].hson == 0)
    {
        return;
    }
    get_top(nodes[x].hson, top_);
    int to;
    for (int yy = 0; yy < nodes[x].son.size(); yy++)
    {
        to = nodes[x].son[yy];
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

long long query_tree(int p)
{
    return query(1, nodes[p].id, nodes[p].id + nodes[p].siz - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int a, b;
    for (int rr = 1; rr < n; rr++)
    {
        cin >> a >> b;
        a++;
        b++;
        nodes[a].son.push_back(b);
        nodes[b].fa = a;
    }

    build_tree(1);
    get_top(1, 1);
    build(1, 1, n);
    nodes[1].fa = 1;
    cin >> m;
    char kk;
    int o, p, q;
    for (int ww = 1; ww <= m; ww++)
    {
        cin >> kk;
        if (kk == 'A')
        {
            cin >> o >> p >> q;
            o++;
            p++;

            change_path(o, p, q);
        }
        else
        {
            cin >> o;
            o++;
            cout << query_tree(o) << "\n";
        }
    }
    return 0;
}
//小小树剖板子题
