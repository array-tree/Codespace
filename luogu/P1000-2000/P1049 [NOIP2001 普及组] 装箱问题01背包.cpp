#include<bits/stdc++.h>
using namespace std;
int dp[20001][20001];
int w[20001],v[20001];
int n,V,kl;
int main()
{
	cin>>V>>n;
	for(int nk=1;nk<=n;nk++)
	{
		cin>>kl;
		w[nk]=kl;
		v[nk]=kl;
	 } 
	for(int k=1;k<=n;k++)
	{
		for(int l=1;l<=V;l++)
		{
			if(l>=v[k])
			{
				dp[k][l]=max(dp[k-1][l],dp[k-1][l-v[k]]+w[k]);
			}
			else
			{
				dp[k][l]=dp[k-1][l];
			} 
		}
	}
	cout<<V-dp[n][V];
	return 0;
}
