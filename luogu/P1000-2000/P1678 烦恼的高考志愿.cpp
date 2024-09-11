#include<bits/stdc++.h>
using namespace std;
long long ji[100010],xue[100010];
int n,m;
	int l=0,r=0;
int main()
{
	cin>>n>>m;
	for(int k=1;k<=n;k++)
	{
		scanf("%d",&ji[k]);
	}
	for(int k=1;k<=m;k++)
	{
		scanf("%d",&xue[k]);
	}
	sort(ji+1,ji+1+n);
	long long ans=0;
	for(int j=1;j<=m;j++)
	{
		l=0,r=n+1;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(ji[mid]<xue[j])
			{
				l=mid+1;
			}
			else
			{
				r=mid;
			}
		}
		if(xue[j]<=ji[1])
		{
			ans+=ji[1]-xue[j];
		}
		else
		{
			ans+=min(abs(ji[l-1]-xue[j]),abs(ji[l]-xue[j]));
		}
	}
	cout<<ans;
	return 0;
}
