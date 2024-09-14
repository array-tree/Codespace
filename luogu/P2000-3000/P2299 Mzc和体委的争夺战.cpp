#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int inf=100000000;
int n,m,u,v,w,ans,dis[6002],g[3002][3002],s,t;
bool vis[3002];
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			g[i][j]=inf;
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		if(w<g[u][v])
		{
			g[u][v]=w;
			g[v][u]=w;
		}
	}
		for(i=0;i<=n;i++)
	{
		dis[i]=g[1][i];vis[i]=0;
 }
	dis[1]=0;vis[1]=1;
	for(i=1;i<n;i++)
	{
		u=0;
		for(j=1;j<=n;j++)
		{
			if(vis[j]==0&&dis[j]<dis[u])
			{
				u=j;
			}
		}
		vis[u]=1;
		for(j=1;j<=n;j++)
		{
			if(vis[j]==0&&g[u][j]!=inf&&dis[u]+g[u][j]<dis[j])
			{
				dis[j]=dis[u]+g[u][j];
			}
		}
	}

		ans+=dis[n];
	
	cout<<ans;
	return 0;
}
