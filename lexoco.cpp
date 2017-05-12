#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <set>
#include <algorithm> 
#include <limits.h>
#include <cstring>
#define  debug ////cout<<stk.top()<<endl
using namespace std;

class Solution {
public:
 vector<int> lexicalOrder(int n) {
           set<string>s;
           std::vector<int> res;
           for (int i = 1; i <= n; ++i)
           {
               s.insert(to_string(i));
           }
           return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    

    int n;
    cin>>n;
    std::vector<int> v=so.lexicalOrder(n);
    for (int i = 0; i < n; ++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return 0;
}