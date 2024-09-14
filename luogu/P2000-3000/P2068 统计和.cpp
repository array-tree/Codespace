#include<iostream> 
using namespace std;
int shu[100001],jie[90000],max,mn1,mn2,n,w,l;
char m;
int main()
{
	cin>>n;
	cin>>w;
	for(int u=0;u<w;u++)
	{
		cin>>m>>mn1>>mn2;
		if(m=='x')
		{
			shu[mn1]+=mn2; 
		}
		else if(m=='y')
		{
			for(int w=mn1;w<=mn2;w++)
			{
				jie[l]+=shu[w];
				cout<<jie[l]<<endl;
			}
			l++;
		}
	}
	return 0;
}
