#include<iostream>
using namespace std;
long long a[1000000],s,d;
int main()
{
	cin>>s;
	a[1]=1;
	a[2]=1;
	for(d=3;d<=s;d++)
	{
		a[d]=a[d-1]+a[d-2];
	}
	cout<<a[s]<<".00";
	return 0;
 } 
