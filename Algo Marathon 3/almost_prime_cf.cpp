#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int ans,N;

void sieve(){
  vector<int>pd_count(N+1,0);
  for(int i=2;i<=N;i++){
    if(pd_count[i]==0){
      for(int j=i;j<=N;j+=i) {
        pd_count[j]++;;
      }
    }
  }
  for(int i=2;i<=N;i++){
    if(pd_count[i]==2){
      ans++;
    }
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  
  int t=1;
  //cin>>t;
  while(t--)
  {
    cin>>N;
    sieve();
    cout<<ans<<'\n';
   
  }
  return 0;
}