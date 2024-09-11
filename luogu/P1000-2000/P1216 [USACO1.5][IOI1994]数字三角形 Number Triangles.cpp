#include<bits/stdc++.h>
using namespace std;
int ko[2000][2000],max_n,l;
int main()
{
	cin>>l;
	for(int u=1;u<=l;u++)
	{
		for(int j=1;j<=u;j++)
		{
			cin>>ko[u][j];
		}
	}
	
	for(int u=2;u<=l;u++)
	{
		ko[u][1]+=ko[u-1][1];
		for(int j=2;j<=u;j++)
		{
			ko[u][j]+=max(ko[u-1][j],ko[u-1][j-1]);
		}
	}
	int ans=-114154;
	for(int o=1;o<=l;o++)
	{
		ans=max(ans,ko[l][o]);
	}
	cout<<ans;
	
	return 0;
}
