#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
	scanf("%lld%lld",&n,&m);
	long long ans=n*m-n-m;
	printf("%lld",ans);
	return 0;
}
/*
打表：
n m
2 3 -> 1 \
2 5 -> 3 - n=2时，m+2,ans+2 \  
2 7 -> 5 /                   \
n m                           \
3 5 ->7   \                    \
3 7 ->11  - n=3时,m+2，ans+4   - ans=n(m-1)-m ->ans=n*m-n-m 
3 11 ->19 /                    /
n,m                           / 
5 7 ->23  \                  /
5 9 ->31  -n=4时，m+2,ans+8 /
5 11 ->39 /
*/ 
