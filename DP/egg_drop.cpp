#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

class Solution {
public:
    int egg(int n,int k){
        if(k==1|| k==0||n==1)return k;
        std::vector<std::vector<int> > v;
        v.resize(n+1,std::vector<int>(k+1,0));
        int value;
        for (int i = 1; i < k+1; ++i)
        {
            v[1][i]=i;
        }
        for (int i = 1; i < n+1; ++i)
        {
            v[i][1]=1;
        }
        for (int i = 2; i <n+1 ; ++i)
        {
            for (int j = 2; j < k+1; ++j)
            {
                v[i][j]=INT_MAX;
                for (int l= 1; l <=j; ++l)
                {
                    value=1+max(v[i-1][l-1],v[i][j-l]);
                    v[i][j]=min(value,v[i][j]);
                }

            }
        }
        return v[n][k];
    }
        
};
int main(int argc, char const *argv[])
{
    Solution so;
    int n,k;
    cin>>n;
    cin>>k;
    cout<<so.egg(n,k)<<endl;
    return 0;
}