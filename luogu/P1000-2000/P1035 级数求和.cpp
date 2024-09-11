#include<iostream>
using namespace std;
int mn1,mn2,mn3,mn4,mn5=1;
double max_1,max_2;
int main()
{
	cin>>max_2;
	while(max_1<=max_2)
	{
		max_1+=1.0/mn5;
		mn5++; 
	}
	cout<<mn5-1;
	return 0;
 } 
