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
	int palinPart(string s)
	{
		int n=s.size();
		std::vector<std::vector<int> > cost(n,std::vector<int> (n,0));
		std::vector<std::vector<bool> > P(n,std::vector<bool> (n,true));
		for (int l = 2; l <= n; ++l)
		{
			for (int i = 0; i+l-1 < n; ++i)
			{
				int j=i+l-1;
				if(l==2)P[i][j]=s[i]==s[j];
				else P[i][j]= (s[i]==s[j])&&P[i+1][j-1];
				if(P[i][j]==true)cost[i][j]=0;
				else 
				{
					cost[i][j]=INT_MAX;
					for (int k=i; k < j; ++k)
					{
						cost[i][j]=min(cost[i][j],cost[i][k]+cost[k+1][j]+1);;
					}
				}
			}
		}
		return cost[0][n-1];
	}
};	
int main(int argc, char const *argv[])
{
	int n;
	Solution  so;
	string s;
	cin>>s;
	cout<<so.palinPart(s)<<endl;
	return 0;
}