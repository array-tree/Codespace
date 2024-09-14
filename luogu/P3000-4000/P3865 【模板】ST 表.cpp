#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int i,j,m,n,l,r,num[N],st[N][22];//st[n][m]:2^(m)大于n即可 
inline int find_max(int x,int y)//求x-y中的最大值，最小值将max改为min 
{
	int z=num[y-x+1];
	return max(st[x][z],st[y-(1<<z)+1][z]);
}
int main()
{
    cin>>n>>m;
    num[0]=-1;
    for(i=1;i<=n;++i)
    {
        scanf("%d",&st[i][0]);
        num[i]=num[i>>1]+1;
    }
    for(j=1;j<21;++j)//j为范围 
    {
    	for(i=1;i+(1<<j)-1<=n;++i)
    	{
    		 st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);//求最小值将max改为min 
		}
	}
    for(i=1;i<=m;++i)
    {
        scanf("%d%d",&l,&r);
        
        printf("%d\n",find_max(l,r));
    }
    return 0;
}
