#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=1e6+9;
vector<int>primes;
bool is_prime[N]; 

void sieve() {
  for(int i=2;i<N;i++){
    is_prime[i]=true;
  }
  for(int i=2;i*i<N;i++){
    if(is_prime[i]){
      for(int j=i*i;j<N;j+=i) {
        is_prime[j]=false;
      }
    }
  }
  for(int i=2;i<N;i++){
    if(is_prime[i]){
      primes.pb(i);
    }
  }
}

int countMaxExponent(int num){
    int maxExponent = 0;
    for (int i=0;i<primes.size() && primes[i]*primes[i]<=num;i++){
        if(num%primes[i]==0){
            int exponentCount=0;
            while(num%primes[i]==0){
                num/=primes[i];
                exponentCount++;
            }
            maxExponent=max(maxExponent,exponentCount);
        }
    }
    if(num>1) 
      maxExponent=max(1,maxExponent);
    return maxExponent;
}

int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  sieve();
  int t=1;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    cout<<countMaxExponent(n)<<'\n';
  }
  return 0;
}