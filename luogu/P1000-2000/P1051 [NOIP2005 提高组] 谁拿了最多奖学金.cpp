#include<bits/stdc++.h>
using namespace std;
struct  ren
{
	string name;
	int qchen;
	int bchen;
	char ban;
	char xi;
	int lun;
	int xu;
	int jing=0;
};
ren renwu[101]; 
int m,n,b,jilu;
int main()
{
	cin>>m;
	for(int e=0;e<m;e++)
	{
		cin>>renwu[e].name>>renwu[e].qchen>>renwu[e].bchen>>renwu[e].ban>>renwu[e].xi>>renwu[e].lun;
		renwu[e].xu=e+1;
	}
	for(int e=0;e<m;e++)
	{
		if(renwu[e].qchen>80&&renwu[e].lun>=1)
		{
			renwu[e].jing+=8000;
		}
		if(renwu[e].qchen>85&&renwu[e].bchen>80)
		{
			renwu[e].jing+=4000;
		}
		if(renwu[e].qchen>90)
		{
			renwu[e].jing+=2000;
		}
		if(renwu[e].qchen>85&&renwu[e].xi=='Y')
		{
			renwu[e].jing+=1000;
		}
		if(renwu[e].bchen>80&&renwu[e].ban=='Y')
		{
			renwu[e].jing+=850;
		}
		if(renwu[e].jing>jilu)
		{
			jilu=renwu[e].jing;
			b=renwu[e].xu;
		}
		n+=renwu[e].jing;
	}
	cout<<renwu[b-1].name<<endl;
	cout<<renwu[b-1].jing<<endl;
	cout<<n<<endl;
	return 0;
}
