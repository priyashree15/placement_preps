#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

#define  debug //cout<<stk.top()<<endl
using namespace std;

class Solution {
public:
    void doStuff(stack<char>&stk){
        string temp="";
        while(stk.top()!='[')
        {
            temp=stk.top()+temp;
            stk.pop();
        }
        stk.pop();
        // //cout<<temp<<" "<<temp.size()<<"\n";
        int j=0;
        // debug;
        int x=stk.top()-'0';
        stk.pop();
        int count=0;
        while(x>=0 && x<=9)
        {
            //cout<<x<<endl;
            // debug;
            count+=x*pow(10,j++);
            
            if(stk.empty()==true){
                // //cout<<"empty\n";
                break;
            }
            // debug;
            x=stk.top()-'0';
            //cout<<"inside:"<<x<<endl;
            stk.pop();

        }
        // //cout<<"out\n";
        if(!stk.empty())stk.push(x+'0');
        // //cout<<count<<"\n";
        // debug;
        while(count>0)
        {
        //     // NewS+=temp;x--;
            for(int i=0;i<temp.size();i++){
                stk.push(temp[i]);
            }
            // //cout<<temp[0]<<" "<<x<<"\n";
            count--;
        }
        // //cout<<temp<<" "<<stk.top()<<"\n";
    }
    string decodeString(string s) {
        stack<char> stk;
        string temp="",NewS="",final="";
        // //cout<<s.size()<<"\n";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==']')
            {
                doStuff(stk);
            }
            else stk.push(s[i]);
            // //cout<<"here1\n";
        }
        while(!stk.empty())
        {
            // //cout<<"here\n";
            final=stk.top()+final;
            stk.pop();
        }
        return final;
    }
};
int main(int argc, char const *argv[])
{
    Solution so;
    string s;
    cin>>s;

    cout<<so.decodeString(s)<<endl;
    return 0;
}