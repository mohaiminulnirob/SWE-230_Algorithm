#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e18
#define PI 3.14159265358979323846264338327
#define pb push_back
const int mod=1e9+7;
const int N=2e5+9;
int32_t main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif 
  int t=1;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    string s;
    cin>>s;
    map<int,int>l;
    map<int,int>r;
    for(int i=0;i<n;i++){
        if(i==0){
            l[i]=0;
            r[n-i-1]=0;
        }
        else {
            l[i]=l[i-1];
            r[n-i-1]=r[n-i];
        }
        if(s[i]=='L')
            l[i]++;
        if(s[n-i-1]=='R')
            r[n-i-1]++;

    }
    ll ans=0;
    for(int i=0;i<n;i++){
        //cout<<l[i]<<" "<<r[i]<<'\n';
        ans+=min(l[i],r[i])*1ll*a[i];
    }

    cout<<ans<<'\n';
  } 
  return 0;
}
//https://codeforces.com/contest/2000/problem/D