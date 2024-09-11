#include<bits/stdc++.h>
using namespace std;

long long x[10001],y[10001];
double jie,jie2=999999999;
int r;

int main()
{
	cin>>r;
	for(int mn=0;mn<r;mn++)
	{
		cin>>x[mn]>>y[mn];
	}
	for(int mn=0;mn<r-1;mn++)
	{
		for(int mn2=mn+1;mn2<r;mn2++)
		{
			long long chang =labs(x[mn]-x[mn2])*labs(x[mn]-x[mn2]);
			long long gao =labs(y[mn]-y[mn2])*labs(y[mn]-y[mn2]);
			jie=sqrt(chang+gao);
			if(jie<jie2)
			{
				jie2=jie;
			}
		}
	}

	printf("%.4f",jie2);
	return 0;
}
