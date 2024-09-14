#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long LL;
typedef pair<long long ,int > pp;
priority_queue<pp,vector<pp>,greater<pp> >  q ;

LL n,k,ans;
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		pp temp;
		scanf("%lld",&temp.first);
		temp.second=0;
		q.push(temp);
	}
	//²¹ÆëÐéÄâµã
	while((n-1)%(k-1))
	{
		pp temp;
		temp.first=0;
		temp.second=0;
		q.push(temp);
		n++;
	 } 
	 //¹¹Ôìk²æ¹þ·òÂüÊ÷ 
	while(q.size()>1)
	{
		LL sum=0;
		int d=0;
		for(int i=0;i<k;i++)
		{
			sum+=q.top().first;
			d=max(d,q.top().second);
			q.pop();
		}

		ans+=sum;

		q.push({sum,d+1});
		
	}
	printf("%lld\n%lld",ans,q.top().second);
	return 0;
}
