#include<bits/stdc++.h>
using namespace std;

int a[5000005],temp[5000005];
long long n,cnt=0;
void mymerge(int left,int right)
{
	if(left==right)return;
	int mid=(left+right)/2;
	mymerge(left,mid);//分左边 
	mymerge(mid+1,right);//分右边
	
	//合并
	int i=left,j=mid+1,k=left;
	while(i<=mid && j<=right)
	{
		if(a[i]<=a[j])
		{
			temp[k++]=a[i++];//左边小放在左边的数 
		}
		else
		{
			temp[k++]=a[j++];//右边小放在右边的数 
			//判断逆序对 
			cnt+=mid-i+1;
		}
	 } 
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=right)
	{
		temp[k++]=a[j++];
	}
	
	//将temp数组回填到原数组
	for(int i=left;i<=right;i++)
	{
		a[i]=temp[i];
	}
}
int main()
{
    ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	mymerge(1,n);
	cout<<cnt;
	return 0;




	return 0;
}

