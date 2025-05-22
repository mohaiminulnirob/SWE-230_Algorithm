#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=2e5+9;
ll dp[N],d[N],t[N];
pair<ll,ll>val[N];

int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  
  int T=1;
  //cin>>t;
  while(T--){
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>d[i]>>t[i];  
    cin>>x;    
    for(int i=1;i<=n;i++){
      val[i].first=d[i]+x*t[i];
      val[i].second=x*t[i]-d[i];
    }
    sort(val+1,val+1+n);

    dp[0]=-1e18;
    int c=0;
    for(int i=1;i<=n;i++){
      if(val[i].first>=0 && val[i].second>=0)
        if(val[i].second>=dp[c]) 
          dp[++c]=val[i].second;
        else 
          dp[upper_bound(dp+1,dp+c+1,val[i].second)-dp]=val[i].second;
    }
    cout<<c<<" ";
    
    memset(dp,0,sizeof(dp));
    c=0;
    for(int i=1;i<=n;i++)
      if(val[i].second>=dp[c]) 
        dp[++c]=val[i].second;
      else 
        dp[upper_bound(dp+1,dp+c+1,val[i].second)-dp]=val[i].second;
    cout<<c<<'\n';
  }
  return 0;
}
//https://codeforces.com/problemset/problem/76/F