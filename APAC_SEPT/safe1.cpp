#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <map>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Solution
{
public:
	// / Returns count of all squares in a rectangle
	// // of size m x n
	// int countSquares(int m, int n)
	// {
	//    // If n is smaller, swap m and n
	//    if (n < m)
	//       swap(m, n);

	//    // Now n is greater dimension, apply formula
	//    return  m*(m+1)*(2*m+1)/6 + (n-m)*m*(m+1)/2;
	// }

	int sqS(int size,int r,int c,int k,std::vector<int> &rk,std::vector<int> &ck)
	{
		int x=min(r,c);
		bool row=true,col=false;
		int count=0;
		bool flag;
		// cout<<"\nhere"<<r<<" "<<c<<endl;
		if(row){
			for (int i = 0; i <= r-size; ++i)
			{
				for (int j = 0; j <= c-size; ++j)
				{
					// cout<<i<<" "<<j<<"\t";
					flag=true;
					for (int k = i; k < i+size; ++k)
					{
						for (int l = j; l <j+size; ++l)
						{
							for(int t=0;t<rk.size();t++){

								if(rk[t]==k && ck[t]==l){flag=false;break;}
							}
							if(!flag)break;
						}
						if(!flag)break;
					}
					if(flag)count++;
				}
			}
		}
		// cout<<"\n"<<size<<" "<<count<<endl;
		return count;
	}
	int fun(int r,int c,int k,std::vector<int> &rk,std::vector<int> &ck)
	{
		int res=r*c-k;
		int x=min(r,c);
		for(int i=2;i<=x;i++){
			res+=sqS(i,r,c,k,rk,ck);
		}
		return res;
	}
};	
int main(int argc, char const *argv[])
{
	
	Solution so;
	int line;
	int j=0;
	std::vector<int> v;
	ifstream rfile ("B-large.in",std::ios_base::in);
	if (rfile.is_open())
	{
		while ( 1 )
		{
				int t,r,c,k;
				std::vector<int> rk(k);
				std::vector<int> ck(k);
			if(j==0)rfile>>t;
			else
			{
				rfile>>r;
				rfile>>c;
				// rfile>>n;
				rfile>>k;
				for (int i = 0; i < k; ++i)
		{
			rfile>>rk[i]>>ck[i];
		}
				v.push_back(so.fun(r,c,k,rk,ck));
				// cout<<l<<" "<<r<<" "<<t<<"\n";
				t--;
				if(t==0)break;
			}
			j++;
		}
		rfile.close();
	}
	// int t;
	// cin>>t;
	// std::vector<int> v;
	// while(t--){
	// 	int r,c,k;
	// 	cin>>r>>c>>k;
	// 	std::vector<int> rk(k);
	// 	std::vector<int> ck(k);
	// 	for (int i = 0; i < k; ++i)
	// 	{
	// 		cin>>rk[i]>>ck[i];
	// 	}
	// 	v.push_back(so.fun(r,c,k,rk,ck));
	// }
	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	cout<<"Case #"<<i+1<<": "<<v[i]<<endl;
	// }
	ofstream myfile;
	myfile.open ("output2.txt");
	for (int i = 0; i < v.size(); ++i)
	{
		// cout<<v[i];
		myfile <<"Case #"<<i+1<<": "<<v[i]<<endl;
	}
	myfile.close();
}