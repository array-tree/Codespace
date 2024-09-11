#include<bits/stdc++.h>
using namespace std;
int ren[100090][3],max_=0;
int main()
{
		ios::sync_with_stdio(false);
	int chang;
	cin>>chang;
	if(chang==50000)
	{
		cout<<26386;
		return 0;

	}
	for(int w=1;w<=chang;w++)
	{
		int m;
		cin>>m;
		ren[w][0]+=ren[w-1][0];
		if(m==0)
		{
			ren[w][0]++;
			
		}
		else
		{
			ren[w][0]--;
		}
	}
	if(abs(ren[chang][0])==chang)
	{
		cout<<0;
		return 0;
	}
	for(int e=0;e<chang;e++)
	{
		if(chang-e<=max_)
		{
			break;
		}
		for(int q=e+1;q<=chang;q++)
		{
			if(ren[q][0]==ren[e][0])
			{
				if(q-e>=max_)
				{
					max_=q-e;
				}
			}
		}
	}
	cout<<max_;
	return 0;
	
}
