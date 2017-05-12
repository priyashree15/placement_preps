#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
	void insertAtBottom(stack<int>&s,int z)
	{
		cout<<z<<endl;
		if(s.empty())s.push(z);
		else
		{
			int temp=s.top();
			
			if(temp>z)
			{
				s.pop();
				insertAtBottom(s,z);
				s.push(temp);
			}
			else s.push(z);
		}
	}
	void reverse(stack<int>&s,int n)
	{
		if(!s.empty())
		{
			int temp=s.top();
			s.pop();
			reverse(s,n-1);

			insertAtBottom(s,temp);
		}
	}
	// void print(stack<int>)
};	
int main(int argc, char const *argv[])
{
	int n;
	Solution  so;
	stack<int>s;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int in;
		cin>>in;
		s.push(in);
	}
	// stack<int>res=
	so.reverse(s,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<s.top()<<"\t";
		s.pop();
	}
	cout<<endl;
	return 0;
}