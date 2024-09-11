#include<bits/stdc++.h>
using namespace std;
int n,m,ans1,ans2;
int a[205],dp[205][205],dp2[205][205];
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
int dfs2(int l,int r)
{                
    if(dp2[l][r])
	{
		return dp2[l][r];
	}
    if(l==r)   
	{
		return 0;
	 }       
    int res=0;                        
    for(int k=l;k<r;k++)
    {
    	 res=max(res,dfs2(l,k)+dfs2(k+1,r)+a[r]-a[l-1]);
	}
	dp2[l][r]=res;
    return dp2[l][r];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        cin>>a[i];
        a[i+n]=a[i];                
    }
    for(int i=1;i<=2*n;i++)            
    {
    	a[i]+=a[i-1];
	}  
    dfs1(1,2*n);
	dfs2(1,2*n);       
    ans1=9999999;  
	ans2=0;
    for(int i=1;i<=n;i++)
	{
        ans1=min(dp[i][n+i-1],ans1);
        ans2=max(dp2[i][n+i-1],ans2);
    }
    cout<<ans1<<endl<<ans2;
    return 0;
}
