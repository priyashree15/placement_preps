#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int tar,n;
	cin>>n;
	int s[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>s[i];
	}
	cin>>tar;

	int dp[tar+1][n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[0][i]=1;
	}
	for (int i = 1; i < tar+1; ++i)
	{
		dp[i][0]=0;
	}
	for (int i = 1; i < tar+1; ++i)
	{
		for (int j=1;j<=n;j++)
		{
			
			int x=(i>=s[j-1])?dp[i-s[j-1]][j]:0;
			dp[i][j]=dp[i][j-1]+x;
		}
	}
	cout<<endl;
	for (int i = 0; i < tar+1; ++i)
	{
		for (int j=0;j<=n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[tar][n]<<endl;
	return 0;
}
