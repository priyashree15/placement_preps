#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
long unfair(vector<long> I,vector<long> J){
    long sum=0;
    for(int i=0;i<I.size();i++){
        for(int j=0;j<J.size();j++){
            sum+=abs(I[i]-J[j]);
            cout<<sum<<" "<<I[i]<<" "<<J[j]<<"\n";
        }
    }
    cout<<sum<<"\n";
    return sum;
}
void split(vector<long> &a,vector<long> &I,vector<long> &J,int s,int e){
     for(int i=s;i<e;i++)I.push_back(a[i]);
     for(int i=e+1;i<a.size();i++)J.push_back(a[i]);
    if(s!=0)for(int i=0;i<s;i++)J.push_back(a[i]);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    long res=INT_MAX;
    cin>>n>>k;
    vector<long>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int dp[n][n];
    for(int i=0;i<n;i++){
        vector<long>I,J;
        
         for(int j=i;j<n;j++){
            split(a,I,J,i,j);
            res=min(res,unfair(I,J));
            // break;
        }
    }
    cout<<res<<"\n";
    return 0;
}
