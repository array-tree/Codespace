#include<bits/stdc++.h>
using namespace std;
int x1,x2,y1s,y2;
struct node
{
	int x,y;
	int s;
};
int dx[15]={-2,-1,1,2,2,2,2,1,-1,-2,2,-2},
	dy[15]={2,2,2,2,1,-1,-2,-2,-2,-2,1,-1};
bool b[900][900];
queue<node> q;
int sou(int x,int y)
{
	node kl;
	kl.x=x;
	kl.y=y;
	kl.s=0;
	q.push(kl);
	while(!q.empty())
	{
		
		kl=q.front();
		q.pop();
		for(int i=0;i<=11;i++)
		{
			node next_p;
			next_p.x=kl.x+dx[i];
			next_p.y=kl.y+dy[i];
			next_p.s=kl.s+1;
			if((next_p.x>=1)&&next_p.y>=1&&b[next_p.x][next_p.y]==0)
			{
				if(next_p.x==1&&next_p.y==1)
				{		
					return next_p.s;
				}
				b[next_p.x][next_p.y]=1;				
				q.push(next_p);
			}
		}
	}
	return 0;
}
int main()
{
	
	cin>>x1>>y1s>>x2>>y2;
	cout<<sou(x1,y1s)<<endl;
	for(int p=0;p<=890;p++)
	{
		for(int u=0;u<=890;u++)
		{
			b[p][u]=0;
		}
	}
	while(!q.empty())
	{
		q.pop();
	}
	cout<<sou(x2,y2);
	
	
	
	
	return 0;
}
