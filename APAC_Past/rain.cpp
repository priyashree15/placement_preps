#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <map>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Solution {
public:
    vector<vector<int> > left(vector<vector<int> >& board){
        int n=board.size();
        int m=board[0].size();
        vector<vector<int> > l(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            l[i][0]=board[i][0];
            for(int j=1;j<m;j++)
                l[i][j]=max(l[i][j-1],board[i][j]);
        }
        // cout<<"leftready\n";
        return l;
    }
    vector<vector<int> > right(vector<vector<int> >& board){
        int n=board.size();
        int m=board[0].size();
        vector<vector<int> > r(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            r[i][m-1]=board[i][m-1];
            for(int j=m-2;j>=0;j--)
                r[i][j]=max(r[i][j+1],board[i][j]);
        }
       
        // cout<<"rightready\n";
        return r;
    }
    vector<vector<int> > top(vector<vector<int> >& board){
        int n=board.size();
        int m=board[0].size();
        vector<vector<int> > t(n,vector<int>(m,0));
        // cout<<val(board,0,0)<<endl;
        for(int i=0;i<m;i++){
            t[0][i]=board[0][i];
            // cout<<val(board,0,i)<<" ";
            for(int j=1;j<n;j++){
               
                t[j][i]=max(t[j-1][i],board[j][i]);
                //  if(j==3 && i==0)cout<<t[j-1][i]<<" "<<val(board,j,i)<<endl;
                // cout<<t[j][i]<<" ";
            }
            // cout<<endl;   
        }
        // cout<<"topready\n";
        return t;
    }
    vector<vector<int> > down(vector<vector<int> >& board){
        int n=board.size();
        int m=board[0].size();
        vector<vector<int> > d(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            d[n-1][i]=board[n-1][i];
            for(int j=n-2;j>=0;j--)
                d[j][i]=max(d[j+1][i],board[j][i]);
        }
        // cout<<"downready\n";
        return d;
    }
    int minimum(int x,int y,int z,int w){
        return min(min(min(x,y),z),w);
    }
    int trapRainWater(vector<vector<int> >& heightMap) {
        int n=heightMap.size();
        if(!n)return 0;
        int m=heightMap[0].size();
        if(n<3 || m<3)return 0;
        vector<vector<int> > d(n,vector<int>(m,0));
        vector<vector<int> > t(n,vector<int>(m,0));
        vector<vector<int> > l(n,vector<int>(m,0));
        vector<vector<int> > r(n,vector<int>(m,0));
        l=left(heightMap);r=right(heightMap);
        t=top(heightMap);d=down(heightMap);
        int water=0;
        cout<<"left:"<<endl;
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{
        		cout<<l[i][j]<<" ";
        	}
        	cout<<endl;
        }
        cout<<endl;
        cout<<"right:"<<endl;
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{
        		cout<<r[i][j]<<" ";
        	}
        	cout<<endl;
        }
        cout<<endl;
        cout<<"top:"<<endl;
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{
        		cout<<t[i][j]<<" ";
        	}
        	cout<<endl;
        }
        cout<<endl;
        cout<<"down:"<<endl;
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < m; ++j)
        	{
        		cout<<d[i][j]<<" ";
        	}
        	cout<<endl;
        }
        cout<<endl;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int x=minimum(l[i][j],r[i][j],t[i][j],d[i][j])-heightMap[i][j];
                // cout<<x<<" ";
                water+=x;
            }
            // cout<<endl;
        }
        return water;
    }
};
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	std::vector<int> v;
	Solution so;
	while(t--){
		int n,m;
		cin>>n>>m;
		std::vector<std::vector<int> > b(n,std::vector<int>(m,0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>b[i][j];
			}
		}
		v.push_back(so.trapRainWater(b));
	}
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<"Case #"<<i+1<<": "<<v[i]<<endl;
	}
    return 0;
}