#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
	std::vector<int> calculateSpan(std::vector<int> &v)
	{
		stack<int>st;
		std::vector<int> res;
		res.push_back(1);

		st.push(0);
		for(int i=1;i<v.size();i++)
		{
			while(!st.empty() && v[st.top()]<=v[i])st.pop();
			res.push_back(st.empty()?i+1:i-st.top());
			st.push(i);
		}
		return res;
	}
};	
int main(int argc, char const *argv[])
{
	int n;
	Solution  so;
	std::vector<int> v;;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int in;
		cin>>in;
		v.push_back(in);
	}
	std::vector<int> s=so.calculateSpan(v);
	for (int i = 0; i < n; ++i)
	{
		cout<<s[i]<<"\t";
		// s.pop();
	}
	cout<<endl;
	return 0;
}