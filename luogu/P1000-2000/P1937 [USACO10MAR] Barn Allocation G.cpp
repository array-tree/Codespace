#include <bits/stdc++.h>
using namespace std;
int n,m;
pair<int ,int > ned[1000000];
struct tree
{
    int l, r;
    long long min_;
    long long tag;
};
int c[1000000];
tree t[4000000];
void update(int p)
{
    t[p].min_ = min(t[p * 2].min_, t[p * 2 + 1].min_);
}
void build(int p, int l, int r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].min_ = c[l];
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    update(p);
}
void pushdown(int p)
{
    if (t[p].tag)
    {
        t[p * 2].min_ += t[p].tag;
        t[p * 2 + 1].min_ += t[p].tag;
        t[p * 2].tag += t[p].tag;
        t[p * 2 + 1].tag += t[p].tag;
        t[p].tag = 0;
    }
}
void change(int p, int l, int r, int delt)
{
    if (l <= t[p].l && r >= t[p].r)
    {
        t[p].min_ += delt;
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
long long query(int p, int l, int r)
{
    if (l <= t[p].l && r >= t[p].r)
    {
        return t[p].min_;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)>>1;
    long long ans=9999999999999;
    if(l<=mid)
    {
        ans=min(ans,query(p*2,l,r));
    }
    if(r>mid)
    {
        ans=min(ans,query(p*2+1,l,r));
    }
    return ans;
}
bool cmp(pair<int,int> a,pair<int ,int > b)
{
    if(a.second<b.second)
    {
        return a.second<b.second;
    }
    else if(a.second==b.second)
    {
        return a.first>b.first;
    }
    else
    {
        return a.second<b.second;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int rr=1;rr<=n;rr++)
    {
        cin>>c[rr];
    }
    for(int ww=1;ww<=m;ww++)
    {
        cin>>ned[ww].first>>ned[ww].second;
    }
    build(1,1,n);
    sort(ned+1,ned+1+m,cmp);
    int fans=0;
    for(int ee=1;ee<=m;ee++)
    {
        if(query(1,ned[ee].first,ned[ee].second))
        {
            fans++;
            change(1,ned[ee].first,ned[ee].second,-1);
        }

    }
    cout<<fans;
    return 0;
}