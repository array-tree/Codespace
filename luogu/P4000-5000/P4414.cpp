#include<bits/stdc++.h>
using namespace std;
int a,b,c;
bool q,w,e;
int A,B,C;
string  abc;
int main()
{
	cin>>a>>b>>c;
	A=min(a,min(b,c));
	
	C=max(a,max(b,c));
	if((A==a||A==c)&&(C==a||C==c))
	{
		B=b;
	}
		if((A==b||A==c)&&(C==b||C==c))
	{
		B=a;
	}
		if((A==a||A==b)&&(C==a||C==b))
	{
		B=c;
	}
	//cout<<A<<" "<<B<<" "<<C<<endl;
	cin>>abc;
	for(int h=0;h<3;h++)
	{
		if(abc[h]=='A')
		{
			cout<<A<<" ";
		}
		if(abc[h]=='B')
		{
			cout<<B<<" ";
		}
		else
		{
			cout<<C<<" ";
		}
	}
}
