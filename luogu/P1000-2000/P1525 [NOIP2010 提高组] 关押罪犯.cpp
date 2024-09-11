//SSYJS 5-14 练习 
#include<bits/stdc++.h>
using namespace std;
int fread()
{
	char ch;
	int x=0, flag = 1;//flag是正负数标记 
	ch= getchar();//读取一个字符，注意空格、换行符也算字符 
	while(ch<'0' || ch>'9')//负号保留，去除数字前的其他无用字符
	{
		if(ch == '-')flag = -1;
		ch = getchar();
	}
	
	while(ch>='0' && ch<='9')//按字符读取数字 
	{
		x= x*10+(ch-'0');//与字符‘0’相减得到对应数字 
		ch = getchar(); 
	}
	return x*flag;//记得跟正负号标记相乘 
}
int fa[20010];//记录友好的关系 
int size[20010];//启发式合并的数组 
int enemy[20010];//记录敌对关系的集合情况 
struct node
{
	int from; 
	int to;
	int sum;//仇恨值 
}nd[100010];
int myfin(int x)
{
	if(fa[x] == x)return x;
	fa[x] = myfin(fa[x]);//路径压缩掉 
	return fa[x];
}
bool cmp(node a,node b)//给sort用的cmp 
{
	return a.sum>b.sum;
}
int main()
{
	int m,n;
	n=fread();
	m=fread();
		for(int i =1;i<=n;i++)
	{
		fa[i] =i;
		size[i] = 1;
	}
	for(int i=1;i<=m;i++)
	{
		nd[i].from = fread();
		nd[i].to = fread();
		nd[i].sum = fread();
	}
	sort(nd+1,nd+m+1,cmp);
	
	for(int i =1;i<=m;i++)
	{
		int x1 = myfin(nd[i].from);//查找 
		int x2 = myfin(nd[i].to);	
		if(x1 == x2)
		{
			cout<<nd[i].sum;//最大矛盾值出现了 ，赶紧输出~ 
			return 0;
		}
		else
		{
		
			if(!enemy[nd[i].from])
				enemy[nd[i].from] = nd[i].to;
			else
			{
	
				int x3 = myfin(enemy[nd[i].from]);
				if(size[x3]>size[x2])
				{
					fa[x2] = x3,size[x3]+=size[x2];
				}
				else
				{
					fa[x3] = x2,size[x2]+=size[x3];
				}
			}
			
			if(!enemy[nd[i].to])
				enemy[nd[i].to] = nd[i].from;
			else
			{
				int x3 = myfin(enemy[nd[i].to]);
				if(size[x3]>size[x1])
				{
					fa[x1] = x3,size[x3]+=size[x1];
				}
				else
				{
					fa[x3] = x1,size[x1]+=size[x3];
				}
			}
		}
	}

	cout<<0;//如果没有矛盾的话就输出0 
	return 0;
 } 
