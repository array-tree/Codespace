#include<bits/stdc++.h>
#include<vector>
#include <queue>
using namespace  std;
int flag[100],dis1[100],dis2[100],n,m,k,u,v;
vector<int> G[51];
void bfs(int s,int dis[])
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
        for(int l=0;l<G[x].size();l++)
        {
            int y=G[x][l];
            if(flag[y]==1)
            {
                continue;
            }
            flag[y]=1;
            dis[y]=dis[x]+1;
            Q.push(y);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int j=1;j<=m;j++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin>>k;
    for(int l=1;l<=k;l++)
    {
        cin>>u>>v;
        bfs(u,dis1);
        bfs(v,dis2);
        for(int j=1;j<=n;j++)
        {
            if(dis1[j]+dis2[j]==dis1[v])
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }


    return 0;
}