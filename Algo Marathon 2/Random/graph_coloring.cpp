#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int mxN=5005;
vector<int> ad[mxN];
int col[mxN];
bool vis[mxN];
bool bipartite;
int one,zero;
vector<int> comp;

void dfs(int node){
    vis[node]=true;
    if(col[node]) one++;
    else zero++;
    comp.pb(node);
    for(int child:ad[node]){
        if(!vis[child]){
            col[child]=col[node]^1;
            dfs(child);
        }
        else if(col[node]==col[child]){
            bipartite=true;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int n1,n2,n3;
        cin>>n1>>n2>>n3;

        for(int i=1;i<=n;i++){
            ad[i].clear();
            vis[i]=false;
        }
        memset(col,0,sizeof(col));
        bipartite=false;

        while(m--){
            int u,v;
            cin>>u>>v;
            ad[u].pb(v);
            ad[v].pb(u);
        }

        vector<pair<int,int>> coins={{-1,-1}};
        vector<vector<int>> comps={{-1}};
        int cnt=0;

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                comp.clear();
                cnt++;
                one=0,zero=0;
                dfs(i);
                coins.pb({one,zero});
                comps.pb(comp);
            }
        }

        if(bipartite){
            cout<<"NO\n";
            continue;
        }

        int dp[n+1][n+1];
        memset(dp,-1,sizeof dp);
        dp[0][0]=0;

        for(int i=1;i<=cnt;i++){
            int a=coins[i].first;
            int b=coins[i].second;
            for(int j=0;j<=n;j++){
                if(j-a>=0&&dp[i-1][j-a]!=-1) dp[i][j]=1;
                else if(j-b>=0&&dp[i-1][j-b]!=-1) dp[i][j]=0;
            }
        }

        if(dp[cnt][n2]==-1){
            cout<<"NO\n";
            continue;
        }

        vector<int> ans(n+1);
        for(int i=cnt;i>=1;i--){
            for(int node:comps[i]){
                if(col[node]==dp[i][n2]) ans[node]=2;
                else if(n1) ans[node]=1,n1--;
                else ans[node]=3,n3--;
            }
            n2-=(dp[i][n2]?coins[i].first:coins[i].second);
        }

        cout<<"YES\n";
        for(int i=1;i<=n;i++) cout<<ans[i];
        cout<<"\n";
    }
    return 0;
}
//https://codeforces.com/contest/1354/problem/E
