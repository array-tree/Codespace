//SSYJS 5-14 ��ϰ 
#include<bits/stdc++.h>
using namespace std;
int fread()
{
	char ch;
	int x=0, flag = 1;//flag����������� 
	ch= getchar();//��ȡһ���ַ���ע��ո񡢻��з�Ҳ���ַ� 
	while(ch<'0' || ch>'9')//���ű�����ȥ������ǰ�����������ַ�
	{
		if(ch == '-')flag = -1;
		ch = getchar();
	}
	
	while(ch>='0' && ch<='9')//���ַ���ȡ���� 
	{
		x= x*10+(ch-'0');//���ַ���0������õ���Ӧ���� 
		ch = getchar(); 
	}
	return x*flag;//�ǵø������ű����� 
}
int fa[20010];//��¼�ѺõĹ�ϵ 
int size[20010];//����ʽ�ϲ������� 
int enemy[20010];//��¼�жԹ�ϵ�ļ������ 
struct node
{
	int from; 
	int to;
	int sum;//���ֵ 
}nd[100010];
int myfin(int x)
{
	if(fa[x] == x)return x;
	fa[x] = myfin(fa[x]);//·��ѹ���� 
	return fa[x];
}
bool cmp(node a,node b)//��sort�õ�cmp 
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
		int x1 = myfin(nd[i].from);//���� 
		int x2 = myfin(nd[i].to);	
		if(x1 == x2)
		{
			cout<<nd[i].sum;//���ì��ֵ������ ���Ͻ����~ 
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

	cout<<0;//���û��ì�ܵĻ������0 
	return 0;
 } 
