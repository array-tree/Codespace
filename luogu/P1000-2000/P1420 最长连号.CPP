#include<bits/stdc++.h>
using namespace std;
int n;
int j[1000000];
int bh,ji,ans;
int main()
{
    cin>>n;
    for(int s=1;s<=n;s++)
    {
        scanf("%d",&j[s]);
    }
    for(int s=1;s<=n;s++)
    {
        if(j[s]!=bh+1)
        {
            ans=max(ans,ji);
            ji=0;
            bh=j[s];
            ji++;
        }
        else
        {
            ji++;
            bh++;
        }
        cout<<ji<<endl;
    }
    ans=max(ans,ji);
    cout<<ans;
    return 0;
}