#include<bits/stdc++.h>
long long  a,b,p,n,m,q=1;
using namespace std;
int main()
{
	cin>>n>>b>>p;
	a=n;	
	m=b;
	while(b>0) 
	{
		
		if(b%2!=0)
		{
			q=q*a%p;
			a=a*a%p;
		}
		else 
		a=a*a%p;
		
		b=b/2;
	}
	q=q%p;
	cout<<n<<"^"<<m<<" "<<"mod"<<" "<<p<<"="<<q;
	return 0;
 } 
