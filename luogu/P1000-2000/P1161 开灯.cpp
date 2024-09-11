#include<bits/stdc++.h>
using namespace std;
int n;
bool f[3000000];
double x,y; 
int main()
{
	cin>>n;
	for(int qq=1;qq<=n;qq++)
	{
		cin>>x>>y;
		for(double ww=1;ww<=y;ww++)
		{
			f[int(ww*x)]=!f[int(ww*x)];
		}
	}
	for(int qq=1;qq<=0x3f3f3f3f3f;qq++)
	{
		if(f[qq])
		{
			cout<<qq;
			return 0;
		}
	}
	return 0;
} 
