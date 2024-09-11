#include <bits/stdc++.h>
using namespace std;
struct renwu
{
	int yu;
	int shu;
	int ying;
	int xue;
	int zong;
};
renwu xuesheng[310];
int s,d,f,r,e;
bool pan(renwu a,renwu b)
{
	if(a.zong>b.zong)
	{
		return 1;
	}
	else if(a.zong<b.zong)
	{
		return 0;
	}
	if(a.zong==b.zong)
	{
		if(a.yu>b.yu)
		{
			return 1;
		}
		else if(a.yu<b.yu)
		{
			return 0;
		}
		else
		{
			if(a.xue>b.xue)
			{
				return 0;
			}
			else
			{
				return 1;
			 } 
		}
	}
}
int main()
{
	cin>>s;
	for(d=0;d<s;d++)
	{
		cin>>xuesheng[d].yu>>xuesheng[d].shu>>xuesheng[d].ying;
		xuesheng[d].zong=xuesheng[d].yu+xuesheng[d].shu+xuesheng[d].ying;
		xuesheng[d].xue=d+1;
	}
	sort(xuesheng,xuesheng+s,pan);
	for(d=0;d<5;d++)
	{
		cout<<xuesheng[d].xue<<" "<<xuesheng[d].zong;
		cout<<endl;
	}
	return 0;
}
