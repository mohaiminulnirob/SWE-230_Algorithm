#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int mod=1e9+7;
const int N=2e5+9;

int32_t main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

  int t=1;
  cin>>t;
  while(t--)
  {
   int n,k;
   cin>>n>>k;
   int a[n+1]={0};
   for(int i=k,j=1;i<=n;i+=k,j++){
      a[i]=j;
   }
   int j=n/k+1;
   for(int i=1;i<=n;i++){
      if(!a[i]){
         a[i]=j;
         j++;
      }
   }
   for(int i=1;i<=n;i++){
      cout<<a[i]<<" ";
   }
   cout<<'\n';
  }
  return 0;
}
//https://codeforces.com/contest/2048/problem/B