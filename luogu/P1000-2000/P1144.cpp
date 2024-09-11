#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N=1000005;
vector<int> G[N];
int flag[N],dis[N],cnt[N];
void BFS(int s)
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
			if(flag[y]==0)
			{
				flag[y]=1;
				dis[y]=dis[x]+1;
				Q.push(y);
			}
		}
	}
}
void solve(int s)
{
	memset(cnt,0,sizeof(cnt));
	memset(flag,0,sizeof(flag));//是否已经入队 
	queue<int> Q;
	cnt[s]=1;flag[s]=1; 
	Q.push(s);
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		for(int i=0;i<G[x].size();i++)
		{
			int y=G[x][i];
			if(dis[x]+1==dis[y])
			{
				cnt[y]+=cnt[x];
				if(flag[y]==0) Q.push(y),flag[y]=1;
			}
			
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
	BFS(1);
	solve(1);
	for(int i=1;i<=n;i++)
	{
		cout<<cnt[i]<<'\n';
	}
}
