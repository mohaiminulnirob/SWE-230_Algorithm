#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int extended_gcd(int m,int n,int &p,int &q)
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
    int t=1;
    //cin>>t;
    int m,n,g,x,y;
    while(cin>>m>>n)
    {
        g=extended_gcd(m,n,x,y);
        cout<<x<<" "<<y<<" "<<g<<'\n';
    }
    return 0;
}
