#include<bits/stdc++.h>
using namespace std;
long long  fpow(long long a,long long b,int  mod)
{
	long long ans=1;
	if(mod!=0)
	{
		for(;b;b/=2,a=a*a%mod)
		{
			if(b&1)
			{
				ans=ans*a%mod;
			}
		}
		return ans;
	}
 	else
 	{
 		for(;b;b/=2,a=a*a)
		{
			if(b&1)
			{
				ans=ans*a;
			}
		}
		return ans;
	 }
}
long long n,m,fans;
int main()
{
	cin>>m>>n;
	long long aans=(fpow(m,n,100003)-m*fpow(m-1,n-1,100003)+100003)%100003;
	cout<<(aans+100003)%100003;
	
	
	return 0;
 } 
