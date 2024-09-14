#include<bits/stdc++.h>
using namespace std;
vector<int> tree[2000];
queue<int> q;
int father[2000],ans,root,dp[2000];
int shu;
bool biao[2000];
int main()
{
	std::ios::sync_with_stdio(false); 
	cin>>shu;
	if(shu==1)
	{
		cout<<1;
		return 0;
	}
	for(int p=0;p<=shu;p++)
	{
		father[p]=-1;
	}
	for(int p=0;p<shu;p++)
	{
		int a,b;
		cin>>a>>b;
		for(int as=0;as<b;as++)
		{
			int p;
			cin>>p;
			tree[a].push_back(p);
			father[p]=a;
		}
	}
	for(int i=0;i<shu;i++)
	{
		if(!tree[i].size())
		{
			q.push(i);
		}
	}
	for(int i=0;i<shu;i++)
	{
		dp[i]=tree[i].size();
	}
	for(int i=0;i<shu;i++)
	{
		if(father[i]==-1)
		{
			root=i;
		}
	}
	
	while(q.front()!=root)
	{
		int pn=q.front();
		q.pop();
		dp[father[pn]]--;

		if(!dp[father[pn]])
		{
			q.push(father[pn]);
		}
		if(!biao[pn])
		{
			biao[father[pn]]=1;
		}
	}
	for(int i=0;i<shu;i++)
	{
		if(biao[i])
		{
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
