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
    ll n;
    cin>>n;
    n++;
    ll sum=0;
    for(int i=0;i<52;i++){
      ll blocks=n/(1LL<<(i+1));
      ll ones=blocks*(1LL<<i);
      ll r=n%(1LL<<(i+1));
      r=max(0LL,r-(1LL<<i));
      sum+=ones+r;
    }
    cout<<sum<<'\n';
  }
  return 0;
}
