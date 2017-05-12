#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int prec(char c)
{
	switch(c)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}
}
bool isOperand(char c)
{
	return (c>='a' && c<='z' || c>='A' && c<='Z');
}
int main(int argc, char const *argv[])
{
	stack<char>s;
	string str;
	cin>>str;
	vector<char>res;
	for(int i=0;i<str.size();i++)
	{
		if(isOperand(str[i]))res.push_back(str[i]);
		else
		{
			if(str[i]=='(')s.push(str[i]);
			else if(str[i]==')')
			{
				while(!s.empty() && s.top()!='(')
				{
					res.push_back(s.top());
					s.pop();
				}
				s.pop();
			}
			else
			{
				while(!s.empty() && prec(s.top())>=prec(str[i]))
				{
					res.push_back(s.top());
					s.pop();
				}
				s.push(str[i]);
			}
		}
	}
	while(!s.empty())
	{
		res.push_back(s.top());
		s.pop();
	}
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<"\t";
	}
	cout<<endl;

	return 0;
}