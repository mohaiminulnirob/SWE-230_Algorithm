#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=1e6+5;
vector<bool>isPrime(N,true);
vector<int>primeCount(N,0);

void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=N;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=N;j+=i){
                isPrime[j]=false;
            }
        }
    }
    int primeCounter=0;
    for(int i=2;i<=N;i++){
        if(isPrime[i]){
            primeCounter++;
        }
        primeCount[i]=primeCounter; 
    }
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    sieve();
    int tc=1;
    cin>>tc;
    for(int cs=1;cs<=tc;cs++)
    {
        ll n,k;
        cin>>n>>k;   
        vector<ll>nums(k);
        ll large=0;
        for(int i=0;i<k;i++){
            cin>>nums[i];
            if(nums[i]>n)
                large++;
        }
        if(n<=3){
            cout<<"Case "<<cs<<": "<<"0"<<'\n';
            continue;
        }
        int sz=(1<<k); 
        ll multipleCount=0;

        for(int mask=1;mask<sz;mask++){
            ll multiple=1;
            int bitCount=0;
            bool valid=true;
            for(int i=0;i<k;i++){
                if(mask & (1<<i)){
                    bitCount++;
                    multiple*=nums[i];
                    if(multiple>n){ 
                        valid=false; 
                        break; 
                    }
                }
            }
            if(!valid) 
                continue;
            ll divisibleCount=n/multiple;
            if(bitCount&1) 
                multipleCount+=divisibleCount; 
            else multipleCount-=divisibleCount;  
        }

        ll res=n-multipleCount;
        res-=primeCount[n]-k; 
        res-=1; 
        res-=large; 
        cout<<"Case "<<cs<<": "<<res<<'\n';
    }
    return 0;
}
