#include<bits/stdc++.h>
using namespace std;
int dp[10010];
int w[100001],v[100001];
const int maxn=10000000;
int V,n,c;
int max_t,max_tl;
int factv;
inline void solve(int i,int  a[],int  b[],int Vs)
{
	for(int j=Vs;j>=1;j--)
	{
		if(j>=v[i]) b[j]=min(w[i]+a[j-v[i]],a[j]);
		else b[j]=min(a[j],w[i]);
	}
}
int main()
{
//	freopen("P1510_2.in","r",stdin);
	for(int hu=1;hu<=5001;hu++)
	{
		dp[hu]=dp[hu+5000]=maxn;
	}
	cin>>V>>n>>c;
	for(int u=1;u<=n;u++)
	{
		scanf("%d%d",&v[u],&w[u]);
	}
	for(int gu=1;gu<=n;gu++)
	{
		solve(gu,dp,dp,V);
	}
	c-=dp[V];
	if(c>=0)
	{
		cout<<c<<endl;
	}
	else
	{
			cout<<"Impossible"<<endl;
	}
	return 0;
}
