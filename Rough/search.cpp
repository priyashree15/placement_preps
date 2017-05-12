#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int coverPoints(vector<int> &X, vector<int> &Y);
	
};
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int row[]={0,0,-1,-1,-1,1,1,1};
    int col[]={-1,1,-1,0,1,-1,0,1};

    // std::vector<bool> v(X.size(),false);
    int res=0;
    stack<int>s1;
    // s1.push(0);
    for (int i = 1; i < X.size(); ++i)
    {
    	// int t=s1.top();
    	// s1.pop();
    	for (int j = 0; j < 8; ++j){
			int newR=X[i-1]+row[j];
			int newC=Y[i-1]+col[j];
			if(X[i]==newR a&& Y[i]==newC){
				res++;
				// s1.push(i);
				break
			}
		}
    	
    }
    return res;
}
int main(int argc, char const *argv[])
{
	int X[]={-2};
	int Y[]={7};
	Solution so;
	cout<<so.coverPoints(X,Y)<<endl;
	return 0;
}