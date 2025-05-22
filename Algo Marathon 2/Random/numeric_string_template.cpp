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
    int m;
    cin>>m;
    while(m--){
        string s;
        cin>>s;
        map<int,char>m1;
        map<char,int>m2;
        if(s.size()!=n){
            cout<<"NO"<<'\n';
            continue;
        }
        int ans=1;
        for(int i=0;i<n;i++){
            //cout<<s[i]<<'\n';
            if(m1[a[i]]){
                //cout<<m2[a[i]]<<'\n';
                if(m1[a[i]]!=s[i]){
                    ans=0;
                    break;
                }
            }
            else m1[a[i]]=s[i];
            if(m2.find(s[i])!=m2.end()){
                //cout<<m2[s[i]]<<'\n';
                if(m2[s[i]]!=a[i]){
                    ans=0;
                    break;
                }
            }
            else{
                //cout<<"!"<<'\n';
                m2[s[i]]=a[i];
                //cout<<m2[s[i]]<<'\n';
            }
        }
        //cout<<ans<<'\n';
        if(ans)
            cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
  } 
  return 0;
}
//https://codeforces.com/contest/2000/problem/C