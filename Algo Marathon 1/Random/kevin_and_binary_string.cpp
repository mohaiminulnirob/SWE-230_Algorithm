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
   string s;
   cin>>s;
   int n=s.length();
   int left=1,right=1,mx=1;
   for(int i=1;i<n;i++){
      if(s[i]=='0'){
         for(int j=0;j<i;j++){
            for(int k=j,l=i;l<n;l++,k++){
               if(s[k]==s[l] || l==n-1){
                  if(s[k]!=s[l]){
                     left=j+1;
                     int x=n-i;
                     right=left+x-1;
                     mx=n-i;
                  }  
                  else if(k-j>=mx){
                     mx=k-j;
                     left=j+1;
                     int x=n-i;
                     right=left+x-1;
                  }
                  break;
               }
            }
         }
         break;
      }
   }
   cout<<1<<" "<<n<<" "<<left<<" "<<right<<'\n';
  }
  return 0;
}
//https://codeforces.com/contest/2048/problem/C