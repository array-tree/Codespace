#include<iostream>
using namespace std;
int n,shu,op1,op2;
int ll[10000];
 
int main()
{
	cin>>n;
	cin>>shu;
	int ui=0;
	while(ui!=-1)
	{
		cin>>ui;
		ll[ui]=1;
	}
	ui=0;
	while(ui!=-1)
	{
		cin>>ui;
		ll[ui]=-1;
	}
	for(int s1=0;s1<=shu;s1++)
	{
		for(int s2=0;s1<=shu-s2;s1++)
		{
			for(int s3=0;s1<=shu;s1++)
			{
				int s4=shu-s1-s2-s3;
			}
		}
	}
	return 0;
 } 
