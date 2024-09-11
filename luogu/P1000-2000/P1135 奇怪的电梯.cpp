#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int ans = 99999999;
queue<pair<int, int> >  q;
bool tag[100000];
int delt[10000];
void bfs()
{  
    pair<int, int> a = q.front();
    while (!q.empty())
    {
        a=q.front();
        if(a.first==b)
        {
            ans=a.second;
            return;
        }
        q.pop();
        int l,r;
        l=a.first+delt[a.first];
        r=a.first-delt[a.first];
        if(l<=n&&!tag[l])
        {
            tag[l]=1;
            q.push({l,a.second+1});
        }
        if(r>=1&&!tag[r])
        {
            tag[r]=1;
            q.push({r,a.second+1});
        }

    }
}
int main()
{
    cin >> n >> a >> b;
    for(int ee=1;ee<=n;ee++)
    {
        cin>>delt[ee];
    }
    q.push({a,0});
    bfs();
    if(ans==99999999)
    {
        cout<<-1;
        return 0;
    }
    else
    {
        cout<<ans<<endl;
        return 0;
    }
}