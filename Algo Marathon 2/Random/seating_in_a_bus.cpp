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
    map<int,bool>m;
    int ans=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i!=0){
            if(m[a[i]+1]==false && m[a[i]-1]==false)
                ans=0;
        }
        m[a[i]]=true;

    }
    if(ans)
        cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
  } 
  return 0;
}
//https://codeforces.com/problemset/problem/2000/B