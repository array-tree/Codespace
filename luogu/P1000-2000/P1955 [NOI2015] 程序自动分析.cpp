#include<bits/stdc++.h>
using namespace std;
int n,t;
struct as
{
	int a,b,c;
};
as jin[1001000];
int gin[2010000];
int xu[2010000];
int fa[2000100];
int cnt;
int fnd(int x)
{
	int r=x;
	while(fa[r]!=r)
	{
		r=fa[r];
	}
	while(x!=r)
	{
		int q=fa[x];
		fa[x]=r;
		x=q;
	}
	return r;
	
}
int cnt2;
int my_find(int x)
{
	return lower_bound(xu+1,xu+cnt2+1,x)-xu;
}
bool cmp(as aa,as b)
{
	return aa.c>b.c;
 } 
bool flag,flag2;

void RD()
{
	for(int qwe=1;qwe<=cnt;qwe++)
	{
		if(qwe==1||gin[qwe]!=gin[qwe-1])
		{
			xu[++cnt2]=gin[qwe];
		}
	}
}
void setfa()
{
	for(int qww=1;qww<=n*2;qww++)
	{
		fa[qww]=qww;
	}
}
int main()
{
	freopen("P1955_2.in","r",stdin);
	cin>>t;
	for(int qq=1;qq<=t;qq++) 
	{
		cnt=0;
		cnt2=0;
		flag=1;
		flag2=1;
		cin>>n;
		for(int we=1;we<=n;we++)
		{
			scanf("%d%d%d",&jin[we].a,&jin[we].b,&jin[we].c);
			gin[++cnt]=jin[we].a;
			gin[++cnt]=jin[we].b;
		}
		sort(jin+1,jin+1+n,cmp);
		sort(gin+1,gin+1+cnt);
		RD();
		setfa();
		//cout<<"wadwadwadawdaw    "<<cnt<<" "<<cnt2<<endl;
	//	for(int qq=1;qq<=n;qq++)
	//	{
	///		cout<<jin[qq].a<<" "<<jin[qq].b<<" "<<jin[qq].c<<endl;
	//	}
	//	cout<<endl;
	//	for(int qq=1;qq<=cnt2;qq++)
	//	{
	//		cout<<my_find(xu[qq])<<" ";
	//	}
	//	cout<<endl;
		for(int we=1;we<=n;we++)
		{
			int x=my_find(jin[we].a),y=my_find(jin[we].b);
			int fx=fnd(x);
			int fy=fnd(y);
			if(jin[we].c==1)
			{
			
				fa[fx]=fy;
			}
			else if(fx==fy)
			{
			//	cout<<fx<<" "<<jin[we].a<<" "<<fy<<" "<<jin[we].b<<endl; 
				flag=0;
				cout<<"NO"<<endl;	
				break;
			}
		}	
		
		if(flag)
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
} 
