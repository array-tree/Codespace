#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int f, t;
    int c;
};
edge edges[1000000];
int cnt = 1;
struct node
{
    int mf;
    int col;
    int vis;
    vector<int> to;
    int pre;
};
node nodes[100000];
//声明定义0 为超级源点 1-p 为房间 p+1~p+n为客人
// p+n+1~p+2n为限流点 p+2n+1~p+2n+q为菜 p+2n+q+1为汇流点
int n, p, q;
int s = 0, t = p + n + n + q + 1; //源点和汇点
bool bfs()
{
    for (int yy = 0; yy <= p + n + n + q + 1; yy++)
    {
        nodes[yy].mf = 0;
    }
    queue<int> qu;
    qu.push(0);
    nodes[0].mf = 1e9;
    while (!qu.empty())
    {
        int now_ = qu.front();
        qu.pop();
        int to, edg;
        for (int rr = 0; rr < nodes[now_].to.size(); rr++)
        {
            edg = nodes[now_].to[rr];
            to = edges[edg].t;
            if (nodes[to].mf == 0 && edges[edg].c)
            {
                nodes[to].mf = min(nodes[now_].mf, edges[edg].c);
                nodes[to].pre = edg;
                qu.push(to);
                if (to == t)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
long long e_k()
{
    long long tot_f = 0;
    while (bfs())
    {
        //   cout<<nodes[t].mf<<endl;
        int now_ = t;
        while (now_ != s)
        {
            int edg = nodes[now_].pre;
            edges[edg].c -= nodes[t].mf;
            edges[edg ^ 1].c += nodes[t].mf;
            now_ = edges[edg ^ 1].t;
        }
        tot_f += nodes[t].mf;
    }
    return tot_f;
}
void add_eg(int f,int t,int c)
{
    edges[++cnt].f=f;
    edges[cnt].t=t;
    edges[cnt].c=c;
    nodes[f].to.push_back(cnt);
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> p >> q;
    t=p+n+n+q+1; 
    int aa;
    for (int ww = 1; ww <= n; ww++) //建立房间与人之间的链接
    {
        for (int pp = 1; pp <= p; pp++)
        {
            cin >> aa;
            if (aa == 1)
            {
                add_eg(pp,p+ww,1);
                add_eg(p+ww,pp,0);
                // edges[++cnt].f = pp;
                // edges[cnt].t = p + ww;
                // edges[cnt].c = 1;
                // nodes[pp].to.push_back(cnt);
                // edges[++cnt].f = p + ww;
                // edges[cnt].t = pp;
                // edges[cnt].c = 0;
                // nodes[p + ww].to.push_back(cnt);
            }
        }
    }

    for (int ww = 1; ww <= n; ww++)
    {
        for (int qq = 1; qq <= q; qq++)
        {
            cin >> aa;
            if (aa == 1)
            {
                add_eg(p+n+ww,p+n+n+qq,1);
                add_eg(p+n+n+qq,p+n+ww,0);
                // edges[++cnt].f = p + n + ww;
                // edges[cnt].t = p + n + n + qq;
                // edges[cnt].c = 1;
                // nodes[p + n + ww].to.push_back(cnt);
                // edges[++cnt].f = p + n + n + qq;
                // edges[cnt].t = p + n + ww;
                // edges[cnt].c = 0;
                // nodes[p + n + n + qq].to.push_back(cnt);
            }
        }
    }
    for (int yy = 1; yy <= n; yy++)
    {
        add_eg(p+yy,p+n+yy,1);
        add_eg(p+n+yy,p+yy,0);
        // edges[++cnt].t = p + n + yy;
        // edges[cnt].f = p + yy;
        // edges[cnt].c = 1; //一个人只能占一个房间并吃一碗菜
        // nodes[p + yy].to.push_back(cnt);
        // edges[++cnt].f = p + n + yy;
        // edges[cnt].t = p + yy;
        // edges[cnt].c = 0;
        // nodes[p + n + yy].to.push_back(cnt);
    }
    for (int ww = 1; ww <= p; ww++)
    {
        add_eg(0,ww,1);
        add_eg(ww,0,0);
        // edges[++cnt].c = 1;
        // edges[cnt].f = 0;
        // edges[cnt].t = ww;
        // nodes[0].to.push_back(cnt);
        // edges[++cnt].c = 0;
        // edges[cnt].f = ww;
        // edges[cnt].t = 0;
        // nodes[ww].to.push_back(cnt);
    }
    for (int ww = 1; ww <= q; ww++)
    {
        add_eg(p+n+n+ww,p+n+n+q+1,1);
        add_eg(p+n+n+q+1,p+n+n+ww,0);
        // edges[++cnt].f = p + 2 * n + ww;
        // edges[cnt].t = p + n + n + q + 1;
        // edges[cnt].c = 1;
        // nodes[p + n + n + ww].to.push_back(cnt);
        // edges[++cnt].f = p + n + n + q + 1;
        // edges[cnt].t = p + 2 * n + ww;
        // edges[cnt].c = 0;
        // nodes[p + n + n + q + 1].to.push_back(cnt);
    }
    cout << e_k();

    return 0;
}
/*
3 2 2
1 0
1 0
0 1
1 0
0 1
1 0
*/
