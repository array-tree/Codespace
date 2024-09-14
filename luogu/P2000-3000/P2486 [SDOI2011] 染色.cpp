#include <bits/stdc++.h>
using namespace std;
const int min_ = -999999999;

int n, m;
int cccv[1500000];
int ycol[1500000];

struct tree
{
    int l, r;
    int cols;    //总共的颜色数量
    int lcol;    //左端点的颜色
    int rcol;    //右端点颜色
    int tag = 0; //颜色修改标记
};
tree t[1500000];
struct node
{
    int col;
    int hson;
    int deep;
    int siz;
    int fa;
    vector<int> son;
    int id;
    int top;
};
int cnt = 0;
node nodes[500000];

void update(int p)
{
    t[p].cols = t[p << 1].cols + t[p << 1 | 1].cols;
    if (t[p << 1].rcol == t[p << 1 | 1].lcol)
    {
        t[p].cols--;
    }
    t[p].lcol = t[p << 1].lcol;
    t[p].rcol = t[p << 1 | 1].rcol;
}
void pushdown(int p)
{
    if (t[p].tag)
    {
        t[p << 1].cols = 1;
        t[p << 1].lcol = t[p].tag;
        t[p << 1].rcol = t[p].tag;
        t[p << 1].tag = t[p].tag;
        t[p << 1 | 1].cols = 1;
        t[p << 1 | 1].lcol = t[p].tag;
        t[p << 1 | 1].rcol = t[p].tag;
        t[p << 1 | 1].tag = t[p].tag;
        t[p].tag = 0;
    }
}
void build(int p, int l, int r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].cols = 1;
        t[p].lcol = ycol[l];
        t[p].rcol = ycol[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    update(p);
}
void change(int p, int l, int r, int delt)
{
    if (l <= t[p].l && r >= t[p].r)
    {
        t[p].cols = 1;
        t[p].lcol = delt;
        t[p].rcol = delt;
        t[p].tag = delt;
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
        return t[p].cols;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    int ans = 0;
    int ccnt = 0;
    if (l <= mid)
    {
        ccnt++;
        ans += query(p << 1, l, r);
    }
    if (r > mid)
    {
        ccnt++;
        ans += query(p << 1 | 1, l, r);
    }
    if (ccnt == 2)
    {
        if (t[p << 1].rcol == t[p << 1 | 1].lcol)
        {
            ans--;
        }
    }
    return ans;
}
int get_col(int x)
{
    int now_ = 1;
    int mid;
    while (1)
    {
        pushdown(now_);
        mid = (t[now_].l + t[now_].r) >> 1;
        if (t[now_].l == x && t[now_].r == x)
        {
            //	cout<<"t[]"<<now_<<"  "<< t[now_].lcol<<"\n";
            return t[now_].lcol;
        }
        if (x <= mid)
        {
            now_ = now_ << 1;
        }
        else
        {
            now_ = now_ << 1 | 1;
        }
    }
}

void build_tree(int x)
{
    nodes[x].deep = nodes[nodes[x].fa].deep + 1;
    nodes[x].siz = 1;

    int to, max_ = min_, wma = 0;
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

void get_top(int x, int top)
{
    nodes[x].top = top;
    nodes[x].id = ++cnt;
    ycol[cnt] = nodes[x].col;
    if (nodes[x].hson == 0)
    {
        return;
    }
    get_top(nodes[x].hson, top);
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

void change_path(int a, int b, int delt)
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

int query_path(int a, int b)
{

    int ans = 0;
    int bef;
    while (nodes[a].top != nodes[b].top)
    {

        if (nodes[nodes[a].top].deep < nodes[nodes[b].top].deep)
        {
            swap(a, b);
        }

        ans += query(1, nodes[nodes[a].top].id, nodes[a].id);

        if (get_col(nodes[nodes[a].top].id) == get_col(nodes[nodes[nodes[a].top].fa].id))
        {
            ans--;
        }
        a = nodes[nodes[a].top].fa;
    }
    ans += query(1, min(nodes[a].id, nodes[b].id), max(nodes[a].id, nodes[b].id));
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int yy = 1; yy <= n; yy++)
    {
        cin >> nodes[yy].col;
    }
    int a, b;
    for (int yy = 1; yy <= n - 1; yy++)
    {
        cin >> a >> b;
        nodes[a].son.push_back(b);
        nodes[b].son.push_back(a);
    }
    build_tree(1);
    get_top(1, 1);
    build(1, 1, cnt);
    char aaa;
    int o, p, q;
    for (int ww = 1; ww <= m; ww++)
    {
        cin >> aaa;
        if (aaa == 'Q')
        {
            cin >> o >> p;
            cout << query_path(o, p) << "\n";
        }
        else
        {
            cin >> o >> p >> q;
            change_path(o, p, q);
        }
    }

    return 0;
}
