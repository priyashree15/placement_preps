bool isPrime(int n){
    if(n<=1)return false;
    if(n<=3)return true;
    if(n%2==0 || n%3==0)return false;
    for(int i=5;i*i<n;i+=6){
        if(n%i==0 || n%(i+2)==0)return false;
    }
    return true;
}
int fun(vector<int>&a){
    int res=0;
    int n=a.size();
    
    for(int c=0;)
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<fun(a)<<endl;
    }
    return 0;
}
