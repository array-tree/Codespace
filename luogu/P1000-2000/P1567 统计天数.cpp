#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int shu;

int main()
{
//	freopen("P1567_2.in","r",stdin);
    ios::sync_with_stdio(false);
    cin>>shu;
    int max_=-9999999,sheng=0;
	for(int p=1;p<=shu;p++)
	{
		int w;
		cin>>w;
		if(w>max_)
		{
			max_=w;
			sheng++;
	//		cout<<w<<"l"<<endl;
		}
		else
		{
			q.push(sheng);
	//		cout<<sheng<<"k"<<endl;
//			cout<<w<<"l"<<endl;
			sheng=1;
			max_=w;
			
		}
		if(p==shu)
		{
			q.push(sheng);
		}
	}
	cout<<q.top();




	return 0;
}

