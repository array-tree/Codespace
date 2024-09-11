#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string w;
char wen[maxn];
int op=1,max_,ans;
void _myfind()
{

	for(int e=0;e<strlen(wen)-w.size();e++)
	{
			int i=0,k=0;
		
		while(w[i]==wen[e+i])
		{
			i++;
			if(i>w.size())
			{
				break;
			}
		}
		if(i==w.size()+1)
		{
			if(op)
			{
				ans=e;
		
				op=0;
				 max_++;
			}
			max_++;
		}
	}
	if(!max_)
	{
		cout<<-1;
	}
	else
	{
		cout<<max_-1<<" ";
		cout<<ans;
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>w;
	gets(wen);	
	for(int q=0;q<w.size();q++)
	{
		if(w[q]>=65&&w[q]<=90)
		{
			w[q]+=32;
		}
	}
		for(int q=0;q<strlen(wen);q++)
	{
		if(wen[q]>=65&&wen[q]<=90)
		{
			wen[q]+=32;
		}
	}
	_myfind();	
		
		
	return 0;
}
