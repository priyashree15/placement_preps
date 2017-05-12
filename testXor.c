// #include<iostream>
// using namespace std;
#include<stdio.h>
void f1(int *a,int *b){
	(*a) ^=(*b) ^=(*a) ^= (*b);
} 
int main(){
	int a=2,b=3;
	a=10;b=10;
	int c=a++ + ++b;
	printf("%d %d %d\n",c,b,a );
	return 0;
	f1(&a,&b);
	printf("%d %d",a,b);
	return 0;
}