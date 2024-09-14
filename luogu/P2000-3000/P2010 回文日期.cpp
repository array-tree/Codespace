#include <bits/stdc++.h>
using namespace std;
int a[13]={0,31,29,31,30,31,30,31,31,30,31,30,31},k[3670];
int s,d,f,g,max_,mn1,mn2;
int main()
{
	scanf("%d%d",&f,&s);
	for(mn1=1;mn1<=12;mn1++)
	{
		for(mn2=1;mn2<=a[mn1];mn2++)
		{
			g=(mn2%10)*1000+(mn2/10)*100+(mn1%10)*10+(mn1/10);
			k[++d]=g*10000+mn1*100+mn2; 
			if(k[d]<f||k[d]>s)
			{
				continue;
			}
			max_++;
		}
	}
	cout<<max_;
	return 0;
}
