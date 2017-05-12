#include<bits/stdc++.h>
using namespace std;
int fun(std::vector<int> &v,int n){
	int res=0;
	std::vector<bool> sw(n,false);
	for (int i = 1; i < n; ++i)
	{
		if(!sw[i-1] && v[i-1]==v[i]){
			res++;
			sw[i]=true;
		}
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int n;cin>>n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	cout<<fun(v,n)<<endl;
	return 0;
}