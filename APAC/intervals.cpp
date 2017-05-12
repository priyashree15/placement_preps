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
	int intervals(std::vector<long long int> &l,std::vector<long long int> &r,int n)
	{
		// for (int i = 0; i < n; ++i)
		// {
		// 	cout<<l[i]<<" "<<r[i]<<"\t";
		// }
		// cout<<"\n";
		long long int lmin=INT_MAX,rmax=INT_MIN,minLocal,minglobal=INT_MAX;
		if(n==1)return 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				// cout<<l[j]<<" "<<r[j]<<"\t";
				if(j==i)continue;
				lmin=min(lmin,l[j]);
				rmax=max(rmax,r[j]);
			}
			// cout<<lmin<<" "<<rmax<<"\n";
			minLocal=rmax-lmin;
			// cout<<"local:"<<minLocal<<"\n";
			minglobal=min(minLocal,minglobal);
			lmin=INT_MAX;rmax=INT_MIN;
		}
		return minglobal;	
	}
};	

long long int LR(long long int a,long long int b,long long int c, long long int x, long long int y,long long int m)
{
	// cout<<a<<" "<<b<<" "<<c<<" "<<x<<" "<<y<<" "<<m<<"\n";
	long long int z=a*x+b*y+c;
	return z%m;
}
int main(int argc, char const *argv[])
{
	int t,j=0;
	long long int n,l1,r1,a,b,c1,c2,m;
	
	Solution so;
	// cin>>t;
	std::vector<long long int> v;
	std::vector<long long int> l;
	std::vector<long long int> r;
	
	ifstream rfile ("C-small-attempt1.in",std::ios_base::in);
	if (rfile.is_open())
	{
		while ( 1 )
		{

			if(j==0)rfile>>t;
			else
			{
				rfile>>n;
				rfile>>l1;
				rfile>>r1;
				rfile>>a;
				rfile>>b;
				rfile>>c1;
				rfile>>c2;
				rfile>>m;
				l.push_back(l1);
				r.push_back(r1);
				// cout<<n<<"\n";
				for (int i = 2; i <=n; ++i)
				{
					int x=LR(a,b,c1,l[i-2],r[i-2],m);
					int y=LR(a,b,c2,r[i-2],l[i-2],m);
					int templ=min(x,y);
					int tempr=max(x,y);
					l.push_back(templ);
					r.push_back(tempr);
				}
				v.push_back(so.intervals(l,r,n));
				// cout<<l<<" "<<r<<" "<<t<<"\n";
				t--;
				if(t==0)break;
			}
			j++;
		}
		rfile.close();
	}
	
	ofstream myfile;
	myfile.open ("op3_2.txt");
	for (int i = 0; i < v.size(); ++i)
	{
		// cout<<v[i];
		myfile <<"Case #"<<i+1<<": "<<v[i]<<endl;
	}
	myfile.close();
	
	return 0;
}