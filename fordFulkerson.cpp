#include<bits/stdc++.h>
using namespace std;
bool bfs(std::vector<std::vector<int> > &rg,int s,int dest,std::vector<int> &parent){
	std::vector<int> v(rg.size(),false);
	queue<int>q;
	q.push(s);
	parent[s]=-1;
	v[s]=true;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for (int i = 0; i < rg.size(); ++i)
		{
			if(rg[t][i]>0 && !v[i]){
				q.push(i);
				parent[i]=t;
				v[i]=true;
			}
		}
	}
	return v[dest]==true;
}
void print(std::vector<std::vector<int> > &g){
	for (int i = 0; i < g.size(); ++i)
	{
		for(int j=0;j<g[0].size();j++){
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
}
int ford(std::vector<std::vector<int> > &g,int s,int t){
	std::vector<std::vector<int> > rg=g;
	std::vector<int> parent(g.size());
	print(rg);

	int max_flow=0;
	while(bfs(rg,s,t,parent)){
		int m=INT_MAX;
		for (int i = t; i !=s; i=parent[i])
		{
			int u=parent[i];
			m=min(m,g[u][i]);
		}
		//update
		for (int i = t; i !=s; i=parent[i])
		{
			int u=parent[i];
			rg[u][i]-=m;
			rg[i][u]+=m;
		}
		cout<<m<<endl;
		max_flow+=m;
	}
	return max_flow;
}
int main(int argc, char const *argv[])
{
	// int g[6][6] = { {0, 16, 13, 0, 0, 0},
 //        {0, 0, 10, 12, 0, 0},
 //        {0, 4, 0, 0, 14, 0},
 //        {0, 0, 9, 0, 0, 20},
 //        {0, 0, 0, 7, 0, 4},
 //        {0, 0, 0, 0, 0, 0}
 //      };
 //    std::vector<std::vector<int> > v(g,g+sizeof(g)/sizeof(g[0]));
    std::vector<std::vector<int> > v{ {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};
    cout<<ford(v,0,5)<<endl;
	return 0;
}