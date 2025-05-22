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
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        bool f=false;
        ll d=sqrt(x);
        for(ll j=2;j*j<=d;j++){
           if(d%j==0){
             f=true;
             break;
            }
        }
        if(!f && d*d==x && x!=1)
            cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
        
    }
   
  }
  return 0;
}