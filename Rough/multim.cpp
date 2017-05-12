#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	multimap<int,int>m;
	m.insert(make_pair(2,1));
	m.insert(make_pair(2,1));
	m.insert(make_pair(1,2));
	vector<int>nums2;//{1,2,2};
	nums2.push_back(1);
	nums2.push_back(2);
	nums2.push_back(2);
	// for (multimap<int,int>::iterator it=m.begin(); it!=m.end(); ++it)
	// {
 //        std::cout << (*it).first << " => " << (*it).second << '\n';
 //        m.erase(it);
	// }
	for(int i=0;i<nums2.size();i++)
    {
    	cout<<"new"<<"\n";
        for (multimap<int,int>::iterator it1=m.begin(); it1!=m.end(); ++it1)
                std::cout << (*it1).first << " => " << (*it1).second << '\n';
        multimap<int,int>::iterator it=m.find(nums2[i]);
        if(it!=m.end()){
            // std::cout << (*it).first << " => " << (*it).second << '\n';
            // res.push_back(nums2[i]);
            m.erase(it);
        }
        else cout<<"end"<<"\n";
    }
	return 0;
}
