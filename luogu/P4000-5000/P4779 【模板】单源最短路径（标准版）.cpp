#include<bits/stdc++.h>
using namespace std;
int dist[210000];
bool st[210000];
int head[210000];
int nex[210000];
int to[210000];
int w[210000];
int n,m,a,b,c,sta,cnt;
void dijkstar(int a)
{
    memset(dist,0x3f3f3f,sizeof(dist));
    memset(st,0,sizeof(st));
    dist[a]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > heap;
    heap.push({0,a});
    while(heap.size())
    {
        pair<int,int> t=heap.top();
        heap.pop();
        int nod=t.second;
        int diss=t.first;
        if(st[nod])
        {
            continue;
        }
        st[nod]=1;
        for(int i=head[nod];i!=-1;i=nex[i])
        {
            int j=to[i];
            if(dist[j]>dist[nod]+w[i])
            {
                dist[j]=dist[nod]+w[i];
                heap.push({dist[j],j});
            }
        }
    }
    for(int qwe=1;qwe<=n;qwe++)
    {
        cout<<dist[qwe]<<" ";
    }
}
void add_edge(int f,int t,int v)
{
    to[++cnt]=t;
    w[cnt]=v;
    nex[cnt]=head[f];
    head[f]=cnt;
}
int main()
{
    memset(head,-1,sizeof(head));
    cin>>n>>m>>sta;
    for(int ui=1;ui<=m;ui++)
    {
        cin>>a>>b>>c;
        add_edge(a,b,c);
    }
    dijkstar(sta);
    return 0;
}