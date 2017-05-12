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
	int eggDrop(int n,int k){
		// if(k==0 || k==1)return k;
		// if(n==1)return k;

		// int res=INT_MAX;
		// for (int x = 1; x < k+1; ++x)
		// {
		// 	res=min(res,max(eggDrop(n-1,x-1),eggDrop(n,k-x))+1);
		// }
		// return res;
		int dp[n+1][k+1];
		for (int i = 0; i <=n; ++i)
		{
			for (int j = 0; j <= k; ++j)
			{
				if(j==0 || j==1 || i==1)dp[i][j]=j;
				else{
					dp[i][j]=INT_MAX;
					for (int x = 1; x <j+1 ; ++x)
					{
						dp[i][j]=min(max(dp[i-1][x-1],dp[i][j-x])+1,dp[i][j]);
					}
				}
			}
			
		}
		return dp[n][k];
	}
};	

int main(int argc, char const *argv[])
{
	/* code */
	Solution so;
	int n,k;
	cin>>n>>k;
	cout<<so.eggDrop(n,k)<<endl;
	return 0;
}