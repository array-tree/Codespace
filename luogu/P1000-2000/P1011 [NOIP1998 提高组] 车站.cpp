#include<bits/stdc++.h>
using namespace std; 
int shu1[25],shu2[25];
	int a,n,m,x; 
void chuli()
{
	for(int i=4;i<n;i++)
	{ 
	 	shu1[i]=shu1[i-1]+shu1[i-2]-1; 
		shu2[i]=shu2[i-1]+shu2[i-2]+1; 
	} 
}
int main()
{ 

	cin>>a>>n>>m>>x;
	shu1[1]=0,shu1[2]=1,shu1[3]=2;//≥ı ºªØ 
	chuli();
	int b=(m-a*shu1[n-1]);
	b/=shu2[n-1];
	cout<<a*shu1[x]+b*shu2[x];
	return 0;
}
