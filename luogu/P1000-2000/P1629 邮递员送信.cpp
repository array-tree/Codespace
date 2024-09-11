#include <bits/stdc++.h>
using namespace std;
const int maxn = 1234, maxm = 123456;
long long inf = 0x3f3f3f3f;
int head[maxn << 1], ver[maxm << 1], wei[maxm << 1], nex[maxm << 1], tot, n;
void addedge(int u, int v, int w)
{
    ver[tot] = v;
    wei[tot] = w;
    nex[tot] = head[u];
    head[u] = tot++;
}
struct nodeq
{
    int x;
    long long dis;
    nodeq(int X, long long DIS) : x(X), dis(DIS) {}
    bool operator>(const nodeq &o) const { return dis > o.dis; }
};
priority_queue<nodeq, vector<nodeq>, greater<nodeq> > q;
long long dis[maxn << 1];
void dij(int s)
{
    for (int i = 1; i <= n << 1; ++i)
    {
        dis[i] = inf;
    }
    dis[s] = 0;
    q.push(nodeq(s, 0));
    while (!q.empty())
    {
        nodeq cur = q.top();
        q.pop();
        if (dis[cur.x] < cur.dis)
        {
            continue;
        }
        for (int i = head[cur.x]; ~i; i = nex[i])
        {
            if (dis[ver[i]] > cur.dis + wei[i])
            {
                dis[ver[i]] = cur.dis + wei[i];
                q.push(nodeq(ver[i], dis[ver[i]]));
            }
        }
    }
}
signed main()
{
    memset(head, -1, sizeof(head));
    int m, u, v, w;
    long long ans = 0;
    cin>>n>>m;
    for (int i = 1; i <= m; i++)
    {
       cin>>u>>v>>w;
        addedge(u, v, w);
        addedge(v + n, u + n, w);
    }
    dij(1);
    for (int i=2;i<=n;++i)
    {
        ans+=dis[i];
    }
    dij(1 + n);
    for (int i = 2 + n; i <= n << 1; ++i)
    {
        ans += dis[i];
    }
    cout << ans;
    return 0;
}