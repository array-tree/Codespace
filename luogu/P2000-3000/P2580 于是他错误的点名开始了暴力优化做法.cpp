#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b)
{
	return a.size()>b.size();
}
string h[1000010];
bool h1[1000010];
int chang[52];
int main()
{
	ios::sync_with_stdio(false);
	int y;
	cin>>y;
	for(int o=0;o<y;o++)
	{
		cin>>h[o];
	}
	int w=0;
	string hd;
	sort(h,h+y+1,cmp);
	for(int w=0;w<y;w++)
	{
		chang[h[w].size()]=w;
	}

	cin>>w;
	for(int q=0;q<w;q++)
	{
		cin>>hd;
		int e=0;
		int qw=hd.size();
		for(int o=chang[hd.size()];o>=0;o--)
		{
			if(h[o].size()!=qw)
			{
				break;
			}
			if(hd==h[o])
			{
				if(!h1[o])
				{
					h1[o]=1;
					cout<<"OK"<<endl;
					e=1;
					break;
				}
				else
				{
					cout<<"REPEAT"<<endl;
					e=1;
					break; 
				 } 
			}
		}
		if(!e)
		{
			cout<<"WRONG"<<endl;
		}
	}
	
	
	
	
	
	return 0;
}
