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
   int a[3];
   for(int i=0;i<3;i++)
   	cin>>a[i];
   sort(a,a+3);
   ll ans=0;
   for(int i=1;i<3;i++)
   	ans+=a[i]-a[i-1];
   cout<<ans<<'\n';
  }
  return 0;
}
//https://atcoder.jp/contests/abc103/tasks/abc103_a