#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.size();
	int m=s2.size();
	int dp[n+1][m+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i][0]=i;
	}
	for (int i = 0; i < m+1; ++i)
	{
		dp[0][i]=i;
	}
	for (int i = 1; i < n+1; ++i)
	{
		for (int j=1;j<m;j++)
		{
			if(s1[i-1]==s2[i-1])dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
		}
	}
	cout<<dp[n][m];
	for (int i = 0; i < n+1; ++i)
	{
		for (int j=0;j<m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"result:"<<dp[n][m]<<endl;
	return 0;
}
