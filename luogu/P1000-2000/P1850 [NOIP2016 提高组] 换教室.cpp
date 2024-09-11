
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1059999999;
int n, m, v, e; // n表示时间段的数量 m表示最多能换多少个教室
struct edge
{
    int f, t;
    int w;
};
edge edges[400000];
struct node
{
    vector<int> to;
    int ano;
    int dis = maxn;
    bool done;
};
node nodes[400000];
int spath[400][400];
void short_path(int a)
{
    spath[a][0] = 1;
    for (int yy = 1; yy <= v; yy++)
    {
        nodes[yy].done = 0;
        nodes[yy].dis = maxn;
    }
    priority_queue<pair<int, int>, vector<pair<int, int> /**/>, greater<pair<int, int> /**/> /**/> q;
    q.push({0, a});
    nodes[a].dis = 0;
    int now_, dis_, to, had_chosen = 0;
    pair<int, int> nn;
    while (!q.empty())
    {
        nn = q.top();
        q.pop();

        now_ = nn.second;
        dis_ = nn.first;
        if (nodes[now_].done == 0)
        {
            had_chosen++;
            nodes[now_].done = 1;
            spath[a][now_] = nodes[now_].dis;
            for (int yy = 0; yy < nodes[now_].to.size(); yy++)
            {
                to = edges[nodes[now_].to[yy]].t;
                if (nodes[to].done == 0)
                {
                    int new_dis = nodes[now_].dis + edges[nodes[now_].to[yy]].w;
                    if (new_dis < nodes[to].dis)
                    {
                        nodes[to].dis = new_dis;
                        q.push({new_dis, to});
                    }
                }
            }
        }
        if (had_chosen == v)
        {
            return;
        }
    }
}
int cla[500000];
int acla[500000]; // another class
double k[500000];
double dp[2400][2400][2];
int main()
{
    //  freopen("classroom.in", "r", stdin);
    //  freopen("classroom.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> v >> e;
    for (int ee = 1; ee <= n; ee++)
    {
        cin >> cla[ee];
    }
    for (int ww = 1; ww <= n; ww++)
    {
        cin >> acla[ww];
    }
    for (int ww = 1; ww <= n; ww++)
    {
        cin >> k[ww];
    }
    int a, b, c;
    for (int ww = 1; ww <= e; ww++)
    {
        cin >> a >> b >> c;
        edges[ww].f = a;
        edges[ww].t = b;
        edges[ww].w = c;
        nodes[a].to.push_back(ww);
        edges[ww + e].f = b;
        edges[ww + e].t = a;
        edges[ww + e].w = c;
        nodes[b].to.push_back(ww + e);
    }
    for (int yy = 1; yy <= v; yy++)
    {
        short_path(yy);
    }
    for (int ss = 0; ss <= n; ss++)
    {
        for (int dd = 0; dd <= m; dd++)
        {
            dp[ss][dd][0] = maxn;
            dp[ss][dd][1] = maxn;
        }
    }
    dp[1][0][0] = 0;
    dp[1][1][1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0][0] = dp[i - 1][0][0] + spath[cla[i - 1]][cla[i]];
        for (int j = 1; j <= min(i, m); j++)
        {
            dp[i][j][0] = min(dp[i - 1][j][0] + spath[cla[i - 1]][cla[i]], dp[i][j][0]);
            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j ][1] + spath[cla[i - 1]][cla[i]] * (1 - k[i - 1]) + spath[acla[i - 1]][cla[i]] * k[i - 1]);
            dp[i][j][1] = min(dp[i - 1][j - 1][0] + spath[cla[i - 1]][acla[i]] * k[i] + spath[cla[i - 1]][cla[i]] * (1 - k[i]), dp[i][j][1]); //上一个不用这一个用成功
            dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][1] + spath[acla[i - 1]][acla[i]] * (k[i] * k[i - 1]) + spath[cla[i - 1]][cla[i]] * (1 - k[i]) * (1 - k[i - 1]) + spath[cla[i - 1]][acla[i]] * (1 - k[i - 1]) * k[i] + spath[acla[i - 1]][cla[i]] * (k[i - 1]) * (1 - k[i]));
         //   cout<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
        }
    }
    double final_ans = maxn;
    for (int yy = 0; yy <= m; yy++)
    {
        final_ans = min(final_ans, dp[n][yy][1]);
        final_ans = min(final_ans, dp[n][yy][0]);
    }
    printf("%.2lf", final_ans);
    return 0;
}