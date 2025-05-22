#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void sieve(vector<ll>&primes,int limit){
    vector<bool>is_prime(limit+1,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<=limit;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=limit;j+=i)
                is_prime[j]=false;
        }
    }
    for(int i=2;i<=limit;i++){
        if(is_prime[i]) 
            primes.pb(i);
    }
}

void segmented_sieve(ll m,ll n){
    int limit=sqrt(n);
    vector<ll>primes;
    sieve(primes,limit);

    vector<bool>is_prime(n-m+1,true);
    if(m==1) 
        is_prime[0] = false; 

    for(auto p:primes){
        ll i=max(p*p,(m+p-1)/p*p);
        for(ll j=i; j<=n;j+=p) {
            is_prime[j-m]=false;
        }
    }

    for(ll i=0;i<=n-m;i++){
        if(is_prime[i]) 
            cout<<m+i<<'\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        ll m,n;
        cin>>m>>n;
        segmented_sieve(m,n);
        cout<<'\n';
    }
    return 0;
}
