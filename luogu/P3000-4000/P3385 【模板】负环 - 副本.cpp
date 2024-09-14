#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N=50;
int m,n;
struct edge
{
	int v,w;
};
vector<edge> G[N];
int dis[N],flag[N];//flag[x]表示x是否入队
int cnt[N],a,b,w;//最短路的边数 
void SPFA(int s)
{
    memset(cnt,0,sizeof(cnt));
	memset(flag,0,sizeof(flag));
    memset(dis,0x3f,sizeof(dis));
	queue<int> Q;
	dis[s]=0;cnt[s]=0; 
	Q.push(s);flag[s]=1;

	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		flag[x]=0;
		for(int i=0;i<G[x].size();i++)
		{
			int y=G[x][i].v,z=G[x][i].w;
			if(dis[x]+z<dis[y])
			{
				dis[y]=dis[x]+z;
				cnt[y]=cnt[x]+1;
				if(cnt[y]>=n) 
				{
				    cout<<"YES"<<endl;
					return;
				}
				if(flag[y]==0) 
				{
					
					Q.push(y);flag[y]=1;
				}
			}
		}
	}
	cout<<"NO"<<endl;
}
int main()
{
	int k;
	cin>>k;
	while(k--)
	{
        
		cin>>n>>m;
		for(int l=1;l<=m;l++)
		{
			cin>>a>>b>>w;
            G[a].push_back({b,w});
            if(w>=0)
            {
                G[b].push_back({a,w});
            }
		}
		SPFA(1);
        for(int l=1;l<=n;l++)
        {
            G[l].clear();
        }
	}

	



	return 0;
}