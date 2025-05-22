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
    ll n,m,q;
    cin>>n>>m>>q;
    ll gcd=__gcd(n,m);
    ll sz1=n/gcd;
    ll sz2=m/gcd;
    while(q--){
        ll sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey; 
        ll r1,r2;
        sy--;
        ey--;
        if(sx==1) 
            r1=sy/sz1;
        else r1=sy/sz2;
        
        if(ex==1) 
            r2=ey/sz1;
        else r2=ey/sz2;
        
        if(r1==r2) 
            cout<<"YES"<<'\n';
        else cout<< "NO"<<'\n';
    }
  }
  return 0;
}
