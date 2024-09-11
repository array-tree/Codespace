#include<bits/stdc++.h>
using namespace std;
int now_a,now_b;
int n,a,b,wa[1000],wb[1000],ansa,ansb;
int win_[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main()
{
	cin>>n>>a>>b;
	for(int qq=0;qq<a;qq++)
	{
		cin>>wa[qq];
	}	
	for(int qq=0;qq<b;qq++)
	{
		cin>>wb[qq]; 
	}
	for(int qq=0;qq<n;qq++)
	{
		now_a=wa[qq%a];
		now_b=wb[qq%b];
		ansb+=win_[now_b][now_a];
		ansa+=win_[now_a][now_b];
	}
	cout<<ansa<<" "<<ansb;
	
	
	return 0;
}
