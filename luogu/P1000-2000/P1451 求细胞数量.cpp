#include<iostream>
using namespace std;
int q[101][101];
int n, m,max_=0;
void pan(int i, int j)
{
	if (i < n && j < m)
	{
		q[i][j] = 0;
		if (q[i - 1][j] == 1)
		{
			pan(i - 1, j);
		}
			
		if (q[i + 1][j] == 1)
		{
			pan(i + 1, j);
		}
			
		if (q[i][j - 1] == 1)
		{
			pan(i, j - 1);
		}
			
		if (q[i][j + 1] == 1)
		{
			pan(i, j + 1);
		}
			
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		string c;
		cin >> c;
		for (int j = 0; j < m; j++) 
		{
			int x=c[j]-48;
			if (x != 0)
			{
				q[i][j] = 1;
			}
			else
			{
				q[i][j] = 0;
			}	
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (q[i][j] == 1)
			{
				max_++;
				pan(i, j);
			}
		}
	}
	cout << max_;
	return 0;
}
