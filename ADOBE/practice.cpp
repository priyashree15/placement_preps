#include<bits/stdc++.h>
using namespace std;
void swap(char *a,char *b ){
	char t=*a;
	*a=*b;
	*b=t;
}
void print(std::vector<char> &v){
	for (int i = 0; i < v.size(); ++i)
		{
			cout<<v[i];
		}
		cout<<endl;
}
void fun(std::vector<char> &v,int l,int r,set<std::vector<char> >&s){
	
	if(l==r){
		print(v);
		s.insert(v);
	}
	else{
		for (int i = l; i <=r; ++i)
		{
			swap(v[l],v[i]);
			fun(v,l+1,r,s);
			swap(v[l],v[i]);
		}
	}
	
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	std::vector<char> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	set<std::vector<char> >s;
	fun(v,0,n-1,s);
	cout<<"from main ranked list:\n";
	for(set<vector<char> >::iterator it=s.begin();it!=s.end();++it){
		std::vector<char> vn=*it;
		print(vn);
	}
	return 0;
}