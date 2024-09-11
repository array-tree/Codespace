#include<bits/stdc++.h>
using namespace std;
int fa[5005],n,m,fx,fy,ss,ttt;
inline int fnd(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=fnd(fa[x]);
}
struct Edge
{
	int x,y,z;
} E[200020];
bool cmp(Edge e1,Edge e2)
{
	return e1.z<e2.z;
}
int main()
{
//	freopen("P1396_10.in","r",stdin);
	cin>>n>>m>>ss>>ttt;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	} 
	for(int i=1;i<=m;i++) 
	{
		cin>>E[i].x>>E[i].y>>E[i].z;
	}
	sort(E+1,E+m+1,cmp);
	int ans=0,k=0;
	for(int i=1;i<=m;i++)
	{
		
		fx=fnd(E[i].x);
		fy=fnd(E[i].y);
		if(fx!=fy)
		{
			fa[fx]=fy;
		}	
		if(fnd(ss)==fnd(ttt))
		{
			cout<<E[i].z<<endl;
			return 0;
		 } 
		 
	}
	
	return 0;
}
