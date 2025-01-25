#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=1e6+9;

int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t=1;
  cin>>t;
  while(t--)
  {
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>mathies,engineers;
    ll maxm=0,maxe=0,x,y;
    for(ll i=0;i<n;i++)
    {
      cin>>x>>y;
      mathies.pb({x,y});
      maxm+=x;
    }
    for(ll i=0;i<m;i++)
    {
      cin>>x>>y;
      maxe+=x;
      engineers.pb({-x,y});
    }
    sort(mathies.begin(),mathies.end());
    sort(engineers.begin(),engineers.end());
    ll dp[N];
    memset(dp,0x80,sizeof(dp));
    dp[0]=0;
    maxm=0;
    for(ll i=0;i<n;i++)
    {
      maxm+=mathies[i].first;
      for(ll j=maxm;j>=mathies[i].first;j--)
      {
        dp[j]=max(dp[j],dp[j-mathies[i].first]+mathies[i].second);
      }
    }
    for(ll i=0;i<m;i++)
    {
      for(ll j=0;j<=engineers[i].first+maxe;j++)
      {
        dp[j]=max(dp[j],dp[j-engineers[i].first]+engineers[i].second);
      }
      maxe+=engineers[i].first;
    }
    cout<<dp[0];
    if(t!=0)cout<<'\n';
  }
  return 0;
}
//https://dmoj.ca/problem/knapsack4