#include<bits/stdc++.h>
using namespace std;
struct ui
{
	int nmoney;
	int im;
};
ui thing[100];
int yu,k;
int max_=-9999999;
bool cmp(ui a,ui b)
{
	return a.nmoney<b.nmoney;
}
void sou(int wei,int yu,int zhi)
{
	if(wei==k+1)
	{
		if(zhi>max_)
		{
			max_=zhi;
		}
		return;
	}
	else if(yu<thing[wei].nmoney)
	{
				if(zhi>max_)
		{
			max_=zhi;
		}
		return;
	}
	else
	{
		sou(wei+1,yu-thing[wei].nmoney,zhi+thing[wei].nmoney*thing[wei].im);
		sou(wei+1,yu,zhi);
	}
}
int main()
{
	cin>>yu>>k;
	for(int p=1;p<=k;p++)
	{
		cin>>thing[p].nmoney>>thing[p].im;
	}	
	sort(thing+1,thing+1+k,cmp);
	sou(1,yu,0);
	cout<<max_; 
	
	return 0;
}
