#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
         int bulls=0,cows=0;
         map<char,vector<int>>m;
         for(int i=0;i<secret.size();i++)
         {
             m[secret[i]].push_back(i);
         }
         for(int i=0;i<guess.size();i++)
         {
             map<char,vector<int>>::iterator it=m.find(guess[i]);
             if(it!=m.end())
             {
                 for(int j:it->second)
                 {
                     if(secret[j]==guess[j]){
                         bulls+=1;
                         vector<int>::iterator itv=j;
                         it->second.erase(itv);
                     }
                 }
             }
         }
         string s1=to_string(bulls),s2=to_string(cows);
         return s1+"A"+s2+"B";
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