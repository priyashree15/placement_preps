#include<bits/stdc++.h>
using namespace std;
struct trie{
	long long int val;
	struct trie *l,*r;
	trie():val(0),l(NULL),r(NULL){};
};
long long int resCal(trie *rootNode,int level,long long int value){
	if(rootNode==NULL || level<0)return 0;
	if(((long long int)1<<level)&value){
		if(rootNode->l){
			if(rootNode->l->val){
				return (1<<level)+resCal(rootNode->l,level-1,value);
			}
			return (resCal(rootNode->r,level-1,value));
		}
		return (resCal(rootNode->r,level-1,value));
	}
	if(rootNode->r){
		if(rootNode->r->val){
			return (1<<level)+resCal(rootNode->r,level-1,value);
		}
		return (resCal(rootNode->l,level-1,value));
	}
	return (resCal(rootNode->l,level-1,value));
}
void insertTrie(trie *rootNode,int level,long long int x,long long int value){
	if(level<0)return;

	if(value &((long long int)1<<level)){
		if(!rootNode->r){
			rootNode->r=new trie();
			rootNode->r->val+=x;
			insertTrie(rootNode->r,level-1,x,value);
		}
	}
	else{
		if(!rootNode->l){
			rootNode->l=new trie();
			rootNode->l->val+=x;
			insertTrie(rootNode->l,level-1,x,value);
		}
	}
	
}
long long int preSuff(std::vector<long long int> &v,int n){
	long long int pre[n+1],suf[n+1];
	pre[0]=0;
	for (int i = 1; i <=n; ++i)
	{
		pre[i]=pre[i-1]^v[i-1];
	}
	trie *rootNode=new trie();
	suf[n]=0;
	insertTrie(rootNode,32,(long long int)1,suf[n]);
	for (int i = n-1; i >=0; --i)
	{
		suf[i]=suf[i+1]^v[i];
		insertTrie(rootNode,32,(long long int)1,suf[i]);
	}
	long long int res=0,local;
	for (int i = 0; i < n+1; ++i)
	{
		insertTrie(rootNode,32,(long long int)-1,suf[i]);
		local=resCal(rootNode,32,pre[i]);
		res=max(local,res);
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int n;cin>>n;
	std::vector<long long int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	cout<<preSuff(v,n)<<endl;
	return 0;
}