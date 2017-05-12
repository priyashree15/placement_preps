#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#define mod
#include <cmath>
using namespace std;
long long lookup[101][1001];
long long sumN(int n,int sum){

	if(n==0)return sum==0;
	long long res=0;
	if(lookup[n][sum]!=1)return lookup[n][sum];
	for (int i = 0; i < 10; ++i)
	{
		if(sum-i>=0){
			res+=sumN(n-1,sum-i);
		}
		return lookup[n][sum]=res;
	}
}
long long sumWrapUp(int n,int sum){
// 	long long lookup[n+1][sum+1];
	long long res=0;
	memset(lookup, -1, sizeof lookup);
	
	for (int i = 0; i < 10; ++i)
	{
		if(sum-i>=0){
			res+=sumN(n-1,sum-i);
		}
		long long x=pow(10,9)+7;
		return res%(x);
	}
}
int main(int argc, char const *argv[])
{
    int t;
    while(t--){
	int n;
	cin>>n;
	int sum;
	cin>>sum;
	cout<<sumWrapUp(n,sum)<<endl;
    }
	return 0;
}