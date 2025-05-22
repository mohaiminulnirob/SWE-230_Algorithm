#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=3e5+9;
vector<pair<int,int>>a[N];
int ans;
int dis[N],vis[N];
void bfs(int start){
	queue<int>q;
	q.push(start);
    vis[start]=1;
    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        if(a[current].empty())
        	ans=min(ans,dis[current]);
        for(auto child:a[current])
        {
            if(vis[child.first]!=1)
            {
            q.push(child.first);
            dis[child.first]=dis[current]+child.second;
            vis[child.first]=1;
            }
        }
        
    }
}
int32_t main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t=1;
  cin>>t;
  while(t--)
  {
   int n;
   cin>>n;
   string s;
   cin>>s;
   for(int i=1;i<=n;i++){
   	vis[i]=0;
   	a[i].clear();
   	int l,r;
   	cin>>l>>r;
   	if(l!=0){
   		if(s[i-1]=='L')
   			a[i].pb({l,0});
        else a[i].pb({l,1});
   	}
   	if(r!=0){
   		if(s[i-1]=='R')
   			a[i].pb({r,0});
   		else a[i].pb({r,1});
   	}
   }
   ans=1e9;
   dis[1]=0;
   bfs(1);
   cout<<ans<<'\n';
  }
  return 0;
}
//https://codeforces.com/contest/1900/problem/C