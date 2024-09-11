#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
vector<int> G[maxn];
int flag[maxn],dis[maxn],cnt[maxn],n,m,k;
int x,y;
void bfs(int s)
{
    memset(flag,0,sizeof(flag));
	memset(dis,0x3f,sizeof(dis));
	queue<int> QQ;
	dis[s]=0;flag[s]=1;
	QQ.push(s);
	while(!QQ.empty())
	{
		int x=QQ.front();
		QQ.pop();
		for(int i=0;i<G[x].size();i++)
		{
			int y=G[x][i];
			if(flag[y]==0)
			{
				flag[y]=1;
				dis[y]=dis[x]+1;
				QQ.push(y);
			}
		}
	}
}
void solve(int s)
{
    memset(cnt,0,sizeof(cnt));
	memset(flag,0,sizeof(flag));
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
                cnt[y]%=100003;
				if(flag[y]==0) Q.push(y),flag[y]=1;
			}
		}
	}
}
int main()
{

	cin>>n>>m;
	while(m--)
	{

		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	bfs(1);
	solve(1);
	for(int i=1;i<=n;i++)
	{
		cout<<cnt[i]<<'\n';
	}


    return 0;
}