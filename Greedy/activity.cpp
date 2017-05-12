#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node{
	int id;
	int s;
	int f;
	Node(int i,int xv,int fv){
		id=i;s=xv;f=fv;
	}
	bool operator <(const Node &r)const{
		return f>r.f;
	}
};
class Solution{
public:
	vector<int> maxActSet(std::vector<int>&s,std::vector<int> &f){
		// priority_queue<Node>pq;
		// for (int i = 0; i < s.size(); ++i)
		// {
		// 	pq.push(Node(i,s[i],f[i]));
		// }
		std::vector<int> res;
		// Node pre=pq.top();
		// pq.pop();
		// res.push_back(pre.id);
		// while(!pq.empty()){
		// 	Node curr=pq.top();
		// 	pq.pop();
		// 	if(curr.s>=pre.f){
		// 		res.push_back(curr.id);
		// 		pre=curr;
		// 	}
		// }
		res.push_back(0);
		int j=0;
		for (int i = 1; i < s.size(); ++i)
		{
			if(s[i]>=f[j]){
				res.push_back(i);
				j=i;
			}
		}
		return res;
	}
};
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	std::vector<int> s(n);
	std::vector<int> f(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>s[i]>>f[i];
	}
	Solution so;
	std::vector<int> res=so.maxActSet(s,f);
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}