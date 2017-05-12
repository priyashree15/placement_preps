#include<bits/stdc++.h>
using namespace std;
// void swap(char *a,char *b ){
// 	char t=*a;
// 	*a=*b;
// 	*b=t;
// }
// void print(std::vector<char> &v){
// 	for (int i = 0; i < v.size(); ++i)
// 		{
// 			cout<<v[i];
// 		}
// 		cout<<endl;
// }
int fun(std::vector<int> &v,int n,int i,int I,int M){
	if(i<n){
		// cout<<"debug:"<<I<<" "<<v[i]<<" "<<M<<"\t";

		int m1=((I+v[i])>M)?-1:I+v[i];
		// cout<<"value of t:"<<t<<"\t";
		// if((t)>M)m1=-1;
		// else m1=I+v[i];
		int m2=((I-v[i])<0)?-1:(I-v[i]);
		int x=max(m1,m2);
		// cout<<i<<":\t"<<m1<<" "<<m2<<endl;
		if(m1!=-1)x=max(x,fun(v,n,i+1,m1,M));
		if(m2!=-1)x=max(x,fun(v,n,i+1,m2,M));
		return x;
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	int I,M;
	cin>>I>>M;
	cout<<fun(v,n,0,I,M)<<endl;
	return 0;
}