#include <iostream>
#include<bits/stdc++.h>
using namespace std;


bool isSafe(int i,int j,int m,int n){
	return i>=0 && i<n && j>=0 && j<m;
}
int main()
{
    // printf("Hello World!\n");
    int t;
    cin>>t;
    while(t--){
    	int n,m;
	    cin>>n>>m;
	    int res=0;
	    vector<vector<int> >terror(n,vector<int>(m,0));
	    vector<vector<int> >mines(n,vector<int>(m,0));
	    vector<vector<bool> >visit(n,vector<bool>(m,false));
	    vector<vector<bool> >blown(n,vector<bool>(m,false));
	    multimap<int,pair<int,int> >mm;
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		cin>>terror[i][j];
	    		// if(terror[i][j])res++;
	    	}
	    }
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		cin>>mines[i][j];
	    		mm.insert(make_pair(mines[i][j],make_pair(i,j)));
	    	}
	    }
	    for(multimap<int,pair<int,int> >::reverse_iterator it=mm.rbegin();it!=mm.rend();++it){
	    	if(visit[(it->second).first][(it->second).second] || mines[(it->second).first][(it->second).second]==0)continue;
	    	visit[(it->second).first][(it->second).second]=true;
	    	blown[(it->second).first][(it->second).second]=true;
	    	res++;
	    	int k=it->first;
	    	for (int i = 1; i <=k; ++i)
	    	{
	    		if(isSafe((it->second).first-k,(it->second).second,m,n)){
	    			visit[(it->second).first-k][(it->second).second]=true;
	    		}
	    	}
	    	for (int i = 1; i <=k; ++i)
	    	{
	    		if(isSafe((it->second).first,(it->second).second-k,m,n)){
	    			visit[(it->second).first][(it->second).second-k]=true;
	    		}
	    	}
	    	for (int i = 1; i <=k; ++i)
	    	{
	    		if(isSafe((it->second).first+k,(it->second).second,m,n)){
	    			visit[(it->second).first+k][(it->second).second]=true;
	    		}
	    	}
	    	for (int i = 1; i <=k; ++i)
	    	{
	    		if(isSafe((it->second).first,(it->second).second+k,m,n)){
	    			visit[(it->second).first][(it->second).second+k]=true;
	    		}
	    	}

	    }
	    cout<<res<<endl;
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		if(!visit[i][j] && mines[i][j]){
	    			visit[i][j]=true;
	    			blown[i][j]=true;
	    			res++;
	    		}
	    		
	    	}
	    }
	    cout<<res<<endl;
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
	    		if(blown[i][j])cout<<i<<" "<<j<<endl;
	    	}
	    }
    }
    
    return 0;
}
