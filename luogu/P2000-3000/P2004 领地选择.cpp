#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
long long  map_[maxn][maxn];
long long m,n,b,max_=-999999,max_x,max_y;
int main()
{
	cin>>m>>n>>b;
	for(int q=1;q<=m;q++)
	{
		for(int w=1;w<=n;w++)
		{
			int op;
			cin>>op;
			map_[q][w]=map_[q][w-1]+map_[q-1][w]-map_[q-1][w-1]+op;
		}
	}
	for(int y=1;y<=m-b+1;y++)
	{
		for(int u=1;u<=n-b+1;u++)
		{
			long long  q=map_[y+b-1][u+b-1]-map_[y-1][u+b-1]-map_[y+b-1][u-1]+map_[y-1][u-1];
			if(q>max_)
			{
				max_=q;
				max_x=y;
				max_y=u;
			}
		}
	}
	
	cout<<max_x<<" "<<max_y;

	return 0;
}

