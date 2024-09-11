#include<bits/stdc++.h>
using namespace std;
int max_,zuixiao_,mn,chang,q,zuixiao_ling;
int main()
{
	cin>>chang;
	cin>>mn;
	for(int j=0;j<mn;j++)
	{
		cin>>q;
		max_=max(max_,max(q,chang-q+1));
		zuixiao_=max(zuixiao_,min(q,chang-q+1));
	}
	cout<<zuixiao_<<" "<<max_;
	return 0;
 } 
