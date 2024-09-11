#include<bits/stdc++.h>
using namespace std;
int flo[110000];
int dp[110000][3];
int hhu,a;
int n,ans;
int max_;
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;	
	if(n)
	{
		dp[1][1]=1;
		dp[1][2]=1;
	}
	for(int we=1;we<=n;we++)
	{
		cin>>flo[we];	
	}
	for(int rt=2;rt<=n;rt++)
	{
		if(flo[rt]>flo[rt-1])
		{
			dp[rt][1]=max(dp[rt-1][1],dp[rt-1][2]+1);
		}
		else
		{
			dp[rt][1]=dp[rt-1][1];
		}
		 if(flo[rt]<flo[rt-1])
		{
			dp[rt][2]=max(dp[rt-1][2],dp[rt-1][1]+1);
		}
        else
        {
            dp[rt][2]=dp[rt-1][2];
        }
	}
	ans=max(dp[n][1],dp[n][2]);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//dp[i][1]:/  dp[i][1]=max(dp[i-1][1],dp[i-1][2]+1);
//dp[i][2]:\ dp[i][2]=max(dp[i-1][2],dp[i-1][1]+1);


/*   暴力
	PS：有问题 
	int up=1;
	int numa=0,numb=0,re=0;
	for(int we=1;we<=n-max_;we++)
	{
		// /\/\/\/\ 
		numa=1;
		up=1;
		for(int ee=we+1;ee<=n;ee++)
		{
			if(up>0)
			{
				if(flo[ee]>flo[ee-1])
				{
					up=2;

				}
				else if(up==2)
				{
					up=0;
					numa++;
				}
			}
			else if(up<=0)
			{
				if(flo[ee]<flo[ee-1])
				{
					up=-1;

				}
				else if(up==-1)
				{
					up=0;
					numa++;
				}
			}

		}					if(up==2||up==-1)
			{
				numa++;
			}
		// \/\/\/\/ 
		numb=1;
		up=0;
		for(int ee=we+1;ee<=n;ee++)
		{
			
			if(up>0)
			{
				if(flo[ee]>flo[ee-1])
				{
					up=2;
			
				}
				else if(up==2)
				{
					up=0;
					numb++;
				}
			}
			else if(up<=0)
			{
				if(flo[ee]<flo[ee-1])
				{
					up=-1;
	
				}
				else if(up==-1)
				{
					up=0;
					numb++;
				}
			}

		}	
			if(up==2||up==-1)
			{
				numb++;
			}
		cout<<we<<" "<<numa<<" "<<numb<<endl;
		max_=max(numa,numb);
	}
	cout<<max_;
*/