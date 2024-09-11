#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
 int n,m;
int a[maxn],b[maxn];
priority_queue<int> left_;
priority_queue<int,vector<int>,greater<int> > ri;

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);	
	}
	for(int i=1,j=1;i<=n;i++)
	{
		
		while(b[i]>=j)
		{
			if(left_.empty()||a[j]>=left_.top())
			{
				ri.push(a[j]);
			
			}
			else
			{
				ri.push(left_.top());
				left_.pop();
				left_.push(a[j]);
				
			}	
			j++;
		}
		cout<<ri.top()<<endl;
		left_.push(ri.top());
		ri.pop();
	
	}
	
	
	return 0;
}
