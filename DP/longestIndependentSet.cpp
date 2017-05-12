#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <map>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
struct node
	{
		int data;
		struct node *left,*right;
	};	
	struct node* newNode(int data){
		struct node* newN=(struct node*)malloc(sizeof(struct node*));
		newN->data=data;
		newN->left=NULL;
		newN->right=NULL;
		return newN;
	}
int LISS(struct node *root,map<int,int>&m){
	if(root==NULL)return 0;
	if(m[root->data])return m[root->data];
	int incl=LISS(root->left,m)+LISS(root->right,m);
	int excl=1;
	if(root->left)excl+=LISS(root->left->left,m)+LISS(root->left->right,m);
	if(root->right)excl+=LISS(root->right->left,m)+LISS(root->right->right,m);
	return m[root->data]=max(incl,excl);
}
int LISS_wrap(struct node *root){
	if(root==NULL)return 0;
	map<int,int>m;
	return m[root->data]=LISS(root,m);
}
int main(int argc, char const *argv[])
{
	
	struct node *root=newNode(20);
	root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
    cout<<LISS_wrap(root)<<endl;
    return 0;
}