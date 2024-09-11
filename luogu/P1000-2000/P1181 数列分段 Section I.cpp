#include<bits/stdc++.h>
using namespace std;
const int  N=100010;
int nS,m,a[N];
int sum,f;
int main()
{
    cin>>nS>>m;
    for(int i=1;i<=nS;i++)
    {
    	 cin>>a[i];
	}
    for(int j=1;j<=nS;j++)
    {
        sum+=a[j];
        if(sum>m)
        {
            j--;
			f++;
			sum=0;
        }
    } 
    cout<<f+1;
    return 0;
}
