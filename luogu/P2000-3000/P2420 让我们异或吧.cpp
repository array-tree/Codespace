#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,r,p,dis[N],dep[N],fa[N][18];
vector<int> edge[N],val[N];
int u,v,w;
inline void dfs(int u,int sum)
{
    int z= edge[u].size(),v=0,w=0;
    dis[u]=sum;
    for(int i=0;i<=z-1;i++)
    {
        v=edge[u][i],w=val[u][i];
        if(v==fa[u][0])
        {
            continue;
        }
        dep[v]=dep[u]+1;
        fa[v][0]=u;
        dfs(v,sum^w);
    }
}
void init()
{
    for(int j=1;j<=17;j++)
    {
        for(int i=1;i<=n;i++)
        {
            fa[i][j]=fa[fa[i][j-1]][j-1];
        }
    }
}
int lca(int a,int b)
{
    if(dep[a]<dep[b])
    {
        swap(a,b);
    }
    for(int i=0;i<=17;i++)
    {
        if((1<<i)&dep[a]-dep[b])
        {
            a=fa[a][i];
        }
    }
    if(a==b)
    {
        return a;
    }
    for(int i=18;i>=0;i--)
    {
        if(fa[a][i]!=fa[b][i])
        {
            a=fa[a][i];
            b=fa[b][i];
        }
    }
    return fa[a][0];
    
}
int main()
{
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>u>>v>>w;
        edge[u].push_back(v);
        val[u].push_back(w);
        edge[v].push_back(u);
        val[v].push_back(w);
    }
    dfs(1,1);
    init();
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        int tmp=lca(u,v);
        cout<<((dis[u]^dis[tmp])^(dis[v]^dis[tmp]))<<endl;
    }

    return 0;
}