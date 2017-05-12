#include<bits/stdc++.h>
using namespace std;
void funUtil(map<int,vector<int> >&m,int j,std::vector<int> &visit)
{
	int z=m[j].size();
	for (int i = 0; i < z; ++i)
	{
		int x=m[j][i];
		visit[x]=true;
		if(!visit(i) && m[i].count()){
			funUtil(m,i,visit);
		}
	}
}
int fun(map<int,vector<int> >&m,int n){
	std::vector<bool> visit(n+1,false);
	int count=0;
	for (int i = 1; i <=n; ++i)
	{
		if(!visit(i) && m[i].count()){
			funUtil(m,i,visit);
			count++;
		}
		
	}
	return count;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	map<int,std::vector<int> >m;
	for(int i=1;i<=n;i++){
		int points_to;
		cin>>points_to;
		map[points_to].push_back(i);
	}
	cout<<fun(m,n)<<endl;
	return 0;
}