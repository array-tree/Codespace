#include <bits/stdc++.h>
using namespace std;
int dp[100000][3];
struct node
{
    int num;
    int dp;
    int hapn; // happyness
    vector<int> son;
    int fa;
};
node nodes[100000];
int n;
void dfs(int p)
{
    dp[p][1]=nodes[p].hapn;
    int to_;
    for (int ww = 0; ww < nodes[p].son.size(); ww++)
    {
        to_=nodes[p].son[ww];
        dfs(to_);
        dp[p][0]+=max(dp[to_][1],dp[to_][0]);
        dp[p][1]+=dp[to_][0];    
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int ww = 1; ww <= n; ww++)
    {
        cin >> nodes[ww].hapn;
    }
    int a, b;
    for (int ww = 1; ww < n; ww++)
    {
        cin >> a >> b;
        nodes[a].fa = b;
        nodes[b].son.push_back(a);
    }
    int root_;
    for (int qq = 1; qq <=n; qq++)
    {
        if (nodes[qq].fa == 0)
        {
            root_=qq;
            dfs(qq);
        }
    }
    cout<<max(dp[root_][0],dp[root_][1]);
}