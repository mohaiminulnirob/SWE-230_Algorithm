#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t=1;
  //cin>>t;
  while(1)
  {
    int n;
    cin>>n;
    if(n==0)
    	break;
    vector<int>inp(n+1),lis(n+1,1),lds(n+1,1);
    for(int i=1;i<=n;i++) 
    	cin>>inp[i];

    for(int i=n;i>=1;i--){
      for(int j=n;j>i;j--){
        if(inp[i]<=inp[j]) 
        	lis[i]=max(lis[i],lis[j]+1);
        if(inp[i]>=inp[j])
        	lds[i]=max(lds[i],lds[j]+1);
      }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
      ans=max({ans, lis[i], lds[i]});
      for(int j=i+1;j<=n;j++){
        if(inp[i]>inp[j])
        	ans=max(ans,lis[i]+lds[j]);
        if(inp[i]<inp[j])
        	ans=max(ans,lis[j]+lds[i]);
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=242&page=show_problem&problem=3153