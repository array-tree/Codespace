#include<bits/stdc++.h>
using namespace std;
double a,mn1,mn2,mn3,mn4,yue=9999;
int q,w,e;
int main()
{
	cin>>mn1>>mn2;
	int chi;
	cin>>chi;
	for(double ls1=1;ls1<=chi;ls1++)
	{
		for(double ls2=1;ls2<=chi;ls2++)
		{
			a=ls1/ls2-mn1/mn2;
			if(a<yue&&a>=0)
			{
				yue=a;
				mn3=ls1;
				mn4=ls2;
			}
		}
	}
	cout<<mn3<<" "<<mn4;
	return 0;
} 
