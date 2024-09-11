#include<iostream>
using namespace std;
int max_,f[1001];
int main()
{
	int a;
	cin>>a;
	f[1]=1;
	f[2]=2;
	f[3]=2;
	for(int e=4;e<=1000;e++)
	{
		if(e%2==0)
		{
			f[e]=f[e-1]+f[e/2];
		}
		else
		{
			f[e]=f[e-1];
		}
	}
	cout<<f[a];
	return 0;
}
