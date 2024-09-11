#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000],c[100000],n,dp[100000];
int main()
{
	cin>>n;
	int qqq;
	for(int i=1;i<=n;i++)
	{
		cin>>qqq;
		a[qqq]=i;
	}
	for(int we=1;we<=n;we++)
	{
		cin>>qqq;
		b[we]=a[qqq];
	}
	int len = 0;
	for (int i = 1; i <= n; ++i)
	{
	    if (dp[len] < b[i])
	    {
	    	dp[len+1] = b[i];
	    	len++;
		}
	    else
		{
			 *lower_bound(dp + 1, dp + len + 1, b[i]) = b[i];
		}
	       
	}
	cout<<len<<endl;
	for(int w=1;w<=len;w++)
	{
		cout<<dp[w]<<" ";
	}
	return 0;
}
