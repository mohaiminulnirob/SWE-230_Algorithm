#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int mod=1e9+7;
const int N=1e6+9;
int dp[N];
ll n;
ll cnt(ll x, ll a[]){
	if(dp[x]!=-1)
		return dp[x];
	if(x==0) return 0;
	// if(x<a[0])
	// 	return INT_MAX;
	ll mn=INT_MAX;
	for(int i=0;i<n;i++){
		if(a[i]<=x)
			mn=min(mn,1+cnt(x-a[i],a));
	}
	return dp[x]=mn;
}
int32_t main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

  int t=1;
 // cin>>t;
  while(t--)
  {
   memset(dp, -1,sizeof dp);
   ll x;
   cin>>n>>x;
   ll a[n];
   for(int i=0;i<n;i++)
   	cin>>a[i];
   sort(a,a+n);
   ll ans=cnt(x,a);
   if(ans==INT_MAX)
   	ans=-1;
   cout<<ans<<'\n';
  }
  return 0;
}
//https://cses.fi/problemset/task/1634