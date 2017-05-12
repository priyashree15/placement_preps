#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>> &matrix) {
        mat=matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++)
        {
            for(int j=col1;j<=col2;j++)
            {
                cout<<mat[i][j]<<"\t";
                sum+=mat[i][j];
            }
            cout<<endl;
        }
        return sum;
    }
};
int main(int argc, char const *argv[])
{
    Solution so;
    int n,k;
    cin>>n;
    cin>>m;
    
    
    return 0;
}