#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int d,g;
struct rubbish
{
	int high;
	int time;
	int life;
};
rubbish rub[1000];
bool cmp(rubbish a,rubbish b)
{
	return a.time<b.time;
}
int main()
{
	cin>>d>>g;	
	dp[0]=10;
	for(int i=1;i<=g;i++)
	{
		cin>>rub[i].time>>rub[i].life>>rub[i].high;	
	}		
	sort(rub+1,rub+1+g,cmp);
	for(int n=1;n<=g;n++)
	{
		for(int m=d;m>=0;m--)
		{
			if(rub[n].time<=dp[m])
			{
				if(m+rub[n].high>=d)
				{
					cout<<rub[n].time;
					return 0;
				}
				dp[m+rub[n].high]=max(dp[m],dp[m+rub[n].high]);
				dp[m]+=rub[n].life;
			}
		}
	}	
	cout<<dp[0];
	return 0;
 } 
