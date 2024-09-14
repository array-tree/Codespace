#include<bits/stdc++.h>
using namespace std;
long long he;

int main()
{
 ios::sync_with_stdio(false);
 int ep=0;
 int r=0;
while(cin>>ep)
{
	he+=ep;
	r++;
}
r--;
he=he<<r;
cout<<he;



	return 0;
}

