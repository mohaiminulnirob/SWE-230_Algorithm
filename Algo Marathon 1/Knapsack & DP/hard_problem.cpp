#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define INF 1e18

int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t=1;
  //cin>>t;
  while(t--)
  {
  	ll n;
  	cin>>n;
  	ll c[n+1];
  	string s[n+1],rs[n+1];
  	for(int i=1;i<=n;i++)
  		cin>>c[i];
  	for(int i=1;i<=n;i++){
  		cin>>s[i];
  		rs[i]=s[i];
  		reverse(rs[i].begin(),rs[i].end());
  	}

  	ll dp[n+1][2];
  	dp[1][0]=0;
  	dp[1][1]=c[1];
  	for(int i=2;i<=n;i++){
  		dp[i][0]=dp[i][1]=INF;
  		if(s[i]>=s[i-1])
  			dp[i][0]=min(dp[i][0],dp[i-1][0]);
  		if(s[i]>=rs[i-1])
  			dp[i][0]=min(dp[i][0],dp[i-1][1]);
  		if(rs[i]>=s[i-1])
  			dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
  		if(rs[i]>=rs[i-1])
  			dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
  	}

  	ll ans=min(dp[n][0],dp[n][1]);
  	if(ans==INF)
  		cout<<"-1"<<'\n';
  	else cout<<ans<<'\n';
  }
  return 0;
}