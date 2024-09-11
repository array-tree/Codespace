#include<bits/stdc++.h>
using namespace std;
int map_[100][100];
bool map__[100][100];
int dx[100]={0,1,0,-1};
int dy[100]={1,0,-1,0},ans;
int sy,sx,ex,ey,kll,a,b,n,m,op;
void dfs(int x,int y)
{
	if(x==ex&&y==ey)
	{
		ans++;
		return;
	}
	else
	{
		for(int j=0;j<=3;j++)
		{
			if(map_[x+dx[j]][y+dy[j]]&&!map__[x][y])
			{
				map__[x][y]=1;
				dfs(x+dx[j],y+dy[j]);
				map__[x][y]=0;
			}
		}
	}
}
int main()
{
	cin>>n>>m>>op;
	for(int k=1;k<=n;k++)
	{
		for(int s=1;s<=m;s++)
		{
			map_[k][s]=1;
		}
	}
	cin>>sx>>sy>>ex>>ey;
	for(int kl=1;kl<=op;kl++)
	{
		cin>>a>>b;
		map_[a][b]=0;
	}
	dfs(sx,sy);
	cout<<ans;	
	return 0;
}
