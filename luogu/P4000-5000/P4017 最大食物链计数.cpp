#include<bits/stdc++.h>
using namespace std;
const int mods=80112002;
queue<int> q;
int inx[10000],outx[10000];
bool mp[5010][5010];
int shu1,shu2;
int ans;
int num[10000];
int main()
{
//	freopen("P4017_5.in","r",stdin);
	cin>>shu1>>shu2;
	for(int p=1;p<=shu2;p++)
	{
		int a,b;
		cin>>a>>b;
		inx[b]++;
		outx[a]++;
		mp[a][b]=1;
		
	}
	for(int c=1;c<=shu1;c++)
	{
		if(!inx[c])
		{
			num[c]=1;
			q.push(c);
			
		}
	}
	while(!q.empty())
	{
		int tot=q.front();
		q.pop();
	//	cout<<tot<<" tot now"<<endl;
		for(int o=1;o<=shu1;o++)
		{
			if(mp[tot][o])
			{
				inx[o]--;
				num[o]=(num[o]+num[tot])%mods;
				if(!inx[o])
				{
					q.push(o);
				}
			}
		}
	}
	for(int x=1;x<=shu1;x++)
	{
		if(outx[x]==0)
		{
			ans=(ans+num[x])%mods;
		}
	}
	cout<<ans;
	
	
	
	return 0;
 } 
 
