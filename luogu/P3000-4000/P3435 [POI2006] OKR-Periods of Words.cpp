#include<bits/stdc++.h>

using namespace std;

const int maxn=1e6+5;
string s1,s2;
int kmp[maxn] ;
int main()
{
	int len2;
	cin >>len2>> s2;
	kmp[0]=-1;
	int j=0,k=-1;
	while(j<len2)
	{
		if(k==-1||s2[j]==s2[k])
		{
			j++,k++;
			kmp[j] = k;
		}
		else
		{
			k=kmp[k];
		}
	}

	long long ans=0;

	for(int i=1;i<=len2;i++)
	{
		int cnt=kmp[i];
		int j=kmp[i];
		while(j>0)
		{
			cnt=j;
			j=kmp[j];
		}
	
		if(cnt)
		{
			kmp[i]=cnt;
			ans+=i-cnt;
		}
		
		
	}
	cout<<ans;
	return 0;
}
