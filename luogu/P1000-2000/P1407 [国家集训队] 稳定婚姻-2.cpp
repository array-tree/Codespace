#include <bits/stdc++.h>
using namespace std;
struct node
{
    int vis;
    int dfn;
    int low;
    vector<int> to;
    bool instk;
    int scc;
};
int cnt;
int siz[10000]; // scc的大小
node nodes[1000000];
int n, m;
int dfn=0;
int stk[100000], top;
void tarjan(int x)
{
    int to;
    nodes[x].dfn = ++dfn;
    nodes[x].low = dfn;
    stk[++top] = x;
    nodes[x].instk = 1;
    for (int yy = 0; yy < nodes[x].to.size(); yy++)
    {
        to = nodes[x].to[yy];
        if (nodes[to].dfn == 0)
        {
            tarjan(to);
            nodes[x].low = min(nodes[x].low, nodes[to].low);
        }
        else if (nodes[to].instk)
        {
            nodes[x].low = min(nodes[x].low, nodes[to].dfn);
        }
    }
    if (nodes[x].low == nodes[x].dfn)
    {
        int y;
        cnt++;
        do
        {
            y = stk[top];
            top--;
            nodes[y].scc = cnt;
            nodes[y].instk = 0;
            siz[cnt]++;
        } while (y != x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int a, b;
    for (int ww = 1; ww <= m; ww++)
    {
        cin >> a >> b;
        nodes[a].to.push_back(b);
    }
    for (int ww = 1; ww <= n; ww++)
    {
        if (!nodes[ww].dfn)
        {
            tarjan(ww);
        }
    }
    int totans=0;
    for(int yy=1;yy<=cnt;yy++)
    {
        if(siz[yy]>=2)
        {
            totans++;
        }
    }
    cout<<totans;
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// struct node
// {
// 	vector<int> to;//能到达的点
// 	int dfn;
// 	int low;//能访问到的dfn最小的节点
// 	bool instk;
// 	bool vis;
// };
// node nodes[1000000];
// int tot;//dfn
// int stk[100000],scc[100000],siz[100000]/*SCC大小*/,cnt/*SCC编号*/,top/*栈顶*/;

// void tarjan(int x)
// {
// 	nodes[x].dfn=++tot;//记录DFN
// 	nodes[x].low=tot;
// 	stk[++top]=x;
// 	nodes[x].instk=1;
// 	int to_;
// 	for(int y=0; y<nodes[x].to.size(); y++)
// 	{
// 		to_=nodes[x].to[y];
// 		if(nodes[to_].dfn==0)//若没访问过 
// 		{
// 			tarjan(to_);//深搜
// 			nodes[x].low=min(nodes[x].low,nodes[to_].low);//更新
// 		}
// 		else if(nodes[to_].instk)//若y已访问且在栈中 
// 		{
// 			nodes[x].low=min(nodes[x].low,nodes[to_].dfn);//更新
// 		}
// 	}
// 	if(nodes[x].dfn==nodes[x].low)//若这个节点能链接到自己说明是一个SCC的根 
// 	{
// 		int y;
// 		cnt++;
// 		do//将节点出栈
// 		{
// 			y=stk[top--];
// 			nodes[y].instk=0;
// 			scc[y]=cnt;
// 			++siz[cnt];
// 		}
// 		while(y!=x);

// 	}

// }
// int main()
// {
// 	ios::sync_with_stdio(0);
// 	cin>>n>>m;
// 	int a,b;
// 	for(int ww=1;ww<=m;ww++)
// 	{
// 		cin>>a>>b;
// 		nodes[a].to.push_back(b);
// 	}
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(!nodes[i].dfn)//图可能不联通
// 		{
// 			tarjan(i);
// 		}
// 	}

// 	cout<<cnt;
// 	return 0;

// }