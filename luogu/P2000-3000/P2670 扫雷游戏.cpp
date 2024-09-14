#include<iostream>
using namespace std;
int s,w,q,mn1,mn2,b1,b2,b3;
int  a[110][110];
char e;
int main()
{
	cin>>mn1>>mn2;
	for(b1=1;b1<=mn1;b1++)
	{
		for(b2=1;b2<=mn2;b2++)
		{
			cin>>e;
			if(e=='*')
			{
				a[b1][b2]=1;
			}
		}
	}
	for(b1=1;b1<=mn1;b1++)
	{
		for(b2=1;b2<=mn2;b2++)
		{
			if(a[b1][b2]==1)
			{
				cout<<"*";
			}
			else
			{
				b3=a[b1-1][b2-1]+a[b1-1][b2]+a[b1][b2-1]+a[b1+1][b2+1]+a[b1+1][b2]+a[b1][b2+1]+a[b1+1][b2-1]+a[b1-1][b2+1];
				cout<<b3;
			}
		}
		cout<<endl;
	}
	return 0;
}
