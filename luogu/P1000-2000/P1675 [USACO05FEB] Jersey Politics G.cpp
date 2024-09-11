#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    int id;
}a[1000];
bool cmp(node a,node b)
{
    return a.val<b.val;
}
int k;
int main()
{	
    cin>>k;
    int tot=3*k;
    for(int i=1;i<=tot;i++)
    {
        cin>>a[i].val;
        a[i].id=i;
    }
    sort(a+1,a+1+tot,cmp);
    int ans=0;
    int cnt=0;
    while(1)
    {
        ans=0;
        cnt=0;
	    for(int qwe=2*k+1;qwe<=3*k;qwe++)
		{
			ans+=a[qwe].val;
			if(ans>500*k)
			{
				cnt++;
				break;
			}
		}
		ans=0;
		for(int qwe=k+1;qwe<=2*k;qwe++)
		{
			ans+=a[qwe].val;
			if(ans>500*k)
			{
				cnt++;
				break;
			}
		}
		if(cnt==2)
		{
			break;
		}         
		random_shuffle(a+2+k,a+1+tot);
    }
    for(int qwe=1;qwe<=3*k;qwe++)
    {
    	cout<<a[qwe].id<<endl;
	}
	return 0;
}
