#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char w[maxn];
char wen[maxn];
int wp;
int kmp[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin>>(w+1)>>(wen+1);
	int len1=strlen(wen+1);
	int len2=strlen(w+1);
	 
	for(int j=2,k=0;j<=len2;j++)
	{
		while(k&&w[j]!=w[k+1])k=kmp[k];
		if(w[j]==w[k+1])k++;
		kmp[j]=k;
	}
	int y=1;
	for(int i=1,j=0;i<=len1;i++)
	{
		while(j&&wen[i]!=w[j+1])j=kmp[j];
		if(wen[i]==w[j+1])j++;
		if(j==len2&&y)
		{
			cout<<i-j<<" ";
			wp++;
			y=0;
		}
		else if(j==len2)
		{
			wp++;
		}
		
	}
	cout<<wp;
	return 0;
}
