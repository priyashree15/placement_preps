#include <algorithm>
#include <vector>
#include <stack>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
	float fun(int n,int m,int t){
		if(n==0 || m==0)return float(1);
		return (2/t)*fun(n-2,m-1,t)+fun(n-2,m,t);
	}
};	

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	Solution so;
	std::vector<float> v(t);
	for (int i = 0; i < t; ++i)
	{
		int n,m;
		cin>>n>>m;
		v[i]=so.fun((n+1),m,(n+1)*m);
	}
	for (int i = 0; i < t; ++i)
	{	
		// std::cout << std::fixed;
  //   std::cout << std::setprecision(2);
		cout<<"Case #"<<i+1<<": "<<v[i]<<endl;
	}
	return 0;
}