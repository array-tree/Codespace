#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll temp,x,y;
ll gcd(ll a,ll b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return gcd(b,a%b);
	 } 
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	temp=exgcd(b,a%b,x,y);
	ll temp2=x;
	x=y;
	y=temp2-a/b*y;
	return temp;
}
ll  ax,ay,m,n,l;
ll qwe,asd;
int main()
{
	cin>>ax>>ay>>m>>n>>l;
	qwe=n-m;
	asd=ax-ay;
	if(qwe<0)
	{
		qwe*=-1;
		asd*=-1;
	}
	exgcd(qwe,l,x,y);
	if(asd%temp!=0)
	{
		cout<<"Impossible"<<endl;
	}
	else
	{
		//cout<<l/temp<<endl;
		cout<<((x*(asd/temp))%(l/temp)+(l/temp))%(l/temp);
	}
	return 0;
}
