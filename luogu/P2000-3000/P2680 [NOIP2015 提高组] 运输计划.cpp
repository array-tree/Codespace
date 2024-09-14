#include <bits/stdc++.h>
using namespace std;
const int min_ = -999999999;
int fa[900000];
int n, m, tot;
struct edge
{
    int f, t;
    int num;
};
int cnt_e = 1;
edge edges[900000];
struct node
{
    vector<int> to;
    int dfn;
    int num;
    int fa;
    int dis;
    int chafen;
    int fab;
    vector<pair<int, int> > query;
};
node nodes[700000];
struct road
{
    int f, t;
    int lca;
    int len;
};
road roads[700000];
int dfnx[600000];
inline int fnd(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    fa[x] = fnd(fa[x]);
    return fa[x];
}
inline void tarjan_b(int x)
{
    int to_;
    nodes[x].dfn = ++tot;
    dfnx[tot]=x;
    for (int ww = 0; ww < nodes[x].to.size(); ww++)
    {
        to_ = edges[nodes[x].to[ww]].t;
        if (nodes[to_].dfn == 0)
        {
            nodes[to_].dis = nodes[x].dis + edges[nodes[x].to[ww]].num;
            nodes[to_].fab = nodes[x].to[ww];
            nodes[to_].fa = x;
            tarjan_b(to_);
            fa[to_] = x;
        }
    }
    int sss; 
    int uuu; 
    for (int yy = 0; yy < nodes[x].query.size(); yy++)
    {
        sss = nodes[x].query[yy].first;
        uuu = nodes[x].query[yy].second;
        if (nodes[sss].dfn != 0)
        {
            // cout<<fnd(sss)<<endl;
            roads[uuu].lca = fnd(sss);
        }
    }
}

inline void change_a(int x)
{
    for (int ww = 0; ww < nodes[x].to.size(); ww++)
    {
        int to_ = edges[nodes[x].to[ww]].t;
        if (to_ != nodes[x].fa)
        {
            nodes[to_].dis = nodes[x].dis + edges[nodes[x].to[ww]].num;
            change_a(to_);
        }
    }
}

void leijia(int x)
{
    int to;
    for(int w=0;w<nodes[x].to.size();w++)
    {
        to=edges[nodes[x].to[w]].t;
        if(to!=nodes[x].fa)
        {
            leijia(to);
            nodes[x].chafen+=nodes[to].chafen;
        }
    }
}

bool check(int mid)
{
    for(int ee=1;ee<=n;ee++)
    {
        nodes[ee].chafen=0;
    }
    int nnum=0;
    int max_=min_;
    for(int yy=1;yy<=m;yy++)
    {
        if(roads[yy].len>mid)
        {
            nodes[roads[yy].f].chafen++;
            nodes[roads[yy].t].chafen++;
            nodes[roads[yy].lca].chafen-=2;
            nnum++;
            max_=max(max_,roads[yy].len);
        }
        // else{
        //     break;
        // }
    }
    if(nnum==0)
    {
        return 0;
    }
    for(int yy=n;yy>=1;yy--)
    {
        nodes[nodes[dfnx[yy]].fa].chafen+=nodes[dfnx[yy]].chafen;
    }
    //leijia(1);
    int need=max_-mid;
    for(int yy=2;yy<=n;yy++)
    {
        if(nodes[yy].chafen==nnum)
        {
            if(edges[nodes[yy].fab].num>=need)
            {
                return 1;
            }
        }
    }
    return 0;
}
bool cmp(road a,road b)
{
    return a.len>b.len;
}
int main()
{
  //  clock_t sa = clock();
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(false);
   // srand(time(0));
   // rnd.seed(rand());

    cin>>n>>m;
    for (int ee = 1; ee <= n; ee++)
    {
        fa[ee] = ee;
    }
    int a, b, c;
    for (int yy = 1; yy < n; yy++)
    {
        cin>>a>>b>>c;
        edges[++cnt_e].f = a;
        edges[cnt_e].t = b;
        edges[cnt_e].num = c;
        nodes[a].to.push_back(cnt_e);
        edges[++cnt_e].f = b;
        edges[cnt_e].t = a;
        edges[cnt_e].num = c;
        nodes[b].to.push_back(cnt_e);
    }
    for (int yy = 1; yy <= m; yy++)
    {
        cin>>a>>b;
        roads[yy].f = a;
        roads[yy].t = b;
        nodes[a].query.push_back({b, yy});
        nodes[b].query.push_back({a, yy});
    }
    tarjan_b(1);

    int max_1 = min_, max_2 = min_, max_4 = min_;
    for (int yy = 1; yy <= m; yy++)
    {
        int aa, bb;
        aa = roads[yy].f;
        bb = roads[yy].t;
        roads[yy].len = nodes[aa].dis + nodes[bb].dis - 2 * nodes[roads[yy].lca].dis;
        max_1=max(max_1,roads[yy].len);
        // if (roads[yy].len >= max_1)
        // {
        //     max_1 = roads[yy].len;
        //     max_4 = yy;
        // }
    }
 //   sort(roads+1,roads+1+m,cmp);
    int l=0,r=max_1,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    if(check(r-1))
    {
        cout<<r-1;
    }
    else if (check(r))
    {
        cout<<r;
    }
    else
    {
        cout<<0;
    }
    // find_max(roads[max_4].f, roads[max_4].lca);
    // find_max(roads[max_4].t, roads[max_4].lca);
    // sort(long_ + 1, long_ + 1 + cnt_l, cmp);
    // int del = 1;
    // int max_6 = min_, final_ans = 999999999;
    // while (1)
    // {
    //     max_6 = min_;
    //     clock_t bb = clock();
    //     if (bb - sa > 800 || del == cnt_l)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         int temp = edges[long_[del]].num;
    //         edges[long_[del]].num = 0;
    //         change_a(edges[long_[del]].f);
    //         for (int yy = 1; yy <= m; yy++)
    //         {
    //             int aa, bb;
    //             aa = roads[yy].f;
    //             bb = roads[yy].t;
    //             roads[yy].len = nodes[aa].dis + nodes[bb].dis - 2 * nodes[roads[yy].lca].dis;
    //             max_6 = max(max_6, roads[yy].len);
    //         }
    //         final_ans = min(max_6, final_ans);
	// 	//	cout<<final_ans<<"\n";
    //         edges[long_[del]].num = temp;
    //         change_a(edges[long_[del]].f);
    //         del++;
    //     }
    // }
   // cout << final_ans;


    return 0;
}

