#include <bits/stdc++.h>
using namespace std;
int shu[100000],xu[100000],d,e,w,q[100000],mn1,mn2,mn3,mn4[10000],mn5,mn6;
int main()
{
	cin>>d>>e;
	for(w=0;w<d;w++)
	{
		cin>>shu[w];
	}
	for(w=0;w<e;w++)
	{
		cin>>q[w];
		cin>>xu[w];
	}
	for(w=0;w<e;w++)
	{
		for(mn2=0;mn2<d;mn2++)
		{
			mn3=shu[mn2];
			mn4[mn2]=mn3%10;
			mn3=mn3/10;
			mn6++;
			while(mn6!=q[mn2])
			{
				mn4=mn4+mn
			}
		}
	 }
	
}
