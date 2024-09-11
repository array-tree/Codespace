#include <bits/stdc++.h>
using namespace std;
const int N = 509;
int x1[509], x2[509];
struct node
{
    double x, y, w;
} edge[N*N];
int fa[N];
int find(int x)
{
    if (fa[x]==0)
    {
        return x;
    }
    return fa[x]=find(fa[x]);
}
bool cmp(node x,node y)
{
    return x.w<y.w;
}
double d(int x1, int y1, int x2, int y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int s,p;
int main()
{
    cin>>s>>p;
    int l=0;
    for (int i=1;i<=p;i++)
    {
        cin>>x1[i]>>x2[i];
    }
    for (int i=1;i<=p;i++)
    {
        for (int j=i+1;j<=p;j++)
        {
            if (i!=j)
            {
                edge[++l].x=i;
                edge[l].y=j;
                edge[l].w=d(x1[i],x2[i],x1[j],x2[j]);
            }
        }
    }
    sort(edge+1,edge+l+1,cmp);
    double ans=0,k=0;
    for(int i=1;i<=l;i++)
    {
        int fx, fy;
        fx=find(edge[i].x);
        fy=find(edge[i].y);
        if (fx!=fy)
        {
            ans = max(ans, edge[i].w);
            fa[fx] = fy;
            k++;
            if (k == p - s)
            {
                break;
            }
        }
    }
    printf("%.2lf",ans);
    return 0;
}
