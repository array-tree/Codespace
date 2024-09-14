#include<bits/stdc++.h>
using namespace std;
int l,n,m,ans;
int ji[60000];
bool check(int jkl)
{
	int tot=0;
	int i=0;
	int now=0;
	while(i<n+1)
	{
		i++;
		if(ji[i]-ji[now]<jkl)
		{
			tot++;
		}
		else
		{
			now=i;
		}
	}
	return tot<=m;
}
int main()
{
	cin>>l>>n>>m;
	for(int s=1;s<=n;s++)
	{
		cin>>ji[s];
	}
	ji[n+1]=l;
	int ll=1;
	int rr=l,mid;
	while(ll<=rr)
	{
		mid=(ll+rr)/2;
		if(check(mid))
		{
			ans=mid;
			ll=mid+1;
		}
		else
		{
			rr=mid-1;
		}
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}
