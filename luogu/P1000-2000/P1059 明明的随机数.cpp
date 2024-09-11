#include<iostream>
using namespace std;
int a[10000],s,d,e,w,q,mn;
int main()
{
	cin>>s;
	for(q=0;q<s;q++)
	{
		cin>>d;
		a[d]++;
	}
	for(q=0;q<1010;q++)
	{
		if(a[q]>0)
		{
			mn++;
		}
	}
	cout<<mn<<endl;
	for(q=0;q<1010;q++)
	{
		if(a[q]>0)
		{
			cout<<q<<" ";
		}
	}
	return 0;
 } 
