#include<bits/stdc++.h>
#include "queue"
using namespace std;
int n,ans;
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int qs=0;qs<n;qs++)
	{
	int op;
		cin>>op;
		q.push(op);	
	}
	if(n==2)
	{
		
		ans+=q.top();
		q.pop();
				ans+=q.top();
		q.pop();
		cout<<ans;
		return 0;
	}
	if(n>2)
	{
		
		while(q.size()>=2)
		{
			int e=0;
			e+=q.top();
			q.pop();
			e+=q.top();
			q.pop();
			ans+=e;
			q.push(e);
		}
	}
	cout<<ans;
	return  0;
}
