#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int lis(vector<int>& nums) {
        int n=nums.size();
        if(!n)return 0;
        std::vector<int> v(n,1);
        for (int i = 1; i < n; ++i)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && v[i]<v[j]+1)
                    v[i]=v[j]+1;
            }
        }
        
        return v[n-1];
    }
        
};
int main(int argc, char const *argv[])
{
    Solution so;
    int n;
    cin>>n;
    std::vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int in;
        cin>>in;
        v.push_back(in);
    }
    // vector <int> res=so.lis(v);
    // for(int i=0;i<res.size();i++)
    // {
    //     cout<<res[i];
    // }
    cout<<so.lis(v)<<endl;
    return 0;
}