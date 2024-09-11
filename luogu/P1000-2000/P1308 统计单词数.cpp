#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[100000][20],s[1000010],f[20];
int  d,mn1,mn2,mn3,mn4,mn5,mn9=2000000,mn90;
char da(char s)
{
	int p;
	p=int(s);
	p=p+32;
	return char(p);
}
int main()
{
	cin>>f;
	if(f[0]<='Z'||f[0]>='A')
	{
		f[0]=da(f[0]);
		cout<<f[0]<<"000"<<endl;
	}
	cin>>s; 
	mn5=strlen(s);
	for(mn1=0;mn1<mn5;mn1++)
	{
		if(s[mn1]<='Z'&&s[mn1]>='A')
		{
			s[mn1]=da(s[mn1]);

		}
		if(s[mn1]!=' ')
		{

			a[mn4][mn5]=s[mn1];
			mn5++;
		}
		if(mn1>=1)
		if(s[mn1]==' '&&s[mn1-1]!=' ')
		{
			mn90=mn1+1;
			if(f==a[mn4])
			{
				mn3++;
				if(mn9==2000000)
				{
					mn9=mn90;
				}
			}
			mn4++; 
		} 

		
	}
	if(mn3!=0)
	cout<<mn3<<" "<<mn9;
	else
	cout<<-1; 
	return 0;
 } 
