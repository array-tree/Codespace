#include<bits/stdc++.h>
using namespace std;
struct toy
{
	int face;
	string name;
};
toy toys[120000];
int n,m,a,b;
int point;
int main()
{
//	freopen("P1563_2.in","r",stdin);
	//ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int qq=0;qq<n;qq++)
	{
		cin>>toys[qq].face>>toys[qq].name;
	}
	point=0;
	for(int qq=1;qq<=m;qq++)
	{
		scanf("%d%d",&a,&b);
		if(a==toys[point].face)
		{
			point=(point-b+n)%n;
		}
		else
		{
			point=(point+b)%n;
		}
		//cout<<point<<endl;
	}
	cout<<toys[point].name;
	return 0;
 } 
