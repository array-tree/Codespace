#include<bits/stdc++.h>
using namespace std;
long long n,shu[200000],k;
long long zong;
bool check(long long x) {
	long long ans=0;
	for(int ks=1;ks<=n;ks++)
	{
		ans+=shu[ks]/x;
		
	}
	return ans>=k;
}

int main()
{
	cin>>n>>k;
	for(int l=1;l<=n;l++)
	{
		scanf("%d",&shu[l]);
		zong+=shu[l];	
	}	
	if(zong<k)
	{
		cout<<0;
		return 0;
	}
	
	long long  l=0,r=100000001;
	long long mid;
	while(l<r)
	{
		mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
		
	}
	cout<<l;
	
	return 0;
}
