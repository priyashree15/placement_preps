#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int coin(vector<int>& nums,m,target) {
        std::vector<std::vector<int> > res;
        res.resize(target+1,std::vector<int> (m,0))
        for (int i = 0; i < count; ++i)
        {
            /* code */
        }
    }
        
};
int main(int argc, char const *argv[])
{
    Solution so;
    int n,target;
    cin>>n;
    std::vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int in;
        cin>>in;
        v.push_back(in);
    }
    cin>>target;
    cout<<so.coin(v,n,target)<<endl;
    return 0;
}