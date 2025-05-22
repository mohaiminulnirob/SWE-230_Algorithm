#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=1e6+5;
const int MOD=1e9+7;
int fact[N];

void preprocessFact(){
    fact[0]=1;
    for(int i=1;i<N;i++) {
        fact[i]=(fact[i-1]*i)%MOD;
    }
}

bool isValid(int nmbr,int fav1,int fav2){
    while(nmbr>0) {
        int lastDigit=nmbr%10;
        nmbr/=10;
        if(lastDigit==fav1 || lastDigit==fav2) 
            continue;
        return false;
    }
    return true;
}

int modPower(int base,int exp) {
    int res=1;
    while(exp>0) {
        if(exp&1) res=(1LL*res*base)%MOD; 
        base=(1LL*base*base)%MOD; 
        exp>>=1;  
    }
    return res;
}


int modularInverse(int value,int mod){
    return modPower(value,mod-2);
}

int combination(int n,int r){
    int num=fact[n];
    int denom=(fact[r]*fact[n-r])%MOD;
    int res=(num*modularInverse(denom,MOD))%MOD;
    return res;
}

int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  preprocessFact();
  int t=1;
  //cin>>t;
  while(t--)
  {
    int fav1,fav2,length;
    cin>>fav1>>fav2>>length;
    
    int res=0;
    for(int i=0; i<=length;i++){
        int sumDigits=fav1*i+fav2*(length-i);
        if(isValid(sumDigits,fav1,fav2)) {
            res=(res+combination(length,i))%MOD;
        } 
    }
    cout<<res<<'\n';
   
  }
  return 0;
}