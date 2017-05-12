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
	int print(std::vector<int> &p,int n)
	{
		int k;
		if(p[n]==1)k=1;
		else k=print(p,p[n]-1)+1;
		cout<<"line "<<k<<": "<<p[n]<<" to "<<n<<endl;
		return k;
	}
	void wordWrap(std::vector<int> &s,int M){
		int n=s.size();
		std::vector<std::vector<int> > extras(n+1,std::vector<int>(n+1,0));
		std::vector<std::vector<int> > lc(n+1,std::vector<int>(n+1,0));
		std::vector<int> c(n),p(n);
		for (int i = 1; i < n+1; ++i)
		{
			extras[i][i]=M-s[i-1];
			for (int j = i+1; j <=n; ++j)
			{
				extras[i][j]=extras[i][j-1]-s[j-1]-1;
			}
		}
		for (int i = 1; i < n+1; ++i)
		{
			for (int j = 1; j < n+1; ++j)
			{
				if(extras[i][j]<0)lc[i][j]=INF;
				else if(j==n && extras[i][j]>=0)lc[i][j]=0;
				else lc[i][j]=extras[i][j]*extras[i][j];
			}
		}
		c[0]=p[0]=0;
		for (int j = 1; j < n+1; ++j)
		{
			c[j]=INF;
			for (int i = 1; i <=j; ++i)
			{
				if(c[i-1]!=INF && lc[i][j]!=INF && c[i-1]+lc[i][j]<c[j])
				{
					c[j]=c[i-1]+lc[i][j];
					p[j]=i;
				}
			}
		}
		print(p,n);
	}

};	
int main(int argc, char const *argv[])
{
	// int n;
	Solution  so;
	int n;
	cin>>n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	int M;
	cin>>M;
	so.wordWrap(v,M);
	return 0;
}