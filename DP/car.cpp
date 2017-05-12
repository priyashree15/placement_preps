#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

class Solution {
public:
    int car(std::vector<int> &v,int n) {
        
        if(!n)return 0;
        std::vector<int> res(n+1);
        for (int i = 0; i < n; ++i)
        {
            cout<<v[i]<<"\t";
        }
        cout<<endl;
        for (int i = 1; i <=n; ++i)
        {
            int max_val=INT_MIN;
            for (int j = 0; j < i; ++j)
            {
                max_val=max(max_val,v[j]+res[i-j-1]);
            }
            cout<<max_val<<endl;
            res[i]=max_val;
        }
        for (int i = 0; i < n+1; ++i)
        {
            cout<<res[i]<<"\t";
        }
        cout<<endl;
        return res[n];
    }
        
};
int main(int argc, char const *argv[])
{
    Solution so;
    int n;
    cin>>n;
    int in;
    std::vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        
        cin>>in;
        cout<<in<<endl;
        v.push_back(in);
    }
    for (int i = 0; i < n; ++i)
    {
        cout<<v[i]<<"\t";
    }
    cout<<endl;
    cout<<so.car(v,n)<<endl;
    return 0;
}