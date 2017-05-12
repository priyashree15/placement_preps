#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <map>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
bool subSetSum(int n,int sum,std::vector<int> &s)
{
	bool dp[sum+1][n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[0][i]=true;
	}
	for (int i = 1; i < sum+1; ++i)
	{
		dp[i][0]=false;
	}
	for (int i = 1; i < sum+1; ++i)
	{
		for (int j = 1; j < n+1; ++j)
		{
			dp[i][j]=dp[i][j-1];
			if(i-s[j-1]>=0){
				dp[i][j]=dp[i][j]||dp[i-s[j-1]][j-1];
			}
		}
	}
	for (int i = 0; i < sum+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[sum][n];
}
int main(int argc, char const *argv[])
{
	int n,sum;
	cin>>n>>sum;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	cout<<subSetSum(n,sum,v)<<endl;
    return 0;
}