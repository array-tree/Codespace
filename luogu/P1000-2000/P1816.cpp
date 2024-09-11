#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int a[N];
struct Node
{
	int l,r;
	int data;//min
} T[N*4];
void pushup(int p)
{
	T[p].data=min(T[2*p].data,T[2*p+1].data);
}
void build(int p,int l,int r)
{
	T[p].l=l,T[p].r=r;
	if(l==r) {T[p].data=a[l];return;}
	int mid=(l+r)/2;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	pushup(p);
}
int query(int p,int l,int r)
{
	if(l<=T[p].l&&T[p].r<=r) return T[p].data;
	int ans=1e9,mid=(T[p].l+T[p].r)/2;
	if(l<=mid) ans=min(ans,query(2*p,l,r));
	if(r>mid) ans=min(ans,query(2*p+1,l,r));
	return ans; 
}
void change(int p,int x,int v)
{
	if(T[p].l==T[p].r) {T[p].data=v;return;}
	int mid=(T[p].l+T[p].r)/2;
	if(x<=mid) change(2*p,x,v);
	else change(2*p+1,x,v);
	pushup(p);
}
int main()
{
	
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	while(m--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d ",query(1,l,r));
	}
} 
