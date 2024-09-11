#include<bits/stdc++.h>
using namespace std;
string a,b;
int aa=1,bb=1;
int main()
{
	cin>>a>>b;
	for(int qwe=0;qwe<a.size();qwe++)
	{
		aa*=a[qwe]-'A'+1;
	}
	for(int qwe=0;qwe<b.size();qwe++)
	{
		bb*=b[qwe]-'A'+1;
	}
	if(aa%47==bb%47)
	{
		cout<<"GO";
	}
	else
	{
		cout<<"STAY";
	}
	return 0;
 } 
