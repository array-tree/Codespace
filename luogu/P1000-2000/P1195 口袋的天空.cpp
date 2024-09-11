#include<bits/stdc++.h>
using namespace std;
struct  jie 
{
    int f,t,v;
};
jie map_[200001];
int fa[200003];
void init(int n)
{
    for(int www=1;www<=n;www++)
    {
        fa[www]=www;
    }
}
int fnd(int x)
{
	int r=x;
	while(fa[r]!=r)
	{
		r=fa[r];
	}
	while(x!=r)
	{
		int q=fa[x];
		fa[x]=r;
		x=q;
	}
	return r;	
}
int n,m,k;
struct jjj
{
    int a,b,c;
};
jjj edge[100000];
bool cmp(jjj a,jjj b)
{
    return a.c<b.c;
}
int ans,cnt,flag;
int main()
{
    
    cin>>n>>m>>k;
    init(n);
    for(int qq=1;qq<=m;qq++)
    {
        scanf("%d%d%d",&edge[qq].a,&edge[qq].b,&edge[qq].c);
    }
    sort(edge+1,edge+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        int fx=fnd(edge[i].a);
        int fy=fnd(edge[i].b);
        if(fx!=fy)
        {
            fa[fx]=fa[fy];
            ans+=edge[i].c;
            cnt++;
        }
        if(cnt==n-k)
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        cout<<ans<<endl;
    }
    else
    {
        cout<<"No Answer"<<endl;
    }
    return 0;
}