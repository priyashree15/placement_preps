#include <algorithm>
#include <vector>
#include <stack>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;
class Solution
{
public:
	int lps(string s){
		int n=s.size();
		int dp[n][n];

		for (int i = 0; i < n; ++i)
		{
			dp[i][i]=1;
		}
		for (int cl = 2; cl<=n; ++cl)
		{
			for (int i = 0; i+cl-1 < n; ++i)
			{
				int j=i+cl-1;
				if(s[i]==s[j] && cl==2)dp[i][j]=2;
				else if(s[i]==s[j])dp[i][j]=dp[i+1][j-1]+2;
				else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}
		}
		return dp[0][n-1];
	}
};	

int main(int argc, char const *argv[])
{
	/* code */
	Solution so;
	string s;
	cin>>s;
	cout<<so.lps(s)<<endl;
	return 0;
}