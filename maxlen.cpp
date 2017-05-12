#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include<set>
#define  debug ////cout<<stk.top()<<endl
using namespace std;

class Solution {
public:
    bool valid(string s,int k){
       map<char,int>m;
       //cout<<s<<endl;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]])m[s[i]]++;
            else m[s[i]]=1;
        } 
        //cout<<m.size()<<"\n";
        for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
        {
            //cout<<"map alue:"<<it->second<<"\n";
            if(it->second<k)return false;
        }
        //cout<<"out";
        return true;
    }
    int longestSubstring(string s, int k) {
        map<char,int>m,start;
        
        int maxlen=0;
        if(k==1 || k==0)return s.size();
        for(int i=0;i<s.size();i++)
        {
            set<char> ss;
            ss.insert(s[i]);
            for(int j=i+k-1;j<s.size();j++)
            {
                if(ss.size()>=2){
                    set<char>::iterator sit=ss.find(s[j]);
                    if(sit!=ss.end()){
                        maxlen=max(maxlen,j+1-i);
                        continue;
                    }
                }
                ss.insert(s[j]);
                if(valid(s.substr(i,j+1-i),k)){
                    //cout<<"true\n";
                    maxlen=max(maxlen,j+1-i);
                }
                //cout<<maxlen<<"\n";
            }
            // //cout<<maxlen<<"\n";
        }
        return maxlen;
        
    }
};
int main(int argc, char const *argv[])
{
    Solution so;
    string s;
    int k;
    cin>>s>>k;
    // cout<<s.size();
    cout<<so.longestSubstring(s,k)<<endl;
    return 0;
}