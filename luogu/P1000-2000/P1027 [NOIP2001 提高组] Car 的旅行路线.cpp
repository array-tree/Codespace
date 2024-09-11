#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define maxx 999999999
struct airport
{
	int x,y;
};
int tf,tr,s,n,a,b,air;
int xxxx[10],yyyy[10];
airport airs[800];
double map_[1005][1005],ans;
void start_()
{
	memset(airs,0,sizeof(airs));
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			if(i==j)
			{
				map_[i][j]=0;
			}
			else
			{
				map_[i][j]=999999999;
			}
		}
	}
	air=0;
	ans=999999999999;
}
int dis2(int x1,int y1,int x2,int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void get_4()
{
	int ab=dis2(xxxx[1],yyyy[1],xxxx[2],yyyy[2]);
	int ac=dis2(xxxx[1],yyyy[1],xxxx[3],yyyy[3]);
	int bc=dis2(xxxx[2],yyyy[2],xxxx[3],yyyy[3]);
	if(ab+ac==bc)
	{
		xxxx[4]=xxxx[3]-xxxx[1]+xxxx[2],yyyy[4]=yyyy[3]-yyyy[1]+yyyy[2];
	}
	if(ab+bc==ac)
	{
		xxxx[4]=xxxx[3]+xxxx[1]-xxxx[2],yyyy[4]=yyyy[3]+yyyy[1]-yyyy[2];
	}
	if(ac+bc==ab)
	{
		xxxx[4]=xxxx[1]+xxxx[2]-xxxx[3],yyyy[4]=yyyy[1]+yyyy[2]-yyyy[3];
	}
	return; 
}

void Folyd()
{
	for(int k=1;k<=air;k++)
	{
		for(int i=1;i<=air;i++)
		{
			for(int j=1;j<=air;j++)
			{
				map_[i][j]=min(map_[i][j],map_[i][k]+map_[k][j]);
			}
		}
	}
}
void addrail(int a,int b,int x[],int y[])
{
	int ra=a+air;
	int rb=b+air;
	airs[ra].x=x[a];
	airs[ra].y=y[a];
	airs[rb].x=x[b];
	airs[rb].y=y[b];
	if(map_[ra][rb]!=maxx)
	{
		return;
	}
	map_[ra][rb]=tr*sqrt((airs[ra].x-airs[rb].x)*(airs[ra].x-airs[rb].x)+(airs[ra].y-airs[rb].y)*(airs[ra].y-airs[rb].y)); 
	map_[rb][ra]=map_[ra][rb];
}
void addflight(int a,int b)
{
	if(map_[a][b]!=maxx)
	{
		return;
	}
	map_[a][b]=tf*sqrt((airs[a].x-airs[b].x)*(airs[a].x-airs[b].x)+(airs[a].y-airs[b].y)*(airs[a].y-airs[b].y));
	map_[b][a]=map_[a][b];
}
int main()
{
	cin>>n;
	for(int qw=1;qw<=n;qw++)
	{
		start_();
		scanf("%d%d%d%d",&s,&tf,&a,&b);
		for(int ww=1;ww<=s;ww++)
		{
			scanf("%d%d%d%d%d%d%d",&xxxx[1],&yyyy[1],&xxxx[2],&yyyy[2],&xxxx[3],&yyyy[3],&tr);
			get_4();
			for(int j=1;j<=4;j++)
			{
				for(int yu=1;yu<=4;yu++)
				{
					if(j!=yu)
					{
						addrail(j,yu,xxxx,yyyy);
					}
					
				}
			}
			air+=4;
		}
		for(int i=1;i<=air;i++)
		{
			for(int j=1;j<=air;j++)
			{
				addflight(i,j);
			}
		 } 
		Folyd();
	//	for(int i=1;i<=air;i++)
	//	{
	//		for(int j=1;j<=air;j++)
	//		{
	//			printf("%.1lf ",map_[i][j]);
	//		}
	//		cout<<endl;
	//	}
		for(int i=a*4-3;i<=a*4;i++)
		{
			for(int j=b*4-3;j<=b*4;j++)
			{
				ans=min(ans,map_[i][j]);
			}
		}
		printf("%.1lf\n",ans);
	}
	return  0;
} 
