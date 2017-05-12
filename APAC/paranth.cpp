#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Solution
{
public:
	int palin(int l,int r)
	{
		// cout<<"here";
		if(!l && !r)return 1;
		if(l<0 || r<0)return 0;
		int temp=min(l,r);
		int sum=0;
		while(temp)
		{
			sum+=temp;temp--;
		}
		// cout<<sum<<"\n";	
		return sum;

	}
};	
int main(int argc, char const *argv[])
{
	int t,l,r,j=0;
	Solution so;
	// cin>>t;
	std::vector<int> v;
	int line;

	ifstream rfile ("A-large.in",std::ios_base::in);
	if (rfile.is_open())
	{
		while ( 1 )
		{

			if(j==0)rfile>>t;
			else
			{
				rfile>>l;
				rfile>>r;
				v.push_back(so.palin(l,r));
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
	myfile.open ("testOp.txt");
	for (int i = 0; i < v.size(); ++i)
	{
		// cout<<v[i];
		myfile <<"Case #"<<i+1<<": "<<v[i]<<endl;
	}
	myfile.close();
	
	return 0;
}