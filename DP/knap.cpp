#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int knap(std::vector<int> w,std::vector<int> v, int W, int n)
    {
        std::vector<std::vector<int> > res;
        res.resize(n+1,std::vector<int>(W+1,0));
        for (int i = 1; i <=n; ++i)
        {
            for (int j = 1; j <= W; ++j)
            {
                if(w[i-1]<=W)
                {
                    res[i][j]=max(v[i-1]+res[i-1][j-w[i-1]],res[i-1][j]);
                }
                else res[i][j]=res[i-1][j];
            }
        }
        return res[n][W];
    }
        
};
int main(int argc, char const *argv[])
{
    Solution so;
    int n,target;
    cin>>n;
    std::vector<int> w,v;
    for (int i = 0; i < n; ++i)
    {
        int in;
        cin>>in;
        w.push_back(in);
    }
    for (int i = 0; i < n; ++i)
    {
        int in;
        cin>>in;
        v.push_back(in);
    }
    int W;
    cin>>W;
    cout<<so.knap(w,v,W,n)<<endl;
    return 0;
}