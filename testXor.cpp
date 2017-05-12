#include<iostream>
using namespace std;
void f1(int *a,int *b){
	(*a) ^=(*b) ^=(*a) ^= (*b);
} 
int main(){
	int a=2,b=3;
	f1(&a,&b);
	cout<<a<<" "<<b<<endl;
	return 0;
}