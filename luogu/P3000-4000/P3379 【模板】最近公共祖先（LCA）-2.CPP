#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n, m, s;
struct node
{
    vector<int> son;
    int fa;
    int vis;
    vector<pair<int, int> /**/> query;
    int dfn, low;
};
node nodes[100000];
int fa[100000];
int fnd(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    fa[x] = fnd(fa[x]);
    return fa[x];
}
int ans[100000];
void tarjanbuild(int x)
{
    int to;
    nodes[x].vis = 1;
    for (int yy = 0; yy < nodes[x].son.size(); yy++)
    {
        to = nodes[x].son[yy];
        if (to != nodes[x].fa && nodes[to].vis == 0)
        {
            nodes[to].fa = x;
            tarjanbuild(to);
            fa[to] = x;
        }
    }
    for (int ww = 0; ww < nodes[x].query.size(); ww++)
    {
        int num_, nex;
        num_ = nodes[x].query[ww].second;
        nex = nodes[x].query[ww].first;
        if (nodes[nex].vis)
        {
            ans[num_] = fnd(nex);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m >> s;
    int a, b;
    for (int wew = 1; wew <= n; wew++)
    {
        fa[wew] = wew;
    }
    for (int ww = 1; ww < n; ww++)
    {
        cin >> a >> b;
        nodes[a].son.push_back(b);
        nodes[b].son.push_back(a);
    }
    for (int ww = 1; ww <= m; ww++)
    {
        cin >> a >> b;
        nodes[a].query.push_back({b, ww});
        nodes[b].query.push_back({a, ww});
    }
    tarjanbuild(s);
    for (int ww = 1; ww <= m; ww++)
    {
        cout << ans[ww] << "\n";
    }
    return 0;
}