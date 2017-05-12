#include <algorithm>
#include <vector>
#include <stack>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;
class Solution
{
public:
	int matrix(int m[],int n){
		// if(i==j)return 0;

		// int c=INT_MAX;
		// for (int k = i; k < j; ++k)
		// {
		// 	c=min(c,matrix(m,i,k)+matrix(m,k+1,j)+m[i-1]*m[k]*m[j]);
		// }
		// return c;

		int mat[n][n];
		for (int i = 0; i < n; ++i)
		{
			mat[i][i]=0;
		}
		for (int l=2;l<n;l++)
		{
			for (int i = 1; i+l-1 < n; ++i)
			{
				int j=i+l-1;
				mat[i][j]=INT_MAX;
				for (int k = i; k < j; ++k)
				{
					mat[i][j]=min(mat[i][j],mat[i][k]+mat[k+1][j]+m[i-1]*m[k]*m[j]);
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return mat[1][n-1];
	}
};	

int main(int argc, char const *argv[])
{
	/* code */
	Solution so;
	int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout<<"Minimum number of multiplications is "<<so.matrix(arr, n)<<"\n";
	// cout<<so.edit(s1,s2,s1.size(),s2.size())<<endl;
	return 0;
}