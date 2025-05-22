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
    string s;
    cin>>s;
    int x=stoi(s);
    if(x>101 && s[0]=='1' && s[1]=='0' && s[2]!='0')
        cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
  } 
  return 0;
}
//https://codeforces.com/contest/2000/problem/A