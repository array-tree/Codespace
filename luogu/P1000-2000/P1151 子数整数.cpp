#include<bits/stdc++.h>
using namespace std;
int k;
int a1,a2,a3;
int flag;
int main()
{
	cin>>k;
	for(int o=10000;o<=30000;o++)
	{
		a1=o/100;
		a2=(o/10)%1000;
		a3=o%1000;
		if(a1%k==0&&a2%k==0&&a3%k==0)
		{
			flag=1;
			cout<<o<<endl;
		}
	}
	if(!flag)
	{
		cout<<"No"<<endl;
	}
	
	return 0;
}
