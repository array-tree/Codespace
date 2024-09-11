#include<iostream>
using namespace std;
int a[10000],b[10000],max_,mn1,mn2,mn3;
int main()
{
	for(mn1=1;mn1<=7;mn1++)
	{
		cin>>a[mn1]>>b[mn1];
		if(a[mn1]+b[mn1]>8&&a[mn1]+b[mn1]-8>max_)
		{
			max_=a[mn1]+b[mn1]-8;
			mn3=mn1;
		}
	}
	cout<<mn3;
	return 0;
}
