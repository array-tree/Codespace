#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[120000];
long long sum[400000],add[400000],max_[400000];
void pushup(int root)
{
    sum[root]=sum[root<<1]+sum[root<<1 |1];
}
void build(int l,int r,int root)
{
   // cout<<"building... root is "<<root<<endl;
    if(l==r)
    {
        sum[root]=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(l,m,root<<1);
    build(m+1,r,root<<1 |1);
    pushup(root);
}
void pushdown(int root,int ln,int rn)
{
    if(add[root])
    {
        add[root<<1]+=add[root];
        add[root<<1 |1]+=add[root];
        sum[root<<1]+=add[root]*ln;
        sum[root<<1 |1]+=add[root]*rn;
        add[root]=0;
    }

}
void update(int L,int R,int ad,int l,int r,int root)
{
    if(L<=l&&r<=R)
    {
        sum[root]+=ad*(r-l+1);
        add[root]+=ad;
        return;
    }
    int m=(l+r)>>1;
    pushdown(root,m-l+1,r-m);

    if(L<=m)
    {
        update(L,R,ad,l,m,root<<1);
    }
    if(R>m)
    {
        update(L,R,ad,m+1,r,root<<1 |1);
    }
    pushup(root);
}
int query(int L,int R,int l,int r,int root)
{
    if(L<=l&&r<=R)
    {
        return sum[root];
    }
    int m=(l+r)>>1;
    pushdown(root,m-l+1,r-m);
    int ans=0;
    if(L<=m)
    {
        ans+=query(L,R,l,m,root<<1);
    }
    if(R>m)
    {
        ans+=query(L,R,m+1,r,root<<1 |1);
    }
    return ans;
}
void show(int l,int r)
{
    for(int qq=l;qq<=r;qq++)
    {
        cout<<query(qq,qq,1,n,1)<<" ";
    }
    cout<<endl;
}
signed main()
{
    int as,b,c,d;   
    int v;
    cin>>n;
    cin>>v;
    for(int qq=1;qq<=n;qq++)
    {
        cin>>a[qq];
    }  
    build(1,n,1);
  //  cout<<"build is OK\n";
   // show(1,n);

   
    for(int ww=1;ww<=v;ww++)
    {
        cin>>as>>b>>c;
      //  if(c>=n+1)
      //  {
       //     cout<<"\nthat is too big!!!\n";
       //     ww--;
      //      continue;
      //  }
        if(as==1)
        {
            cin>>d;
            update(b,c,d,1,n,1);
          //  cout<<"update OK. now the array are :";
          //  show(1,n);
        }
        else
        {
            cout<<query(b,c,1,n,1)<<endl;

        }
    }
    return 0;
}