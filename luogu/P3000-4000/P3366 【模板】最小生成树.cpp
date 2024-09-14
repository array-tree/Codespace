#include<bits/stdc++.h>
using namespace std;
int G[5001][5001],dis[5001];
bool flag[5001];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int l=1;l<=n;l++)
	{
		for(int nm=1;nm<=n;nm++)
		{
			G[l][nm]=1e9;
		}
	}
	int a,b,c;
	for(int l=1;l<=m;l++)
	{
		cin>>a>>b>>c;
		int ghu=min(min(c,G[a][b]),G[b][a]);
		G[a][b]=ghu;
		G[b][a]=ghu;	
	}
	int ans=0;
	int s=1;
	flag[s]=1;
	dis[0]=1e9;
	for(int i=1;i<=n;i++)
	{
		dis[i]=G[s][i];
	} 
	for(int k=1;k<n;k++)
	{
		int j=0;
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==0&&dis[i]<dis[j]) j=i;
		}
		ans+=dis[j];
		flag[j]=1;
		if(!j)
		{
			cout<<"orz"<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==0&&dis[i]>G[j][i]) dis[i]=G[j][i];
		}
	}
	cout<<ans;
	return 0;
}
