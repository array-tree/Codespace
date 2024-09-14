#include<bits/stdc++.h>
using namespace std;
mt19937 rnd;
struct node
{
	int l,r;
	int val;
	int key;
	int size;
};
node tr[100000];
int n,root,idx;
int newnode(int v)
{
	tr[++idx].key=rnd();
	tr[idx].size=1;
	tr[idx].val=v;
	return idx;
}
void pushup(int p)
{
	tr[p].size=tr[tr[p].l].size+tr[tr[p].r].size+1;
}
void split(int p,int v,int &x,int &y)
{
	if(!p)
	{
		x=0;
		y=0;
		return;
	}
	if(tr[p].val<=v)
	{
		x=p;
		split(tr[x].r,v,tr[x].r,y);
	}
	else
	{
		y=p;
		split(tr[y].l,v,x,tr[y].l);
	}
	pushup(p);	
}
int merge(int x,int y)
{
	if(!x||!y)
	{
		return x+y;
	}
	if(tr[x].key<tr[y].key)
	{
		tr[x].r=merge(tr[x].r,y);
		pushup(x);
		return x;
	}
	else
	{
		tr[y].l=merge(x,tr[y].l);
		pushup(y);
		return y;
	}
}
void insert(int v)
{
	int x,y,z;
	split(root,v,x,y);
	z=newnode(v);
	root=merge(merge(x,z),y);
	
} 
void del(int v)
{
	int x,y,z;
	split(root,v,x,z);
	split(x,v-1,x,y);
	y=merge(tr[y].l,tr[y].r);
	root=merge(merge(x,y),z);
}
int get_k(int p,int k)
{
	if(k<=tr[tr[p].l].size)
	{
		return get_k(tr[p].l,k);
	}
	if(k==tr[tr[p].l].size+1)
	{
		return p;
	}
	return get_k(tr[p].r,k-tr[tr[p].l].size-1);
}
int get_pre(int v)
{
	int x,y;
	split(root,v-1,x,y);
	int p=get_k(x,tr[x].size);
	root=merge(x,y);
	return p;
}
int get_suc(int v)
{
	int x,y;
	split(root,v,x,y);
	int p=get_k(y,1);
	root=merge(x,y);
	return p;
}
int get_rank(int v)
{
	int x,y;
	split(root,v-1,x,y);
	int kk=tr[x].size+1;
	root=merge(x,y);
	return kk;
}
int get_val(int k)
{
	int p=get_k(root,k);
	return tr[p].val;
}
int main()
{
	ios::sync_with_stdio(0);
	srand(time(NULL));
	rnd.seed(rand());
	cin>>n;
	int op,v;
	for(int ww=1;ww<=n;ww++)
	{
		cin>>op>>v;
		if(op==1)
		{
			insert(v);
		}
		else if(op==2)
		{
			del(v);
		}
		else if(op==3)
		{
			cout<<get_rank(v)<<endl;
		}
		else if(op==4)
		{
			cout<<get_val(v)<<endl;
		}
		else if(op==5)
		{
			cout<<tr[get_pre(v)].val<<endl;
		}
		else
		{
			cout<<tr[get_suc(v)].val<<endl;
		}
	}




	return 0;
}
