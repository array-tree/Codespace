#include<bits/stdc++.h>
using namespace std;
const int seed=233;
int n,m,k,kk1,kk2,xa,xb;
unsigned long long hash_=0;
int fa[200100];
inline int hashs(string s)
{
	hash_=0;
	for(int i=0;i<s.length();i++)
	{
		hash_*=seed;
		hash_+=s[i];
	}
	return hash_%200000+1;
}
inline int fnd(int x)
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

string hul,hui;
int main()
{
	cin>>n>>m;
	for(int u=1;u<=n;u++)
	{
		cin>>hul;
		kk1=hashs(hul);
		fa[kk1]=kk1;
	}
	for(int u=1;u<=m;u++)
	{
		cin>>hul>>hui;
		kk1=hashs(hul);
		kk2=hashs(hui);
		xa=fnd(kk1);
		xb=fnd(kk2);
		fa[xa]=xb;
	}	
	cin>>k;
	for(int u=1;u<=k;u++)
	{
		cin>>hul>>hui;
		kk1=hashs(hul);
		kk2=hashs(hui);
		xa=fnd(kk1);
		xb=fnd(kk2);
		if(xa==xb)
		{
			cout<<"Yes."<<endl;
		}
		else
		{
			cout<<"No."<<endl;
		}
	}
	
	
	
	return 0;
}
