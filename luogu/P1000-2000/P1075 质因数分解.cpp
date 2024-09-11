#include<iostream>
#include<cmath> 
using namespace std;
int a,mn1,d,s,mn2;
int main()
{
	cin>>s;
	for(d=2;d<=sqrt(s);d++)
	{
		if(s%d==0)
		{
				cout<<s/d;
				return 0;
		}
	}
	return 0;
}
