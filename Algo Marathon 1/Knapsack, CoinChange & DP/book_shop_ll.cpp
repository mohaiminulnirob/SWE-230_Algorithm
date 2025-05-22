#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t=1;
  //cin>>t;
  while(t--)
  {
   ll n,x;
   cin>>n>>x;
   ll h[n],s[n],k[n],dp[x+1]={0};
   for(int i=0;i<n;i++)
      cin>>h[i];
   for(int i=0;i<n;i++)
      cin>>s[i];
   for(int i=0;i<n;i++)
      cin>>k[i];
   for(int i=0;i<n;i++){
      int copies=k[i];
      for(int bitVal=1;copies>0;bitVal<<=1){
         ll usableCopies=min(bitVal,copies);
         ll cost=usableCopies*h[i];
         ll pages=usableCopies*s[i];
         copies-=usableCopies;
         for(int j=x;j>=cost;j--){
            dp[j]=max(dp[j],dp[j-cost]+pages);
         }
      }
   }
   cout<<dp[x]<<'\n';
  }
  return 0;
}
//https://cses.fi/problemset/task/1159