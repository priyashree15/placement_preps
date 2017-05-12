#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	list<int> myList;
	myList.assign(5,2);
	myList.assign(1,2);
	
	myList.push_back(8);
	myList.push_front(4);
	list<int>::iterator itr=find(myList.begin(),myList.end(),7);
	myList.insert(itr,7);
	list<int>::iterator it;
	for(it=myList.begin();it!=myList.end();++it)
		cout<<*it<<"\t";
	cout<<endl;
	return 0;
}
