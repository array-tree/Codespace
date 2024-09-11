#include<bits/stdc++.h>
using namespace std;
int ans=-999999999;
struct node
{
    int num;
    int buty;
    vector<int> son;
    int fa;
    int dp;
};
node nodes[100000];
inline bool if_true_son(int a,int b)
{
    if(nodes[a].fa==b)
    {
        return 0;
    }
    return 1;
}

int n;
void build_tree(int p)
{   
    int to_;
    for(int ww=0;ww<nodes[p].son.size();ww++)
    {
        to_=nodes[p].son[ww];
        if(if_true_son(p,to_))
        {
            nodes[to_].fa=p;
            build_tree(to_);
        }
    }
}   
void dfs(int p)
{
    int to_;
    nodes[p].dp=nodes[p].buty;
    for(int ww=0;ww<nodes[p].son.size();ww++)
    {
        to_=nodes[p].son[ww];
        if(if_true_son(p,to_))
        {
            dfs(to_);
            nodes[p].dp+=max(0,nodes[to_].dp);
        }
        
    }
    ans=max(ans,nodes[p].dp);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int yy=1;yy<=n;yy++)
    {
        cin>>nodes[yy].buty;
    }
    int a,b;
    for(int yy=1;yy<n;yy++)
    {
        cin>>a>>b;
        nodes[a].son.push_back(b);
        nodes[b].son.push_back(a);
    }
    build_tree(1);
    dfs(1);
    cout<<ans;


    return 0;
}