#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node{
	int freq;
	char data;
	struct Node *left,*right;
	Node(int f,char d,Node *x,Node *y){
		freq=f;data=d;
		left=x;
		right=y;
	}
	bool operator <(Node const &r)const{
		return freq>r.freq;
	}
};
void huffman(std::vector<char> &v,std::vector<int> f){
	priority_queue<Node>pq;
	for (int i = 0; i < v.size(); ++i)
	{
		pq.push(Node(f[i],v[i],NULL,NULL));
	}
	
	while(!pq.empty()){
		struct Node *x=pq.top();pq.pop();
		if(!pq.empty()){
			struct Node *y=pq.top();
			pq.pop();
			int n_f=x->freq+y->freq;
			pq.push(Node(n_f,'I',x,y));
		}
	}
}
int main(int argc, char const *argv[])
{
	int n;
	std::vector<int> f(n);
	std::vector<char> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i]>>f[i];
	}
	huffman(v,f);
	return 0;
}