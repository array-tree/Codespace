#include<bits/stdc++.h>
using namespace std;
int n,m,as,bs;
long long fastm(int a,int b)
{
    long long back_=1,t=a;
    while(b)
    {
        if(b&1)
        {
            back_=back_*t%n;
        }
        t=t*t%n;
        b/=2;    
      //  cout<<b<<" ";
    //   cout<<back_<<endl; 
    }
    return back_;
}
int main()
{   
    cin>>n>>m>>as>>bs;
    int ans=(bs%n+m%n*fastm(10,as)%n)%n;
    cout<<ans;


    return 0;
}