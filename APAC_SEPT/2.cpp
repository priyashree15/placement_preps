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
	float maximum(float a,float b,float c,float d){
		float x=max(a,b);
		float y=max(c,d);
		return max(x,y);
	}
	float fun1(int r,int c,int rs,int cs,int s,float p,float q,std::vector<vector<char> > &a){
		if(s==0 || rs<0 || cs<0 || rs>=r ||cs>=c)return 0.0;
		float res=a[rs][cs]=='A'?p:q;
		s--;
		// bool x,y,v,z;
		// x=y=v=z=false;
		// if(rs-1>=0)x=true;
		// if(cs-1>=0)y=true;
		// if(rs+1<r)v=true;
		// if(cs+1<c)z=true;
		// if(x && y && v && z)
		// cout<<res<<" "<<a[rs][cs]<<" "<<rs<<" "<<cs<<endl;
			return res+maximum(fun1(r,c,rs-1,cs,s,p,q,a),fun1(r,c,rs,cs-1,s,p,q,a),fun1(r,c,rs+1,cs,s,p,q,a),fun1(r,c,rs,cs+1,s,p,q,a));
	}
	float fun(int r,int c,int rs,int cs,int s,float p,float q,std::vector<vector<char> > &a)
	{
		// int res=0;
		// bool x,y,v,z;
		// x=y=v=z=false;
		// if(rs-1>=0)x=true;
		// if(cs-1>=0)y=true;
		// if(rs+1<r)v=true;
		// if(cs+1<c)z=true;

		// if(x && y && v && z)
			return maximum(fun1(r,c,rs-1,cs,s,p,q,a),fun1(r,c,rs,cs-1,s,p,q,a),fun1(r,c,rs+1,cs,s,p,q,a),fun1(r,c,rs,cs+1,s,p,q,a));
		// else if(x && y && v)
		// 	return maximum(fun1(r,c,rs-1,cs,s,p,q,a),fun1(r,c,rs,cs-1,s,p,q,a),fun1(r,c,rs+1,cs,s,p,q,a),0.0);
		// else if(x && y)
		// 	return max(fun1(r,c,rs-1,cs,s,p,q,a),fun1(r,c,rs,cs-1,s,p,q,a));
		// else if(x && v)
		// 	return maximum(fun1(r,c,rs-1,cs,s,p,q,a),fun1(r,c,rs+1,cs,s,p,q,a));
		// else if()
	}
};	
int main(int argc, char const *argv[])
{
	
	Solution so;
	int t;
	cin>>t;
	std::vector<float> v;
	while(t--){
		int t,r,c,rs,cs,s;
		float p,q;
		cin>>r>>c>>rs>>cs>>s>>p>>q;
		std::vector<vector<char> > a(r,std::vector<char>(c,'.'));
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cin>>a[i][j];
			}
		}
		v.push_back(so.fun(r,c,rs,cs,s,p,q,a));
	}
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<"Case #"<<i+1<<": "<<v[i]<<endl;
	}
}