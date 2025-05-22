#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=505;
int a[N],dp[N][N];

ll fun(int l,int r){
   if(dp[l][r]!=-1)
      return dp[l][r];
   if(l>r)
      return 0;
   ll ans=1e18;
   if(a[l]==a[r]){
      if(r-l<=1)
         return 1;
      ans=min(ans,fun(l+1,r-1));
   }
   for(int i=l;i<r;i++){
      ans=min(ans,fun(l,i)+fun(i+1,r));
   }
   return dp[l][r]=ans;

}

int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t=1;
  //cin>>t;
  while(t--)
  {
   int n;
   cin>>n;
   memset(dp,-1,sizeof dp);
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   ll ans=fun(0,n-1);
   cout<<ans<<'\n';

  }
  return 0;
}
//https://codeforces.com/contest/607/problem/B