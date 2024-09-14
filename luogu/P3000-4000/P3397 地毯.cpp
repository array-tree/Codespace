#include<bits/stdc++.h>
using namespace std;
int map_[1010][1010];
int m,n;
int main()
{
	cin>>n>>m;
	for(int o=1;o<=m;o++)
	{
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int w=x1;w<=x2;w++)
		{
			for(int e=y1;e<=y2;e++)
			{
				map_[w][e]++;
			}
		}
	}
	
	
	for(int o=1;o<=n;o++)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<map_[o][i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
