#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int MOD=998244353;

int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t=1;
  //cin>>t;
  while(t--)
  {
  	ll n;
  	cin>>n;
  	ll ans=n;
    map<ll,ll>m;
  	for(int i=0;i<n-1;i++){
  		ll a,b;
  		cin>>a>>b;
  		m[a]++;
  		m[b]++;
  		ans=ans*m[a]%MOD*m[b]%MOD;
  	}
  	cout<<ans<<'\n';
  }
  return 0;
}