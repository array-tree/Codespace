#include<bits/stdc++.h>
using namespace std;
bool gg[100000001];
int shu[10000];
int n;
int main()
{
	cin>>n;
	for(int qq=1;qq<=n;qq++)
	{
		cin>>shu[qq];
	}
	for(int qq=2;qq<=n;qq++)
	{
		gg[abs(shu[qq]-shu[qq-1])]=1;
	}
	for(int qq=1;qq<n;qq++)
	{
		if(!gg[qq])
		{
			cout<<"Not jolly"<<endl;
			return 0;
		}
	}
	cout<<"Jolly";
	
	return 0;
}
