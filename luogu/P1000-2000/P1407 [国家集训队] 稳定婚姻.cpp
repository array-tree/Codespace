#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int f, t;
};
edge edges[60000];
int cnt = 1;
struct node
{
    int col;
    int match;
    vector<int> to;
    bool vis;
};
node nodes[10000];
map<string, int> name_;
int n, m;
void add_eg(int f, int t)
{
    edges[++cnt].f = f;
    edges[cnt].t = t;
    nodes[f].to.push_back(cnt);
}
bool xyl(int x)
{
    int to;
    for (int yy = 0; yy < nodes[x].to.size(); yy++)
    {
        to = edges[nodes[x].to[yy]].t;
        if (nodes[to].vis)
        {
            continue;
        }
        nodes[to].vis = 1;

        if (nodes[to].match == 0 || xyl(nodes[to].match))
        {
            return 1;
        }
    }
    return 0;
}
string man_, wo;
int main()
{
    // freopen("P1407_3.in", "r", stdin);
    // freopen("", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;

    for (int yy = 1; yy <= n; yy++)
    {
        cin >> wo >> man_;
        // swap(wo,man_);
        name_[man_] = yy;
        name_[wo] = yy + n;
    }
    cin >> m;
    for (int ww = 1; ww <= m; ww++)
    {
        cin >> wo >> man_;
        // swap(wo,man_);
        add_eg(name_[man_], name_[wo]);
        // add_eg(name_[wo],name_[man_]);
    }
    for (int ww = 1; ww <= n; ww++)
    {
        nodes[ww].match = ww + n;
    }
    for (int ww = n + 1; ww <= 2 * n; ww++)
    {
        nodes[ww].match = ww - n;
    }
    for (int yy = 1; yy <= n; yy++)
    {
        for (int ww = 1; ww <= 2 * n; ww++)
        {
            nodes[ww].vis = 0;
        }
        nodes[nodes[yy].match].match = 0;
        //    nodes[yy].match = 0;
        if (xyl(yy))
        {
            cout << "Unsafe\n";
        }
        else
        {
            cout << "Safe\n";
        }
        nodes[yy].match = yy + n;
        nodes[yy + n].match = yy;
    }
    return 0;
}