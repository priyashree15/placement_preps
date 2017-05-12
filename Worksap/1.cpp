#include<bits/stdc++.h>
using namespace std;
bool dif(std::vector<string> &v,int k){
	set<string>s;
	for (int i = 0; i < v.size(); ++i)
	{
		s.insert(v[i]);
	}
	return s.size()==k;
}
int main(int argc, char const *argv[])
{
	int n,m,k;
	cin>>n>>m>>k;
	map<int,vector<vector<int> > >mp;
	for (int i = 0; i < k; ++i)
	{
		std::vector<std::vector<int> > v(n,std::vector<int>(m));
		for (int j = 0; j < n; ++j)
		{
			for (int l = 0; l < m; ++l)
			{
				cin>>v[j][l];
			}
		}
		mp[i]=v;
	}
	int nBits=ceil(log2(k));
	nBits=max(1,nBits);
	// cout<<nBits<<endl;
	int res;
	if(k<=2)res=1;
	else{
		int flag=0;
		for (int i = nBits; i < n*m; ++i)
		{
			std::vector<string> s(k);
			std::vector<pair<int,int> > pos(i);
			std::vector<std::vector<int> > visit(n,std::vector<int>(m,0));
			for (int count= 0; count < i; ++count)
			{
				for (int i = 0; i < n; ++i)
				{
					for (int j = 0; j < m; ++j)
					{
						
						visit[i][j]=1;
						pos[count]=
					}
				}
			}
			if(dif(s,k)){
				res=i;
				flag=1;
				break;
			}
		}
		if(!flag)res=n*m;

	}
	cout<<res<<endl;
	return 0;
}