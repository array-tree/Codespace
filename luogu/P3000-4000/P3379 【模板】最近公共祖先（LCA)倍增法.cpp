#include<bits/stdc++.h>
using namespace std;
int n,m,s,a,b;
vector<int > e[500010];
int dep[500010],fa[500010][20];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n,m,s;
    int x,y;
    for(int rr=1;rr<n;rr++)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    



    return 0;
}