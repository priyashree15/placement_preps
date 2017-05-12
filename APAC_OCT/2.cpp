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
	bool safe(std::vector<std::vector<bool> > &v,int i,int j,int r,int c){
		if( i>=0 && j>=00 &&i<r && j<c && !v[i][j]){

			if((i-1)>=0 &&(i+1)<r&&v[i-1][j]&&v[i+1][j])return false;
			if((j-1)>=0 &&(j+1)<c&&v[i][j-1]&&v[i][j+1])return false;
			return true;
		}
		return false;
	}
	int dfs(int i,int j,int r,int c){
	// 	cout<<i<<" "<<j<<endl;
		std::vector<std::vector<bool> > v(r,std::vector<bool>(c,false));
		v[i][j]=true;
		int res=1;
	// 	int row[]={0,0,-1,1},col[]={-1,1,0,0};
	// 	// for (int t = 0; t < 4; ++t)
	// 	// {
			if(i-1>=0 && !v[i-1][j] && safe(v,i+1,j,r,c))res+=dfs(i+1,j,r,c);
			else if(i-1<0 && safe(v,i+1,j,r,c))res+=dfs(i+1,j,r,c);
			if(i+1<r && !v[i+1][j] && safe(v,i-1,j,r,c))res+=dfs(i-1,j,r,c);
			else if(i+1>=r && safe(v,i-1,j,r,c))res+=dfs(i-1,j,r,c);
			if(j-1>=0 && !v[i][j-1] && safe(v,i,j+1,r,c))res+=dfs(i,j+1,r,c);
			else if(j-1<0 && safe(v,i,j+1,r,c))res+=dfs(i,j+1,r,c);
			if(j+1<c && !v[i][j+1] && safe(v,i,j-1,r,c))res+=dfs(i,j-1,r,c);
			else if(j+1>=c && safe(v,i,j-1,r,c))res+=dfs(i,j-1,r,c);
	// 	// }
		return res;
	}
	int fun(int r,int c){
		std::vector<std::vector<bool> > v(r,std::vector<bool>(c,true));
		int res=r*c;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				res=max(res,dfs(i,j,r,c));
			}
		}
		// for (int i = 0; i < r; ++i)
		// {
		// 	for (int j = 0; j < c; ++j)
		// 	{
		// 		if(v[i][j]){
					
		// 			if(!safe(v,i,j,r,c)){
		// 				res-=1;
		// 				v[i][j]=false;
		// 			}
		// 		}
		// 	}
		// }
		return res;
	}
};	

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	Solution so;
	std::vector<int> v(t);
	for (int i = 0; i < t; ++i)
	{
		int n,m;
		cin>>n>>m;
		v[i]=so.fun(n,m);
	}
	for (int i = 0; i < t; ++i)
	{	
		// std::cout << std::fixed;
  //   std::cout << std::setprecision(2);
		cout<<"Case #"<<i+1<<": "<<v[i]<<endl;
	}
	return 0;
}