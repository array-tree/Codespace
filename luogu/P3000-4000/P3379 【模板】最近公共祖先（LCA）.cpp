#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,r,s,p,dis[N],dep[N],fa[N][983];
vector<int> edge[N],val[N];
int u,v,w;
inline void dfs(int u,int sum)
{
    int z= edge[u].size(),v=0,w=0;
    dis[u]=sum;
    for(int i=0;i<=z-1;i++)
    {
        v=edge[u][i];
        if(v==fa[u][0])
        {
            continue;
        }
        dep[v]=dep[u]+1;
        fa[v][0]=u;
        dfs(v,sum+1);
    }
}
void init()
{
    for(int j=1;j<=100;j++)
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
    for(int i=0;i<=100;i++)
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
    for(int i=100;i>=0;i--)
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
    cin>>n;cin>>m>>s;
    for(int i=1;i<=n-1;i++)
    {
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
        dfs(s,1);
  init();
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v; 
 
        int tmp=lca(u,v);
        cout<<tmp<<endl;
    }

    return 0;
}