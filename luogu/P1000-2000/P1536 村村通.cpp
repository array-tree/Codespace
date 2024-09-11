#include<bits/stdc++.h>
using namespace std;
int fa[1000000],n,m,ans,a,b,ya,yb;
int fnd(int x)
{
	int r=x;
	while(fa[r]!=r)
	{
		r=fa[r];
	}
	while(x!=r)
	{
		int q=fa[x];
		fa[x]=r;
		x=q;
	}
	return r;
	
}
int main()
{
	while(1)
	{
		ans=0;
		
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		for(int u=1;u<=n;u++)
		{
			fa[u]=u;
		}
		
		scanf("%d",&m);
		for(int h=1;h<=m;h++)
		{
			scanf("%d%d",&a,&b);
			ya=fnd(a);
			yb=fnd(b);
			fa[ya]=yb;
		}
		for(int o=1;o<=n;o++)
		{
			if(fnd(o)==o)
			{
				ans++;
			}
		}
		ans--;
		cout<<ans<<endl;
		
	}

	
	
	
	
	
	
	return 0;
} 
