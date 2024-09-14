#include<bits/stdc++.h>
using namespace std;
int shu[10000000],cnt;
bitset<100000001> book;
int n,q,v;
void init(int qw)
{
    for(int www=2;www<=qw;www++)
    {
        if(!book[www])
        {
            shu[++cnt]=www;
            for(int qqq=www*2;qqq<=qw;qqq+=www)
            {
                if(!book[qqq])
                {
                     book[qqq]=1;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    init(n);
    for(int qqq=1;qqq<=q;qqq++)
    {
        cin>>v;
        cout<<shu[v]<<endl;
    }

    return 0;
}