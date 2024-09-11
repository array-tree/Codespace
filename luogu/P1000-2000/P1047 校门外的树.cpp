#include<iostream>
using namespace std;
int a[100000],s,d,e,w[1000][3],max_,mn1,mn2;
int main()
{
	cin>>s>>d;
	for(e=0;e<d;e++)
	{
		cin>>w[e][0]>>w[e][1];
		for(mn1=w[e][0];mn1<=w[e][1];mn1++)
		{
			if(a[mn1]==0)
			{
				a[mn1]=1;
				max_++;
			}
		}
	}
	mn2=s+1-max_;
	cout<<mn2;
	return 0;
 } 
