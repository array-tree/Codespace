#include <bits/stdc++.h>
using namespace std;
#define N 1000009
struct node
{
    int nxt,to,w;
} edge[N];
long long tot=0;
long long head[N],siz[N],dp[N],c[N],dis[N],n,m,cnt;
long long ans = 0x3f3f3f3f3f3f3f3f3f3f;
inline int add(int x,int y,int w)
{
    edge[++tot].w=w;
    edge[tot].to=y;
    edge[tot].nxt=head[x];
    head[x]=tot;
}
void dfs(int u,int fa)
{
    siz[u]=c[u];
    for (int i=head[u];i!=0;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if (v==fa)
        {
            continue;
        }
        dfs(v,u);
        siz[u]+=siz[v];
        dis[u]+=dis[v]+siz[v]*edge[i].w;
    }
}
void dfs2(int u, int fa)
{
    for (int i=head[u];i!=0;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if (v==fa)
        {
            continue;
        }
        dp[v]=dp[u]-siz[v]*edge[i].w+(cnt-siz[v])*edge[i].w;
        ans=min(ans,dp[v]);
        dfs2(v,u);
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>c[i];
        cnt+=c[i];
    }     
	int x,y,z;
    for (int i=1;i<n;i++)
    {
 
        cin>>x;
        cin>>y;
        cin>>z;
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0);
    dp[1]=dis[1];
    ans=min(ans,dp[1]);
    dfs2(1,0);
    cout << ans;
    return 0;
}
