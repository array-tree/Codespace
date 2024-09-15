#include<bits/stdc++.h>
#include<time.h>
using namespace std;
short ans;
short a[100];
bool ch[100];
bool ji[100][100];
int n;
 mt19937 g;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int as,b;
    for(int qwe=1;qwe<=n;qwe++)
    {
        a[qwe]=qwe;
    }
    while(cin>>as>>b)
    {
        ji[as][b]=1;
        ji[b][as]=1;
    }
    clock_t aa=clock();
    short aans=1;
    int ccnt=0;
            bool flag=1;
    while(clock()-aa<0.0035*CLOCKS_PER_SEC)
    {
        ccnt++;
        aans=0;
        memset(ch,0,sizeof(ch));
        shuffle(a+1,a+1+n,g);
        flag=1;
        for(short qwe=1;qwe<=n;qwe++)
        {
            flag=1;
            for(short qqq=1;qqq<qwe;qqq++)
            {
                if(ch[a[qqq]]&&!ji[a[qwe]][a[qqq]])
                {
                    flag=0;
                    break;
                }
            } 
            if(flag)
            {
                ch[a[qwe]]=1;
                aans++;
            }
        }
        ans=max(aans,ans);
    }
    cout<<ans;
    return 0;
}