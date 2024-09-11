#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=4000011;
const int coverr=-114514;
int max_[maxn];
int add[maxn],cover[maxn];
int n;
int a[maxn];
void pushup(int root)
{
    max_[root]=max(max_[root<<1],max_[root<<1 |1]);
}
void build(int l,int r,int root)
{
     cout<<"building... root is "<<root<<endl;
    if(l==r)
    {
        max_[root]=a[l];
        cover[root]=coverr;
        return;
    }
    int m=(l+r)>>1;
    build(l,m,root<<1);
    build(m+1,r,root<<1 |1);
    pushup(root);
}
void pushdown_cover(int root)
{
    if(cover[root]!=coverr)
    {
        add[root]=0;
        add[root<<1]=0;
        add[root<<1 |1]=0;
        max_[root<<1]=cover[root];
        max_[root<<1 |1]=cover[root];
        cover[root<<1]=cover[root];
        cover[root<<1 |1]=cover[root];
        cover[root]=coverr;
    }
}
void pushdown_sum(int root)
{
    if(add[root])
    {
        pushdown_cover(root);
        add[root<<1]+=add[root];
        add[root<<1 |1]+=add[root];
        max_[root<<1]+=add[root];
        max_[root<<1 |1]+=add[root];
        add[root]=0;
    }
}

void update_add(int L,int R,int C,int l,int r,int root)
{
    if(L<=l&&r<=R)
    {
        pushdown_cover(root);
        max_[root]+=C;
        add[root]+=C;
        return;
    }
    int m=(l+r)>>1;
    pushdown_cover(root);
    pushdown_sum(root);
    if(L<=m)
    {
        update_add(L,R,C,l,m,root<<1);
    }
    if(R>m)
    {
        update_add(L,R,C,m+1,r,root<<1 |1);
    }
    pushup(root);
}
void update_cover(int L,int R,int C,int l,int r,int root)
{
    if(L<=l&&r<=R)
    {
        add[root]=0;
        max_[root]=C;
        cover[root]=C;
        return;
    }
    pushdown_cover(root);
    pushdown_sum(root);
    int m=(l+r)>>1;
    if(L<=m)
    {
        update_cover(L,R,C,l,m,root<<1);
    }
    if(R>m)
    {
        update_cover(L,R,C,l,r,root<<1 |1);
    }
    pushup(root);
}
int query(int L,int R,int l,int r,int root)
{
    if(L<=l&&r<=R)
    {
        return max_[root];
    }
    int m=(l+r)>>1;
    pushdown_cover(root);
    pushdown_sum(root);
    int ans=-9999999;
    if(L<=m)
    {
        ans=max(ans,query(L,R,l,m,root<<1));
    }
    if(R>m)
    {
        ans=max(ans,query(L,R,m+1,r,root<<1 |1));
    }
    return ans;
}
int v;
signed main()
{
    
    cin>>n>>v;
    for(int qq=1;qq<=n;qq++)
    {
        scanf("%lld",&a[qq]);
    }
    build(1,n,1);
     cout<<"build is OK\n";
    int sa=0,b=0,c=0,d=0;
    for(int qq=1;qq<=v;qq++)
    {
        cin>>sa;
        if(sa==1)
        {
            scanf("%lld%lld%lld",&b,&c,&d);
            update_cover(b,c,d,1,n,1);
            
        }
        else if(sa==2)
        {
           scanf("%lld%lld%lld",&b,&c,&d);

            update_add(b,c,d,1,n,1);
        }
        else
        {
            scanf("%lld%lld",&b,&c);
            cout<<query(b,c,1,n,1)<<endl;
        }
     }
    return 0;
}