#include<bits/stdc++.h>
using namespace std;
int n,m;
int shu[1010][1010];
bool biao[1010][1010];
int ans=0;
int max_;
string d; 
void lian(int x,int y)
{
	if(shu[x-1][y]==1&&!biao[x-1][y])
	{
		ans++;
		biao[x-1][y]=1;
		lian(x-1,y);
	}
	if(shu[x+1][y]==1&&!biao[x+1][y])
	{
		ans++;
		biao[x+1][y]=1;
		lian(x+1,y);
	}
	if(shu[x][y-1]==1&&!biao[x][y-1])
	{
		ans++;
		biao[x][y-1]=1;
		lian(x,y-1);
	}
	if(shu[x][y+1]==1&&!biao[x][y+1])
	{
		ans++;
		biao[x][y+1]=1;
		lian(x,y+1);
	}
}
int main()
{

	cin>>n>>m;
	for(int vb=1;vb<=n;vb++)
	{
		cin>>d;
		for(int vc=0;vc<m;vc++)
		{
			if(d[vc]=='O')
			{
				shu[vb][vc]=1;
			}
			else
			{
				biao[vb][vc]=1;
				shu[vb][vc]=0;
			}
			
		}
	}	
	for(int vb=1;vb<=n;vb++)
	{
		for(int vc=1;vc<=m;vc++)
		{
			if(shu[vb][vc]&&!biao[vb][vc]&&(vb==1||vc==1||vc==m||vb==n))
			{
				ans=1;
				biao[vb][vc]=1;
				lian(vb,vc);
				max_=max(ans,max_);
			}
		}
	}
	ans=0;
	for(int vb=1;vb<=n;vb++)
	{
		for(int vc=1;vc<=m;vc++)
		{
			if(!biao[vb][vc])
			{
				ans++;
			}
		}
	}
	cout<<ans;
	
	
	
	
	
	return 0;
}
