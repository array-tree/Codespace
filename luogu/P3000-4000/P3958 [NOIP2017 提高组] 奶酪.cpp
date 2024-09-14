#include<bits/stdc++.h>
using namespace std;
#define ll  long long 
int fa[10000];	
long long  r;	
ll t,n,h;
struct ball
{
	ll  x,y,z;
};
ball balls[11000];
int fnd(int x)
{
	if(x!=fa[x])
	{
		fa[x]=fnd(fa[x]);
	}
	return fa[x];
}
long long dis(ll x1,ll y1,ll z1,ll x2,ll y2,ll z2)
{
	ll hhh= (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
	return hhh;
}
void pts()//prepare to start ²¢²é¼¯ 
{
	for(int op=1;op<=n;op++)
	{
		fa[op]=op;	
	}	
} 	

ll  top[100000],front[100000];
ll  cnt1,cnt2,flag2;
int main()
{
	cin>>t;
	bool sf1,sf2;
	for(int qq=1;qq<=t;qq++)
	{
		cnt1=0;cnt2=0;
		cin>>n>>h>>r;
		sf1=1;
		sf2=1;
		flag2=0;		
		int flag=1; 
		for(int ss=1;ss<=n;ss++)
		{
			scanf("%lld%lld%lld",&balls[ss].x,&balls[ss].y,&balls[ss].z);
			if(balls[ss].z-r<=0)
			{
				 front[++cnt2]=ss;
				 sf2=0;
			}
			if(balls[ss].z+r>=h)
			{
				top[++cnt1]=ss;
				sf1=0;
			}
			if(!sf2&&!sf1)
			{
			//	cout<<"bianhao is "<<ss<<endl;
				flag2=1;
			}
		}
		pts();
		for(int j=1;j<n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				int fx=fnd(j),fy=fnd(k);
				long long ww=4LL*r*r;
				if(ww>=dis(balls[j].x,balls[j].y,balls[j].z,balls[k].x,balls[k].y,balls[k].z))
				{
					fa[fx]=fy;
				} 
			}
		} 

		for(int j=1;j<=cnt1;j++)
		{
			for(int k=1;k<=cnt2;k++)
			{
				int fx=fnd(top[j]),fy=fnd(front[k]);
				if(fx==fy)
				{
					flag=0;
					cout<<"Yes"<<endl;
					break;
				}
			}

			if(flag==0)
			{
				break;
			}
		}
	//	cout<<flag2<<endl;
		if(flag)
		{
			cout<<"No"<<endl;
		}
	}

	
	return 0;
}
