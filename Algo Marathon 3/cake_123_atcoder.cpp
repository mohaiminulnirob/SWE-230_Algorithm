#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t=1;
  //cin>>t;
  while(t--)
  {
    int x,y,z,K;
    cin>>x>>y>>z>>K;
    vector<ll>a(x),b(y),c(z);
    for(int i=0;i<x;i++)
      cin>>a[i];
    for(int i=0;i<y;i++)
      cin>>b[i];
    for(int i=0;i<z;i++)
      cin>>c[i];
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(c.rbegin(),c.rend());

    priority_queue<tuple<ll,int,int,int>>pq;
    set<tuple<int,int,int>>visited;
    pq.push({a[0]+b[0]+c[0],0,0,0});
    visited.insert({0,0,0});

    for(int count=0;count<K;count++){
      auto top=pq.top();
      pq.pop();
      ll sum = get<0>(top);
      int i=get<1>(top);
      int j=get<2>(top);
      int k=get<3>(top);
      cout<<sum<<'\n';

      if(i+1<x && !visited.count({i+1,j,k})){
            pq.push({a[i+1]+b[j]+c[k],i+1,j,k});
            visited.insert({i+1,j,k});
        }
        if(j+1<y && !visited.count({i,j+1,k})){
            pq.push({a[i]+b[j+1]+c[k],i,j+1,k});
            visited.insert({i,j+1,k});
        }
        if(k+1<z && !visited.count({i,j,k+1})){
            pq.push({a[i]+b[j]+c[k+1],i,j,k+1});
            visited.insert({i,j,k+1});
        }
    }
    
  }
  return 0;
}