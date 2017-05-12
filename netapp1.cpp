#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int digitXor(int n){
	int res=n%10;
	n=n/10;
	while(n){
		res^=n%10;
		n/=10;
	}
	return res;
}
int gcd(int x,int y){
	if(x==0)return y;
	return gcd(y%x,x);
}
void lowest(int &den3, int &num3)
{
	int common = gcd(num3,den3);
	den3 = den3/common;
    num3 = num3/common;
}
void addFrac(int num1, int den1, int num2,int den2, int &num3, int &den3){
	// cout<<num1<<"/"<<den1<<" "<<num2<<"/"<<den2<<endl;
	den3 = gcd(den1,den2);
	den3 = (den1*den2) / den3;
	num3 = (num1)*(den3/den1) + (num2)*(den3/den2);
	lowest(den3,num3);
	// cout<<"sum="<<num3<<"/"<<den3<<endl;
}
int main()
{
    int t;cin>>t;
    while(t--){
    	int n;cin>>n;
    	map<int,int>mp;
    	for(int i=1;i<=n;i++){
    		int x=digitXor(i);
    		mp[x]++;
    	}
    	int num1=0,den1=1;
    	int num2,den2=n,num3,den3;
    	for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it){
    		num2=(it->first)*(it->second);
    		addFrac(num1, den1, num2, den2, num3, den3);
    		num1=num3;
    		den1=den3;
    		// cout<<it->first<<" "<<it->second<<endl;
    	}
    	cout<<num3<<"/"<<den3<<endl;
    }
    return 0;
}
