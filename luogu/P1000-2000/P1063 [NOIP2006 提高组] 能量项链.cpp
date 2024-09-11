#include<bits/stdc++.h>
using namespace std;
int n;
int e[1000],dp[1000][1000];
int ans=-1; 
int main()
{
	cin>>n;
	for(int qq=1;qq<=n;qq++)
	{
		cin>>e[qq];
		e[qq+n]=e[qq];
	}
	for(int siz=2;siz<=n+1;siz++)
	{
		for(int l=1;l+siz<=2*n+1;l++)
		{
			int r=l+siz-1;
			for(int k=l+1;k<=l+siz-2;k++)
			{
				dp[l][r]=max(dp[l][r],dp[l][k]+dp[k][r]+e[l]*e[k]*e[r]);
			 } 
			
		}
	}

	for(int wi=1;wi<=n;wi++)
	{
	//	cout<<dp[wi][wi+n]<<endl;
		ans=max(ans,dp[wi][wi+n]);
	}
	cout<<ans;
	
	return 0;
}
