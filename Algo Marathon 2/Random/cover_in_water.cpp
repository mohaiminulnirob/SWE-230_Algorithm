#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t=1;
  cin>>t;
  while(t--)
  {
   int n;
   cin>>n;
   string s;
   cin>>s;
   int c=0,ans=0;
   bool f=false;
   for(int i=0;i<n;i++){
   	if(i>0 && i<n-1 && s[i]=='.' && s[i-1]=='.' && s[i+1]=='.'){
   		f=true;
   	}
   	if(s[i]=='.') 
   		c++;
   }
   if(f)
   	ans=2;
   else ans=c;
   cout<<ans<<'\n';
  }
  return 0;
}
//https://codeforces.com/contest/1900/problem/A