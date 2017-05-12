#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits.h>
#define INF INT_MAX
using namespace std;

class Solution
{
public:
	void space(string s,char buff[],int  i,int j,int n){
		if(i==n)
		{
			buff[j]='\0';
			cout<<buff<<endl;
			return;
		}
		buff[j]=s[i];
		space(s,buff,i+1,j+1,n);

		buff[j]=' ';
		buff[j+1]=s[i];
		space(s,buff,i+1,j+2,n);
	}

};	
int main(int argc, char const *argv[])
{
	// int n;
	Solution  so;
	string s;
	cin>>s;
	int n=s.size();
	char buff[2*n];
	buff[0]=s[0];
	so.space(s,buff,1,1,n);
	return 0;
}