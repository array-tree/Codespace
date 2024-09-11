#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;//第一个表ai+bi，二ai的i 
const int maxn=1e5+5;
int n,a[maxn], b[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=1;i<=n;i++)
	{
		q.push({a[1]+b[i],1});
	}
	for(int i=1;i<=n;i++)
	{
		pii temp=q.top();
		printf("%d ",temp.first);
		q.pop();
		temp.first=temp.first-a[temp.second]+a[temp.second+1];
		temp.second++;
		q.push(temp);
	}
	
	return 0;
}

