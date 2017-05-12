#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int lps(string s) {
        int n=s.size();
        if(!n)return 0;
        std::vector<std::vector<int> > res(n,std::vector<int>(n,0));
        for (int i = 0; i < n; ++i)
        {
            res[i][i]=1;
        }
        for (int p = 2; p <=n; ++p)
        {
            for (int i = 0; i+p-1 < n; ++i)
            {
                int j=i+p-1;
                if(s[i]==s[j] && p==2)res[i][j]=2;
                else if(s[i]==s[j]) res[i][j]=res[i+1][j-1]+2;
                else res[i][j]=max(res[i+1][j],res[i][j-1]);
            }
        }
        return res[0][n-1];
    }
        
};
int main(int argc, char const *argv[])
{
    Solution so;
    string s;
    cin>>s;

    cout<<so.lps(s)<<endl;
    return 0;
}