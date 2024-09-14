#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int f, t;
};
edge edges[1000000];
int cnt = 1;
struct node
{
    int col;
    bool vis;
    int match;
    vector<int> to;
};
node nodes[1000000];

int n;
bool xyl(int x)
{

    int to;
    for (int ww = 0; ww < nodes[x].to.size(); ww++)
    {
        to = edges[nodes[x].to[ww]].t;
        if (nodes[to].vis)
        {
            continue;
        }
        nodes[to].vis = 1;
        if (nodes[to].match == 0 || xyl(nodes[to].match))
        {
            nodes[to].match = x;
            return 1;
        }
    }
    return 0;
}
// 1-n是人，n+1-3n+1是座位
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int a, b;
    for (int ww = 1; ww <= 2 * n; ww++)
    {
        cin >> a >> b;
        edges[++cnt].f = ww;
        edges[cnt].t = a + 2 * n;
        nodes[ww].to.push_back(cnt);
        edges[++cnt].f = ww;
        edges[cnt].t = a + 3 * n;
        nodes[ww].to.push_back(cnt);
        edges[++cnt].f = ww;
        edges[cnt].t = b + 2 * n;
        nodes[ww].to.push_back(cnt);
        edges[++cnt].f = ww;
        edges[cnt].t = b + 3 * n;
        nodes[ww].to.push_back(cnt);
        // edges[++cnt].f = a + 2 * n;
        // edges[cnt].t = ww;
        // nodes[a + 2 * n].to.push_back(cnt);
    }
    int ans = 0;
    for (int ww = 1; ww <= 2 * n; ww++)
    {
        for (int yy = 1; yy <= 5 * n; yy++)
        {
            nodes[yy].vis = 0;
        }
        if (xyl(ww)) //匈牙利算法
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}