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
	bool isSum(std::vector<int> &v,int n,int sum)
	{
		if(sum==0)return true;
		if(n==0 && sum!=0)return false;
		if(v[n-1]>sum)return isSum(v,n-1,sum);
		return isSum(v,n-1,sum)||isSum(v,n-1,sum-v[n-1]);
	}
	bool partition(std::vector<int> &v,int n)
	{
		// return false;
		int sum=0;
		for (int i = 0; i < n; ++i)
		{
			sum+=v[i];
		}
		// cout<<sum;
		if(sum%2)return false;
		// return isSum(v,n,sum/2);
		sum=sum/2;
		bool a[sum/2+1][n+1];
		for (int i = 0; i <= n; ++i)
			a[0][i]=true;
		for (int i = 1; i <=sum/2; ++i)
			a[i][0]=false;
		for (int i = 1; i <=sum/2; ++i)
		{
			for (int j = 1; j <=n; ++j)
			{
				a[i][j]=a[i][j-1];
				if(i>=v[j-1])a[i][j]=a[i][j]||a[i-v[j-1]][j-1];
			}
		}
		return a[sum/2][n];
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
	cout<<so.partition(v,n)<<endl;
	return 0;
}