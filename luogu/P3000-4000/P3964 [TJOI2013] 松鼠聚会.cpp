#include <bits/stdc++.h>
using namespace std;
int n,x[100010],y[100010],gx[100010],gy[100010];
long long addx[100010],addy[100010];
long long add_(int i)
{
   int rx=lower_bound(gx + 1, gx + n + 1, x[i])-gx;
   int ry=lower_bound(gy + 1, gy + n + 1, y[i])-gy;
   return rx*1LL*x[i]-addx[rx]+addx[n]-addx[rx]-(n-rx)*1LL*x[i]+ry*1LL*y[i]-addy[ry]+addy[n]-addy[ry]-(n-ry)*1LL*y[i];
}
long long ans=0x3f3f3f3f3f3f3f3f3f3f;
int  main()
{
    cin>>n; 
	int xi,yi;
    for(int i=1;i<=n;++i)
    {
       
 		scanf("%d%d",&xi,&yi);
 		x[i]=gx[i]=xi+yi;
 		y[i]=gy[i]=xi-yi;

 	}
 	sort(gx+1,gx+n+1);
 	for(int i=1; i<=n;++i)
 	{
 		addx[i]=addx[i-1]+gx[i];
	}
	sort(gy+1,gy+n+1);
 	for(int i=1;i<=n;++i)
 	{
 		addy[i]=addy[i-1]+gy[i];
	}
	for(int i=1;i<=n;++i)
	{
		ans=min(ans,add_(i));
	}
 	printf("%lld\n",ans>>1LL);
 	return 0;
}
