#include <bits/stdc++.h>
using namespace std;
struct tree
{
    int l, r;
    long long num;
    long long tag;
};
tree t[800005];
void update(int p)
{
    t[p].num = t[p * 2].num + t[p * 2 + 1].num;
}
long long  feng[200005];
int n,f;
void build(int p, int l, int r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].num = feng[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    update(p);
}
void pushdown(int p)
{
    if (t[p].tag)
    {
        t[p * 2].num += (t[p * 2].r - t[p * 2].l + 1) * t[p].tag;
        t[p * 2 + 1].num += (t[p * 2 + 1].r - t[p * 2 + 1].l + 1) * t[p].tag;
        t[p * 2].tag += t[p].tag;
        t[p * 2 + 1].tag += t[p].tag;
        t[p].tag = 0;
    }
}
void change(int p, int l, int r, int delt)
{
    if (l <= t[p].l && r >= t[p].r)
    {
        t[p].num += (t[p].r - t[p].l + 1) * delt;
        t[p].tag += delt;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
    {
        change(p * 2, l, r, delt);
    }
    if (r > mid)
    {
        change(p * 2 + 1, l, r, delt);
    }
    update(p);
}
long long query(int p,int l,int r)
{
    if(l<=t[p].l&&r>=t[p].r)
    {
        return t[p].num;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)>>1;
    long long aans=0;
    if(l<=mid)
    {
        aans+=query(p*2,l,r);
    }
    if(r>mid)
    {
        aans+=query(p*2+1,l,r);
    }
    return aans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>f;
    for(int ee=1;ee<=n;ee++)
    {
        cin>>feng[ee];
    }
    build(1,1,n);
    int x,y,z,k;
    for(int yy=1;yy<=f;yy++)
    {
        cin>>x;
        if(x==1)
        {
            cin>>y>>z>>k;
            change(1,y,z,k);
        }
        else if(x==2||x==3)
        {
            cin>>k;
            change(1,1,1,k*(x==2?1:-1));
        }
        else if(x==4)
        {
            cin>>y>>z;
            cout<<query(1,y,z)<<endl;
        }
        else
        {
            cout<<query(1,1,1)<<endl;
        }

    }
    return 0;
}