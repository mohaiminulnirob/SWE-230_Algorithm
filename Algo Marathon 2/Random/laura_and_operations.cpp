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
   int a,b,c;
   cin>>a>>b>>c;
   if(b%2==c%2)
   cout<<"1 ";
   else cout<<"0 ";
   if(a%2==c%2)
   cout<<"1 ";
   else cout<<"0 ";
   if(a%2==b%2)
   cout<<"1"<<endl;
   else cout<<"0"<<'\n';
  }
  return 0;
}
//https://codeforces.com/problemset/problem/1900/B