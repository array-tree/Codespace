#include<bits/stdc++.h>
using namespace std;
int qq[10000];
int qqq,qqw;
int qt[10000];
int qtq,qtw;
int shu;
int ying;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	cin>>shu;
	qqq=1;qqw=shu;
	qtq=1;qtw=shu;
	for(int i=1;i<=shu;i++)
	{
		int o;
		cin>>o;
		qt[i]=o;
	}
	for(int i=1;i<=shu;i++)
	{
		int o;
		cin>>o;
		qq[i]=o;
	}	
	sort(qq+1,qq+1+shu,cmp);
	sort(qt+1,qt+1+shu,cmp);
	for(int i=1;i<=shu;i++)
	{
		if(qq[qqq]<qt[qtq])
		{
			qqq++;qtq++;
			ying++;
		}
		else if(qq[qqq]==qt[qtq])
		{
			if(qq[qqw]<qt[qtw])
			{
				qqw--;qtw--;
				ying++;
			}
			else
			{
				if(qq[qqq]>qt[qtw])
				{
					ying--;
					qqq++;
					qtw--;
				}
				else if(qq[qqq]==qt[qtw])
				{
					qqq++;qtw--;
				}
				else
				{
					ying++;
					qqq++;qtw--;
				}
			}
		}
		else
		{
			ying--;
			qtw--;
			qqq++;
		}
	}
	
	cout<<ying*200;
	return 0;
}
