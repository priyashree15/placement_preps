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
	int gym(long long int a,long long int b,long long int n,long long int k)
	{
		long long int r=0;
		for (long long int i = 1; i <= n; ++i)
		{
			for (long long int j= 1; j <= n; ++j)
			{
				if(i==j)continue;
				long long int x=pow(i,a)+pow(j,b);

				// x=x%k;
				// cout<<x<<" "<<k<<"\n";
				if(x%k==0)r++;
			}
		}
		// int y=pow(10,9)+7;
		return (r%(1000000007));
		// return 0;
	}
};	
int main(int argc, char const *argv[])
{
	int t,j=0;
	long long int a;
	long long int b;
	long long int n;
	long long int k;
	Solution so;
	// cin>>t;
	std::vector<long int> v;
	int line;

	ifstream rfile ("B-small-attempt0.in",std::ios_base::in);
	if (rfile.is_open())
	{
		while ( 1 )
		{

			if(j==0)rfile>>t;
			else
			{
				rfile>>a;
				rfile>>b;
				rfile>>n;
				rfile>>k;
				v.push_back(so.gym(a,b,n,k));
				// cout<<l<<" "<<r<<" "<<t<<"\n";
				t--;
				if(t==0)break;
			}
			j++;
		}
		rfile.close();
	}
	// cout<<v.size();
	// cout<<v[0];
	// else cout << "Unable to open file"; 

	// for (int i = 0; i < t; ++i)
	// {
	// 	cin>>l;
	// 	cin>>r;
	// 	v.push_back(so.palin(l,r));
	// }
	// for (int i = 0; i < ; ++i)
	// {
	// 	cout<<"Case #"<<i+1<<": "<<v[i]<<endl;
	// }
	ofstream myfile;
	myfile.open ("test1.txt");
	for (int i = 0; i < v.size(); ++i)
	{
		// cout<<v[i];
		myfile <<"Case #"<<i+1<<": "<<v[i]<<endl;
	}
	myfile.close();
	
	return 0;
}