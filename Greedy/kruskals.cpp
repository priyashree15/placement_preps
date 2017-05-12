#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct edge{
	int s,d,w;
	edge(int sv,int dv,int wv){
		s=sv;d=dv;w=wv;
	}
	bool operator<(const edge &r)const{
		return w>r.w;
	}
};
class  Graph
{
	int V,E;
	std::vector<edge> ed;
	int find(std::vector<int> &p,int i);
	void Union(std::vector<int> &p,int x,int y);
public:
	Graph(int v);
	void addEdge(int s,int d,int w);
	bool isCyclc();
	void kruskal();	
};
Graph::Graph(int v){
	this->V=v;
}
void Graph::addEdge(int s,int f,int w){
	ed.push_back(edge(s,f,w));
}
int Graph::find(std::vector<int> &parent,int i){
	if(parent[i]==-1)return i;
	return(parent,parent[i]);
}
void Graph::Union(std::vector<int> &parent,int x,int y){
	int xset=find(parent,x);
	int yset=find(parent,y);
	parent[xset]=yset;
}
bool Graph::isCyclc(){
	std::vector<int> parent(V,-1);
	for (int i = 0; i < ed.size(); ++i)
	{
		int x=find(parent,ed[i].s);
		int y=find(parent,ed[i].d);
		// cout<<ed[i].s<<" "<<ed[i].d<<" "<<x<<" "<<y<<endl;
		// cout<<ed[i].s<<" "<<ed[i].d<<endl;
		if(x==y)return true;
		Union(parent,x,y);
	}
	return false;
}
void Graph::kruskal(){
	priority_queue<edge>pq;
	for (int i = 0; i < ed.size(); ++i)
	{
		pq.push(ed[i]);
	}
	int e=0;
	std::vector<int> parent(V,-1);
	while(!pq.empty()){
		edge x=pq.top();
		pq.pop();
		// cout<<x.s<<" "<<x.d<<endl;		

		int a=find(parent,x.s);
		int b=find(parent,x.d);

		if(a!=b){
		
			e++;
			cout<<x.s<<"--"<<x.d<<endl;
			if(e==V-1)break;
		}

	}
}
int main(int argc, char const *argv[])
{
	int v=3;
	Graph g(4);
	g.addEdge(0,1,10);
	
	g.addEdge(0,2,6);
	g.addEdge(0,3,5);
	g.addEdge(1,3,15);
	g.addEdge(2,3,4);
	g.kruskal();
	return 0;
}