#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	// string s1,s2;
	// cin>>s1>>s2;
	// int n=s1.size();
	// int m=s2.size();
	// int dp[n+1][m+1];
	int n,m;
	cin>>n>>m;
	int cost[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j=0;j<m;j++)
		{
			cin>>cost[i][j];
		}
	}
	int dp[n][m];
	for (int i = n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--){
			if(i==n-1 && j==m-1)dp[i][j]=cost[i][j];
			else if(i==n-1)dp[i][j]=cost[i][j]+dp[i][j+1];
			else if(j==m-1)dp[i][j]=cost[i][j]+dp[i+1][j];
			else dp[i][j]=cost[i][j]+min(min(dp[i+1][j+1],dp[i+1][j]),dp[i][j+1]);
		}
	}
	cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j=0;j<m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"result:"<<dp[0][0]<<endl;
	return 0;
}
