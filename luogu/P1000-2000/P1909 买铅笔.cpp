#include<iostream>
using namespace std;
int a,s,d,max_=10000000,mn1,mn2,qian[5][3];
int main()
{
	cin>>mn2;
	for(mn1=1;mn1<=3;mn1++)
	{
		cin>>qian[mn1][0]>>qian[mn1][1];
		if(mn2%qian[mn1][0]==0&&mn2/qian[mn1][0]*qian[mn1][1]<max_)
		{
			max_=mn2/qian[mn1][0]*qian[mn1][1];
		}
		if(mn2%qian[mn1][0]!=0&&((mn2/qian[mn1][0])+1)*qian[mn1][1]<max_)
		{
			max_=((mn2/qian[mn1][0])+1)*qian[mn1][1];
		}
	}
	cout<<max_;
	return 0;
}
