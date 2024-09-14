#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int n,m,fx,fy,x,y,z,pa,pb,sa,sb;
int tota,totb;
int fa[maxn],fb[maxn];
int fand(int x)
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
int fbnd(int x)
{
	int r=x;
	while(fb[r]!=r)
	{
		r=fb[r];
	}
	while(x!=r)
	{
		int q=fb[x];
		fb[x]=r;
		x=q;
	}
	return r;
	
}
int main()
{
	cin>>pa>>pb>>sa>>sb;
	for(int i=1;i<=pa;i++) fa[i]=i;
	for(int i=1;i<=pb;i++) fb[i]=i;
	for(int k=1;k<=sa;k++)
	{
		cin>>x>>y;
		fx=fand(x);
		fy=fand(y);
			if(fy==1)
		{
			fa[fx]=fy;
		}
		else if(fx==1)
		{
			fa[fy]=fx;
		}
		else
		{
			fa[fy]=fx;
		}
	}
	for(int k=1;k<=sb;k++)
	{
		cin>>x>>y;
		fx=fbnd(-x);
		fy=fbnd(-y);
		if(fy==1)
		{
			fb[fx]=fy;
		}
		else if(fx==1)
		{
			fb[fy]=fx;
		}
		else
		{
			fb[fy]=fx;
		}
		
	}	
	

	for(int k=1;k<=pa;k++)
	{
//		cout<<fand(k)<<endl;
		if(fand(k)==1)
		{
			tota++;
//			cout<<k<<endl; 
		}
	}
//	cout<<"sdsda"<<endl;
	for(int k=1;k<=pb;k++)
	{
//			cout<<fbnd(k)<<endl;
		if(fbnd(k)==1)
		{
			totb++;
//			cout<<k<<endl;
		}
	}
	cout<<min(tota,totb);
	
}
