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
   int n;
   cin>>n;
   vector<pair<int,int>>a(n);
   for(int i=0;i<n;i++){
    cin>>a[i].first>>a[i].second;
   }
   sort(a.begin(),a.end());
   ll ans=0,sum=0;
   for(int i=0;i<n;i++){
    sum+=a[i].first;
    ans+=a[i].second-sum;
   }
   cout<<ans<<'\n';
  }
  return 0;
}

//https://cses.fi/problemset/task/1630