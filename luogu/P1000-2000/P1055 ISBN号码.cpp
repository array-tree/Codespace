#include<iostream>
#include<cstdio> 
using namespace std;
int a,max_,max_2,mn1,mn2,mn3,s,b,c;
char mn5,mn6;
int main()
{
	scanf("%d-%d-%d-%c",&a,&b,&c,&mn5);
	if(mn5=='X')
	{
		mn1=10;
	}
	else
	{
		mn1=mn5-48;
	}
	mn2=( a * 1000 ) +b* 100000 + c;
	for(mn3=0;mn3<9;mn3++)
	{
		s=mn2%10*(9-mn3);
		cout<<s<<" ";
		s=s%11;
		mn2=mn2/10;
		cout<<s<<endl;
	}
	if(s==mn1)
	{
				cout<<a<<"-"<<b<<"-"<<c<<"-";
		if(s==10)
		{
			cout<<"X";
		}
		else
		{
			cout<<s; 
		}
	}
	else
	{	
cout<<"Right";
	}
	return 0;
}
