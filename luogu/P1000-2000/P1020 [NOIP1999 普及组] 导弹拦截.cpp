#include<iostream>
using namespace std;
int dp[100010],dps,op;
int shuru[100010],shurus;
int dayi,da2;
int main()
{
    int w=0;
    while(cin>>shuru[++w])
    {


    }
    w--;
    int len1 = 1, len2=1;
    for(int q=0;q<w;q++)
    {
        if(dp[dps-1]<=shuru[q])
        {
            dp[dps]=shuru[q];
            dps++;

        }
        else{
            int p = lower_bound(dp,dp+w,shuru[q])-dp;
            dp[p]=shuru[q];
            op++;
        }
    }
    cout<<op<<endl<<dps;
    return 0;
}
//lower_bound
//upper_bound
//int p = lower_bound(a,a+n)-a;
