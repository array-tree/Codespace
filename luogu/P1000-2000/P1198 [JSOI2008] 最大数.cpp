#include<bits/stdc++.h>
using namespace std;
#define int long long
struct ni
{
    int shu;
    bool que;
};
ni jj[100000];
int new_;
int m,d;
int max_[800000],add[800000];
int a[300001],n;
void pushup(int root)
{
    max_[root]=max(max_[root<<1],max_[root<<1 |1]);
}
void build(int l,int r,int root)
{
    if(l==r)
    {
        max_[root]=0;
        return;
    }
    int m=(l+r)>>1;
    build(l,m,root<<1);
    build(m+1,r,root<<1 |1);
    pushup(root);
}
void pushdown(int root)
{
    if(add[root])
    {
        add[root<<1]+=add[root];
        add[root<<1 |1]+=add[root];
        max_[root<<1]+=add[root];
        max_[root<<1 |1]+=add[root];
        add[root]=0;
    }
}
void update(int L,int R,int C,int l,int r,int root)
{
    if(L<=l&&R>=r)
    {
        max_[root]+=C;
        add[root]+=C;
        return;
    }
    int m=(l+r)>>1;
    pushdown(root);
    if(L<=m)
    {
        update(L,R,C,l,m,root<<1);
    }
    if(R>m)
    {
        update(L,R,C,m+1,r,root<<1 |1);
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
    pushdown(root);
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
signed main()
{
    char ee;
    cin>>m>>d;
    for(int qqq=1;qqq<=m;qqq++)
    {
        cin>>ee;
        if(ee=='A')
        {
            jj[qqq].que=1;
            new_++;
        }
        else{
            jj[qqq].que=0;
        }
        cin>>jj[qqq].shu;
    }
    build(1,new_,1);
    //cout<<"build is OK"<<endl;
    int t=0;
    for(int jaj=1;jaj<=m;jaj++)
    {
        if(jj[jaj].que==1)
        {
            n++;
            update(n,n,(jj[jaj].shu+t)%d,1,new_,1);
            //   cout<<"update is OK:"<<jj[jaj].shu<<" "<<t<<endl;
        }
        else
        {
            t=query(n+1-jj[jaj].shu,n+1,1,new_,1);
            cout<<query(n+1-jj[jaj].shu,n+1,1,new_,1)<<endl;
        }
    }
    return 0;
}