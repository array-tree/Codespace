#include<iostream>
using namespace std;
long a,b,s[100000],ain_,x[100000];
int main()
{
	cin>>a>>b;
	for(int y=0;y<a;y++)
	{
		cin>>ain_;
		s[y]=ain_;
	}
		for(int y=0;y<b;y++)
	{
		cin>>ain_;
		x[y]=ain_;
	}
	for(int y=0;y<a;y++)
	{
		for(int u=0;u<b;u++)
		{
			if(s[y]==x[u])
			{
				cout<<s[y]<<" ";
			}
		}
	}
	return 0;
}
