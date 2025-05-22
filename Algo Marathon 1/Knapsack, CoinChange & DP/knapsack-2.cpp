#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
#define INF 1e18
const int mod=1e9+7;

int32_t main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  //   #endif 

  int t=1;
  //cin>>t;
  while(t--)
  {
   int n,W;
   cin>>n>>W;
   int w[n],v[n];
   int mx=0;
   for(int i=0;i<n;i++){
      cin>>w[i]>>v[i];
      mx+=v[i];
   }
   vector<ll>dp(mx+1,INF);
   dp[0]=0;
   for(int i=0;i<n;i++){
      for(int j=mx;j>=v[i];j--){
         dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
      }
   }
   int ans=0;
   for(int i=mx;i>=0;i--){
      if(dp[i]<=W){
         ans=i;
         break;
      }
   }
   cout<<ans<<'\n';
  }
  return 0;
}
//https://atcoder.jp/contests/dp/tasks/dp_e