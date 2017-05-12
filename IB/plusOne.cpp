#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int coverPoints(vector<int> &X, vector<int> &Y);
	
};
vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    int c=1,i=n-1;
    while(c && i>=0){
        if(A[i]<9){
            A[i]=A[i]+1;
            c=0;
        }
        else{
            A[i]=0;
            c=1;
        }
    }
}
int main(int argc, char const *argv[])
{
	int X[]={-2};
	int Y[]={7};
	Solution so;
	cout<<so.coverPoints(X,Y)<<endl;
	return 0;
}