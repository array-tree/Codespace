#include<bits/stdc++.h>
using namespace std;
int zshu,xshu;
int jilu[2010][2010];//jilu¡¾×é¡¿¡¾ÏîÄ¿¡¿£» 

int main()
{
	cin>>xshu>>zshu;
	for(int p=1;p<=zshu;p++)
	{
		for(int z=1;z<=xshu;z++)
		{
			cin>>jilu[p][z];
		}
		
	}
	for(int z=xshu;z>=2;z--)
	{
		for(int p=1;p<=zshu;p++)
		{
			if(p==zshu)
			{
				jilu[p][z-1]=min(jilu[p][z],jilu[1][z])+jilu[p][z-1];
			}
			else
			{
				jilu[p][z-1]=min(jilu[p][z],jilu[p+1][z])+jilu[p][z-1];
			 } 
		}
	}
	int min_=99999999;
	for(int o=1;o<=zshu;o++)
	{
		if(jilu[o][1]<min_)
		{
			min_=jilu[o][1];
		}
	}
	cout<<min_;
	return 0;
}
