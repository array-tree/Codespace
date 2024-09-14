#include<bits/stdc++.h>
using namespace std;
int cnt,hoo,n;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    int a;
    for(int ee=1;ee<=n;ee++)
    {
        cin>>a;
        if(cnt==0)
        {
            hoo=a;
            cnt++;
        }
        else
        {
            if(a==hoo)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
    }
    cout<<hoo;



    return 0;
}


