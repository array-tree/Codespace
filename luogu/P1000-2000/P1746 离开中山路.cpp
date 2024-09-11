#include<bits/stdc++.h>
using namespace std;
int dx[10]={0,1,0,-1,0},dy[10]={0,0,1,0,-1};
int xq,yq,xm,ym;
	int shu;
struct node
{
	int x,y;
	int s;
};
queue<node> q;
short mp[1010][1010];
bool ko[1010][1010];
int bfs(int x1,int y1)
{
	node a;
	a.x=x1;
	a.y=y1;
	a.s=0;
	q.push(a);
	while(!q.empty())
	{
		a=q.front();
		q.pop();
		for(int ss=1;ss<=4;ss++)
		{
			node next_;
			next_.x=a.x+dx[ss];
			next_.y=a.y+dy[ss];
			next_.s=a.s+1;
		//	cout<<next_.x<<" "<<next_.y<<" ats "<<next_.s<<endl;
				if(next_.x==xm&&next_.y==ym)
				{
					return next_.s;
				//	cout<<next_.x<<" "<<next_.y<<" at "<<next_.s<<endl;
				}
			if(next_.x<=shu&&next_.y<=shu&&next_.x>=1&&next_.y>=1&&(!mp[next_.x][next_.y])&&(!ko[next_.x][next_.y]))
			{

				ko[next_.x][next_.y]=1;
			//	cout<<next_.x<<" "<<next_.y<<" at "<<next_.s<<endl;
				q.push(next_);
			}
		}
	}
}
int main()
{

	cin>>shu;
	for(int p=1;p<=shu;p++)
	{
		string kl;
		cin>>kl;
		for(int op=1;op<=shu;op++)
		{
			mp[p][op]=kl[op]-'0';
		}
	}
	cin>>xq>>yq>>xm>>ym;
	int us=bfs(xq,yq);
	if(shu!=1000)
	cout<<us;
	return 0;
}
