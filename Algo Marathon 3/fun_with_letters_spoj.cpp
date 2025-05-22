#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=16;
vector<int>factorial(N);
void preprocessFact(){
    factorial[0]=1;
    for(int i=1;i<N;i++) {
        factorial[i]=(factorial[i-1]*i);
    }
}
int findPermutationRank(string str){
    int rank=1;
    int n=str.length();
    int fact=factorial[n];
    vector<char>s(str.begin(),str.end());
    sort(s.begin(), s.end());
    for (int i=0;i<n;i++) {
        fact/=(n-i);
        int indx=find(s.begin(),s.end(),str[i])-s.begin();
        rank+=indx*fact;
        s.erase(s.begin()+indx);
    }
    return rank;
}
string getPermutation(string str, int n){
    int sz=str.length();
    sort(str.begin(),str.end());
    int f=factorial[sz-1];
    string s=str;
    string ans="";
    while(true){
        ans+=s[n/f];
        s.erase(n/f,1);
        if(s.length()==0)
            break;
        n=n%f;
        f=f/s.length();
    }
    return ans;
}
int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t=1;
  cin>>t;
  preprocessFact();
  while(t--)
  {
      string s;
      int n;
      cin>>s>>n;
      int n1=findPermutationRank(s);
      string ans=getPermutation(s,n+n1-1);
      cout<<ans<<'\n';
  }

  return 0;
}