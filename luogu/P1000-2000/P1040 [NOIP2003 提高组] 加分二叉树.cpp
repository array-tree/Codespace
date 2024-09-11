#include<bits/stdc++.h>
using namespace std;
const int maxn=50;
long long  n;
long long ff[100][100],tree_[100][100];
void xianxu(long long l,long long r)
{
    if(l>r)
    {
        return;
    }
    cout<<tree_[l][r]<<" ";
    if(l==r)
    {
        return;
    }
    xianxu(l,tree_[l][r]-1);
    xianxu(tree_[l][r]+1,r);
}
bool my_max(long long &a,long long b,long long c)
{
    a=max(b,c);
    return b>c;
}
int main()
{
    cin>>n;
    for(int qq=1;qq<=n;qq++)   
    {
        cin>>ff[qq][qq];
        tree_[qq][qq]=qq;
    }
    for(int wqe=1;wqe<=n;wqe++)
    {
        for(int qqq=1;qqq+wqe<=n;qqq++)
        {
            tree_[qqq][qqq+wqe]=qqq;
            ff[qqq][qqq+wqe]=ff[qqq+1][qqq+wqe]+ff[qqq][qqq];
            for(int ll=qqq+1;ll<qqq+wqe;ll++)
            {
                if(my_max(ff[qqq][qqq+wqe],ff[qqq][ll-1]*ff[ll+1][qqq+wqe]+ff[ll][ll],ff[qqq][qqq+wqe]))
                {
                    tree_[qqq][qqq+wqe]=ll;
                }
            }
        }
    }
    cout<<ff[1][n]<<endl;
    xianxu(1,n);
    return 0;




    return 0;
}