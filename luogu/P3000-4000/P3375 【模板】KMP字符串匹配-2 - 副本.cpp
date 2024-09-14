#include<bits/stdc++.h>

using namespace std;
const int maxn=1e6+5;
char s1[maxn],s2[maxn];
int kmp[maxn];

int main()
{
	cin>>(s1+1)>>(s2+1);
	int len1=strlen(s1+1);
	int len2=strlen(s2+1);
	
	
	for(int j=2,k=0;j<=len2;j++)
	{
		while(k&&s2[j]!=s2[k+1])k=kmp[k];
		if(s2[j]==s2[k+1])k++;
		kmp[j]=k;
	}
	for(int i=1,j=0;i<=len1;i++)
	{
		while(j&&s1[i]!=s2[j+1])j=kmp[j];
		if(s1[i]==s2[j+1])j++;
		if(j==len2)
		{
			printf("%d\n",i-len2+1);
			j=kmp[j];
		}
	}
	for(int i=1;i<=len2;i++)
	{
		printf("%d ",kmp[i]);
	}
	return 0;
}

