#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;
class Solution
{
public:
	int lps(string s)
	{
		int n=s.size();
		std::vector<std::vector<bool> > P(n,std::vector<bool> (n,false));
		int maxlen=1;
		for (int i = 0; i < n; ++i)
        	P[i][i] = true;

		for(int i=0;i<n-1;i++){
			if(s[i]==s[i+1])
			{
				P[i][i+1]=true;
				maxlen=2;
			}
		}
		for (int l = 3; l <= n; ++l)
		{
			for (int i = 0; i+l-1 < n; ++i)
			{
				int j=i+l-1;
				if(s[i]==s[j] && P[i+1][j-1]){
					P[i][j]=true;
					maxlen=max(l,maxlen);
				}
			}
		}
		return maxlen;
	}
};	
int main(int argc, char const *argv[])
{
	int n;
	Solution  so;
	string s;
	cin>>s;
	cout<<so.lps(s)<<endl;
	return 0;
}