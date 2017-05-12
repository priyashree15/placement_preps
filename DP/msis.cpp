#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

class Solution {
public:
    int car(std::vector<int> &v,int n) {
        
        if(!n)return 0;
        std::vector<int> res(n);
        for (int i = 0; i < n; ++i)
        {
            res[i]=v[i];
        }
        cout<<endl;
        int m=INT_MIN;
        for (int i = 1; i <n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if(v[j]<v[i] && res[j]+v[i]>res[i])
                    res[i]=v[i]+res[j];
            }
            m=max(m,res[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            cout<<res[i]<<"\t";
        }
        cout<<endl;
        return m;
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
        // cout<<in<<endl;
        v.push_back(in);
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     cout<<v[i]<<"\t";
    // }
    // cout<<endl;
    cout<<so.car(v,n)<<endl;
    return 0;
}