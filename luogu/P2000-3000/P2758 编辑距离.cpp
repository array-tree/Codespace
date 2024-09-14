#include<bits/stdc++.h>
using namespace std;
string j,s;
int dp[2010][2010];
int main()
{
	cin>>j>>s;
	for(int y=1;y<=j.size();y++)
	{
		dp[y][0]=y;
	}
	for(int y=1;y<=s.size();y++)
	{
		dp[0][y]=y;
	}
	for(int h=1;h<=j.size();h++)
	{
		for(int k=1;k<=s.size();k++)
		{
			int yy=1;
			if(j[h-1]==s[k-1])
			{
				yy=0;
			}
			dp[h][k]=min(dp[h-1][k]+1,min(dp[h][k-1]+1,dp[h-1][k-1]+yy));
			
		}
	}
	cout<<dp[j.size()][s.size()];
}
