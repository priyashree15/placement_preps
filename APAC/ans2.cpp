#include<bits/stdc++.h>
using namespace std;
 
#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",&mark)
#define sl(mark) scanf("%lld",&mark)
#define debug(mark) printf("check%d\n",mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 100010
#define MOD 1000000007
ll cnt[N];
vector<int> v[N];
ll mod;
ll pow1(ll a,ll b)
{
	if(b==0)	return 1%mod;
	ll ret=pow1(a,b/2);
	ret=(ret*ret)%mod;
	if(b&1)	ret=(a*ret)%mod;
	return ret;
}
int main()
{
	// freopen("B1.in","r",stdin);
	// freopen("B1.out","w",stdout);
	int t;
	sd(t);
	for(int tt=1;tt<=t;++tt)
	{
		ll a,b,n,k,i,j;
		sl(a);sl(b);sl(n);sl(k);
		clr(cnt);
		for(i=0;i<k;++i)
			v[i].clear();
		mod=k;
		for(i=0;i<k;++i)
			cnt[i]=n/k;
		ll low=k*(n/k);
		for(i=low+1;i<=n;++i)
			cnt[i%k]++;
		for(i=0;i<k;++i)
			cnt[i]%=MOD;
		for(i=0;i<k;++i)
			v[pow1(i,b)].PB(i);
		ll ans=0;
		for(i=0;i<k;++i)
		{
			int Left=(k-pow1(i,a))%k;
			for(j=0;j<v[Left].size();++j)
			{
				if(v[Left][j]!=i)
					ans=(ans+cnt[i]*cnt[v[Left][j]]%MOD)%MOD;
				else
					ans=(ans+cnt[i]*(cnt[i]-1+MOD)%MOD)%MOD;
			}
		}
		printf("Case #%d: %lld\n",tt,ans);
	}
}
