#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N=50;
vector<int> G[N];
int flag[N],dis1[N],dis2[N];
void BFS(int s,int dis[])
{
	memset(flag,0,sizeof(flag));
	memset(dis,0x3f,sizeof(dis));
	queue<int> Q;
	dis[s]=0;flag[s]=1;
	Q.push(s);
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		for(int i=0;i<G[x].size();i++)
		{
			int y=G[x][i];
			if(flag[y]==1) continue;
			flag[y]=1;
			dis[y]=dis[x]+1;
			Q.push(y);
		}
	}
}
int main()
{
	int n,m,k;
	cin>>n>>m;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	cin>>k;
	while(k--)
	{
		int x,y;
		cin>>x>>y;
		BFS(x,dis1);
		BFS(y,dis2);
		for(int z=1;z<=n;z++)
		{
			if(dis1[z]+dis2[z]==dis1[y]) cout<<z<<' ';
		}
		cout<<'\n';
	}
}
