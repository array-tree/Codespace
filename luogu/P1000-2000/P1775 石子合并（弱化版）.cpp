#include<bits/stdc++.h>
using namespace std;
int n,m,ans1;
int a[305],dp[305][305];
int dfs1(int l,int r)
{                
    if(dp[l][r])
	{
		return dp[l][r];  
	}  
    if(l==r)    
	{
		return 0;   
	}
    int res=9999999;                    
    for(int k=l;k<r;k++)    
	{
		res=min(res,dfs1(l,k)+dfs1(k+1,r)+a[r]-a[l-1]);
	}            
	dp[l][r]=res;
    return dp[l][r];           
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        cin>>a[i];
        a[i+n]=a[i];                
    }
    for(int i=1;i<=n;i++)            
    {
    	a[i]+=a[i-1];
	}  
    dfs1(1,n);
    ans1=9999999;  
    ans1=min(dp[1][n],ans1);

    cout<<ans1;
    return 0;
}
