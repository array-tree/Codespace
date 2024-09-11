#include<bits/stdc++.h>
using namespace std;
int c[1000000],n,cc;
bool check(int dis)
{
	int qqw=cc;
	qqw--;
	int last=c[1]+dis;
	for(int yu=1;yu<=n;yu++)
	{
		if(c[yu]<last)
		{
			continue;
		}
		qqw--;
		last=c[yu]+dis;
	}
	if(qqw>0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	cin>>n>>cc;
	for(int qq=1;qq<=n;qq++)
	{
		cin>>c[qq];
		
	}
	sort(c+1,c+1+n,cmp);
	int l=0,r=c[n]-c[1];
	int mid=(l+r)/2;
	while(l<=r) 
	{
		if(!check(mid))
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
		mid=(l+r)/2;
	//	cout<<mid<<endl;
	}
	
	cout<<mid;
	return 0;
}
