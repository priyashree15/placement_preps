#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits.h>
#define INF INT_MAX
using namespace std;

class Solution
{
public:
	void print(std::vector<std::vector<int> > v,int n){
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<v[i][j]<<"\t";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
	int even(string s){
		int maxlen=0,n=s.size();
		std::vector<std::vector<int> > dp(n,std::vector<int>(n,0));
		for(int i=0;i<n;i++)
			dp[i][i]=s[i]-'0';
		// print(dp,n);
		for (int cl = 2; cl <=n; ++cl)
		{
			for (int i = 0; i+cl-1<n; ++i)
			{
				int j=i+cl-1;
				int k=cl/2;
				dp[i][j]=dp[i][j-k]+dp[j-k+1][j];
				if(cl%2==0 && dp[i][j-k]==dp[j-k+1][j] && maxlen<cl)
					maxlen=cl;
			}
			// print(dp,n);
			// cout<<maxlen<<"\n";
		}
		return maxlen;
	}

};	
int main(int argc, char const *argv[])
{
	// int n;
	Solution  so;
	string s;
	cin>>s;
	cout<<so.even(s)<<endl;
	return 0;
}