#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int i,j,m,n,l,r,num[N],st[N][22];//st[n][m]:2^(m)����n���� 
inline int find_max(int x,int y)//��x-y�е����ֵ����Сֵ��max��Ϊmin 
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
    for(j=1;j<21;++j)//jΪ��Χ 
    {
    	for(i=1;i+(1<<j)-1<=n;++i)
    	{
    		 st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);//����Сֵ��max��Ϊmin 
		}
	}
    for(i=1;i<=m;++i)
    {
        scanf("%d%d",&l,&r);
        
        printf("%d\n",find_max(l,r));
    }
    return 0;
}
