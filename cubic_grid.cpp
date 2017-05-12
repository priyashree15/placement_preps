#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    
    char m[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>m[i][j];
    }
    if(n%2==0)cout<<"0";
    else{
        int l,r,u,d,tl,tr,bl,br;
        int c=n/2;
        if(m[c][c]=='.')l=r=u=d=tl=tr=bl=br=1;
        else l=r=u=d=tl=tr=bl=br=0;
        
        int x=c-1,y;
        while(x>=0){
            if(m[c][x--]=='.')l++;
            else break;
        }
        x=c+1;
        while(x<n && r<=l){
            if(m[c][x++]=='.')r++;
            else break;
        }
        x=c-1;
        while(x>=0 && x<=r){
            if(m[x--][c]=='.')u++;
            else break;
        }
        x=c+1;
        while(x<n && d<=u){
            if(m[x++][c]=='.')d++;
            else break;
        }
        x=c-1;
        while(x>=0 && tl<=l){
            if(m[x][x]=='.'){
                tl++;
                x--;
            }
                
            else break;
        }
        x=c+1;
        while(x<n && br<=l){
            if(m[x][x]=='.'){
                br++;
                x++;
            }
                
            else break;
        }
        x=c+1,y=c-1;
        while(x<n && y>=0 && bl<=l){
            if(m[x++][y--]=='.'){
                bl++;
                //x--;
            }
                
            else break;
        }
        x=c+1,y=c-1;
        while(x<n && y>=0 && tr<=l){
            if(m[y--][x++]=='.'){
                tr++;
                //x--;
            }
                
            else break;
        }
        cout<<l<<" "<<r<<" "<<u<<" "<<d<<" "<<tl<<" "<<tr<<" "<<bl<<" "<<br<<endl;
        l=min(l,r);
        l=min(l,u);
        l=min(l,d);
        l=min(l,tl);
        l=min(l,tr);
        l=min(l,bl);
        l=min(l,br);
        cout<<l;
    }
    return 0;
}
