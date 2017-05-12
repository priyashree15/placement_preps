#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int edit(vector<char>& v1, std::vector<char>& v2,int m,int n) {
        std:std::vector<std::vector<int> > res;
        res.resize(m+1,std::vector<int>(n+1,0));
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if(i==0)res[i][j]=j;
                else if(j==0)res[i][j]=i;
                else if(v1[i-1]==v2[j-1])res[i][j]=res[i-1][j-1];
                else res[i][j]=min(res[i-1][j-1],min(res[i-1][j],res[i][j-1]))+1;
            }
        }
        return res[m][n];
    }
        
};
int main(int argc, char const *argv[])
{
    Solution so;
    int n,m;
    cin>>m;
    cin>>n;
    std::vector<char> v1(m),v2(n);
    for (int i = 0; i < m; ++i)
    {
        cin>>v1[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin>>v2[i];
    }
    
    cout<<so.edit(v1,v2,m,n)<<endl;
    return 0;
}