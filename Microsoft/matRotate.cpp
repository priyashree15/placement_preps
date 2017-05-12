#include<bits/stdc++.h>
#define ct(x) cout<<"debug"<<x<<endl
using namespace std;
void rotate(std::vector<int> &v,int k){
	int n=v.size();
	k=k%n;
	std::vector<int> temp(n);
	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<" ";
	}cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		if(i+k<n)
			temp[i+k]=v[i];
		else
			temp[(i+k)%n]=v[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<" ";
	}cout<<endl;
	v=temp;
}
void print(std::vector<std::vector<int> >&v){
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
void fun(std::vector<std::vector<int> >&v,int m,int n,int k){
	ct(1);
	int r=0,c=0,pr=0,pc=0,pm,pn;
	while(r<m && c<n){
		std::vector<int> newV;
		ct(2);
		pr=r,pc=c,pm=m,pn=n;
		print(v);
		ct(3);
		for(int i=c;i<n;i++){
			newV.push_back(v[r][i]);
		}
		r++;
		for (int i = r; i < m; ++i)
		{
			newV.push_back(v[i][n-1]);
		}
		n--;
		if(r<m){
			for (int i = n-1; i>=c; --i)
			{
				newV.push_back(v[m-1][i]);
			}
		}
		m--;
		if(c<n){
			for (int i = m-1; i >=r; --i)
			{
				newV.push_back(v[i][c]);
			}
		}
		c++;
		rotate(newV,k);
		int j=0;
		for(int i=pc;i<pn;i++){
			v[pr][i]=newV[j++];
		}
		pr++;
		for (int i = pr; i < pm; ++i)
		{
			v[i][pn-1]=newV[j++];
		}
		pn--;
		if(pr<pm){
			for (int i = pn-1; i>=pc; --i)
			{
				v[pm-1][i]=newV[j++];
			}
		}
		pm--;
		if(pc<pn){
			for (int i = pm-1; i >=pr; --i)
			{
				v[i][pc]=newV[j++];
			}
		}
		pc++;
	}
}
int main(int argc, char const *argv[])
{
	int m,n,k;
	cin>>m>>n>>k;
	std::vector<std::vector<int> > v(m,std::vector<int>(n,0));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>v[i][j];
		}
	}
	
	fun(v,m,n,k);
	print(v);
	return 0;
}