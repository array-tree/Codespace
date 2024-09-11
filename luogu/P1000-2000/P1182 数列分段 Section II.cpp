#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,m,a[N];
bool check(int k)
{
	int cur=0,ans=1;
	for(int i=1;i<=n;i++)
	{
		if(cur+a[i]>k)
		{
			cur=0;
			ans++;
		}
		cur+=a[i];
	}
	return ans<=m;
}
int main()
{
	scanf("%d%d",&n,&m);
	int l=0,r=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		r+=a[i];
		l=max(l,a[i]);
	}
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else 
		{
			l=mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
