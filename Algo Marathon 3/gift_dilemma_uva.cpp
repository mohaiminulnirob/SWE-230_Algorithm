#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


ll extended_gcd(ll m,ll n,ll &p,ll &q)
{
    if(!n)
    {
        p=1;
        q=0;
        return m;
    }
    int g=extended_gcd(n,m%n,p,q);
    int t=p;
    p=q;
    q=t-(m/n)*q;
    return g;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ll a,b,c,p,x,y,ans=0;
        cin>>a>>b>>c>>p;
        ll g=extended_gcd(a,b,x,y);
        ll da=b/g,db=a/g;
        
        for(ll k=0;;k++)
        {
            ll k0=p-k*c;
            if(k0<0) break;
            if(k0%g!=0) continue;
            
            ll X=x*k0/g,Y=y*k0/g;
        
            X=(X%da + da)%da;
            Y=(k0 - X*a)/b;
            
            if(Y>=0) ans++;
            ans+=Y/db;
        }
        cout<<"Case "<<i<<": "<<ans<<"\n";
    }
    return 0;
}
