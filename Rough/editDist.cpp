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
	int edit(string s1,string s2,int m,int n){
		// if(m==0)return n;
		// if(n==0)return m;
		// if(s1[m-1]==s2[n-1])return edit(s1,s2,m-1,n-1);

		// return 1+min(min(edit(s1,s2,m,n-1),edit(s1,s2,m-1,n)),edit(s1,s2,m-1,n-1));
		int dp[m+1][n+1];

		for (int i = 0; i <=m; ++i)
		{
			for (int j = 0; j <=n; ++j)
			{
				cout<<i<<j<<endl;
				if(i==0)dp[i][j]=j;
				else if(j==0)dp[i][j]=i;

				else if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1];

				else dp[i][j]=1+min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
			}
		}
		for (int i = 0; i <=m; ++i)
		{
			for (int j = 0; j<=n; ++j)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"here ends "<<m<<" "<<n<<" ******************\n";
		return dp[m][n];
	}
};	

int main(int argc, char const *argv[])
{
	/* code */
	Solution so;
	string s1,s2;
	cin>>s1>>s2;
	cout<<so.edit(s1,s2,s1.size(),s2.size())<<endl;
	return 0;
}