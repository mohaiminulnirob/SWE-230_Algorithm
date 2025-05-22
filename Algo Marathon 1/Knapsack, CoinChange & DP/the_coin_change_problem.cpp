#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int mod=1e9+7;
const int N=255;
ll dp[N][55];
int n;
ll check(int x, int a[], int j){
  if(x==0) return 1;
  if(j>=n || x<0) return 0;
  if(dp[x][j]!=-1)
    return dp[x][j];
  ll ways=0;
  for(int i=j;i<n;i++){
    if(a[i]<=x)
      ways+=check(x-a[i],a,i);
  }
  return dp[x][j]=ways;
}
int32_t main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  //   #endif 
 
  int t=1;
 // cin>>t;
  while(t--)
  {
   memset(dp, -1,sizeof dp);
   int x;
   cin>>x>>n;
   int a[n];
   for(int i=0;i<n;i++)
    cin>>a[i];
   sort(a,a+n);
   ll ans=check(x,a,0);
   cout<<ans<<'\n';
  }
  return 0;
}
//https://www.hackerrank.com/challenges/coin-change/problem