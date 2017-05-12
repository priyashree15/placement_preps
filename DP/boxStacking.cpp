#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <set>
#include <algorithm> 
#define  debug ////cout<<stk.top()<<endl
using namespace std;

class Solution {
public:
    void print(std::vector<std::vector<int> > v,int n){
        for(int i=0;i<n;i++){
            cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<"\n";
        }
    }
    int base(std::vector<int> v){
        return v[1]*v[2];
    }
    void sort(std::vector<std::vector<int> > &b)
    {
        for(int i=1;i<b.size();i++){
            std::vector<int> temp=b[i];
            int j=i-1;
            // cout<<"sort:"<<base(b[i])<<endl;
            while(j>=0 && base(b[j])>base(temp))
            {
                // cout<<"sort:"<<base(b[i])<<" "<<base(b[j])<<"\n";
                b[j+1]=b[j];
                j--;
            }
            b[j+1]=temp;
        }
    }
    int boxStack(std::vector<std::vector<int> > &box,int n){
        // print(box,3*n);
        cout<<endl;
        std::vector<int> H(3*n,1);
        int m=H[0];
        sort(box);
        // print(box,3*n);
        reverse(box.begin(),box.end());
        print(box,3*n);
        cout<<endl;
        for (int i = 0; i < 3*n; ++i)
        {
            H[i]=box[i][0];
        }
        for(int i=1;i<3*n;i++){
            for (int j = 0; j < i; ++j)
            {
                if(box[j][1]>box[i][1] && box[j][2]>box[i][2] && H[i]<H[j]+box[i][0])
                    H[i]=H[j]+box[i][0];
            }
            m=max(H[i],m);
        }
        return m;
    }
};

void sort_test(int b[],int n)
    {
        for(int i=1;i<n;i++){
            int temp=b[i];
            int j=i-1;
            // cout<<"sort:"<<base(b[i])<<endl;
            while(j>=0 && b[j]>temp)
            {
                // cout<<"sort:"<<base(b[i])<<" "<<base(b[j])<<"\n";
                b[j+1]=b[j];
                j--;
            }
            b[j+1]=temp;
        }
    }
void in(std::vector<std::vector<int> > &v,int h,int w,int d,int i){
    v[i][0]=h;
    v[i][1]=w;
    v[i][2]=d;
}
void rotate(int *h,int *w,int *d){
    int t=*h;
    *h=*d;
    *d=max(*w,t);
    *w=min(*w,t);
}
int main(int argc, char const *argv[])
{
    Solution so;
    // int a[]={42,24,28,6,2,3};
    // sort_test(a,6);
    // for (int i = 0; i < 6; ++i)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    int n;
    cin>>n;
    std::vector<std::vector<int> > box(3*n,std::vector<int>(3,0));
    for (int i = 0; i < 3*n;i=i+3)
    {
        int h,w,d;
        cin>>h>>w>>d;
        in(box,h,w,d,i);
        rotate(&h,&w,&d);
        in(box,h,w,d,i+1);
        rotate(&h,&w,&d);
        in(box,h,w,d,i+2);
    }
    // cout<<s.size();
    cout<<so.boxStack(box,n)<<endl;
    return 0;
}