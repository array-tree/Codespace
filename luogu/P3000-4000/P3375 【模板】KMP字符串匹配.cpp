



























#include<bits/stdc++.h>
using namespace std;
string p,s;
int nexts[100000];int ans;
int main()
{
	cin>>s>>p;
	for(int i=1,j=0;i<p.length();++i)
	{
		while(j&&p[i] != p[j])
		{
			j = nexts[j-1];
		}
		if(p[i]==p[j])     j++;
		nexts[i]=j;
	} 
	for(int i=0,j=0;i<s.length();++i)
	{
		while(j&&s[i]!=p[j])
		{
			j=nexts[j-1];
		}
		if(s[i]==p[j])  j++;
		if(j==p.length())
		{
			cout<<i-j+2<<endl;
			j=nexts[j-1];
		}
	}
	for(int we=0;we<p.length();we++)
	cout<<nexts[we]<<" ";
	return 0;
}
