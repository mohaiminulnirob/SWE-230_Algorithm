#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int mod=1e9+7;
const int N=1e6+9;
int32_t main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int t=1;
 // cin>>t;
  while(t--)
  {
   ll n,x;
   cin>>n>>x;
   ll a[n],dp[x+1]={0};
   for(int i=0;i<n;i++)
    cin>>a[i];
   sort(a,a+n);
   dp[0]=1;
   for(int i=0;i<n;i++){
    for(int sum=a[i];sum<=x;sum++){
      dp[sum]=(dp[sum]+dp[sum-a[i]])%mod;
    }
   }
   cout<<dp[x]<<'\n';
  }
  return 0;
}
