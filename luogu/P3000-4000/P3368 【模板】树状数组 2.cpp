#include<bits/stdc++.h>
using namespace std;
int j,q;
int a[500100],b[500100],s[500100];
int my_lowbit(int x)
{
    return -x&x;
}
void add(int x,int y)
{
	while(x<=j)
	{
		s[x]+=y;
		x+=my_lowbit(x);
	}
}
int query(int x)
{
	int sum=0;
	while(x>0)
	{
		sum+=s[x];
		x-=my_lowbit(x);
	}
//	cout<<sum<<endl;
	return sum;
}
void build_t(int n)
{
	for(int k=1;k<=n;k++)
	{
		s[k]+=a[k];
		int sj=k+my_lowbit(k);
		if(sj<=n)
		{
			s[sj]+=s[k];
		}
		
	}
}
int main()
{
	cin>>j>>q;
	for(int o=1;o<=j;o++)
	{
		scanf("%d",&b[o]);
	}

	for(int h=1;h<=q;h++)
	{
		int ops,t,y,u;
		cin>>ops;
		if(ops==1)
		{
			cin>>t>>y>>u;
			add(t,u);
			add(y+1,-u);
		}
		else
		{
			cin>>t;
			cout<<query(t)+b[t]<<endl;
		}
	}
	




	return 0;
}

