#include<bits/stdc++.h>
using namespace std;

int a[5000005],temp[5000005];
long long n,cnt=0;
void mymerge(int left,int right)
{
	if(left==right)return;
	int mid=(left+right)/2;
	mymerge(left,mid);//����� 
	mymerge(mid+1,right);//���ұ�
	
	//�ϲ�
	int i=left,j=mid+1,k=left;
	while(i<=mid && j<=right)
	{
		if(a[i]<=a[j])
		{
			temp[k++]=a[i++];//���С������ߵ��� 
		}
		else
		{
			temp[k++]=a[j++];//�ұ�С�����ұߵ��� 
			//�ж������ 
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
	
	//��temp������ԭ����
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

