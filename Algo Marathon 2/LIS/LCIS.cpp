#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void printLCS(int idx,vector<int>&seq2,vector<int>&prev){
    if(idx==0) return;
    printLCS(prev[idx],seq2,prev);
    cout<<seq2[idx]<<" ";
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1; 
    //cin>>t;
    while(t--){
        int n,m; cin>>n;
        vector<int>seq1(n+1);
        for(int i=1;i<=n;i++)  
            cin>>seq1[i];
        cin>>m;
        vector<int>seq2(m+1);
        for(int i=1;i<=m;i++) 
            cin>>seq2[i];
        vector<int>dp(m+1,0),prev(m+1,0);
        for(int i=1;i<=n;i++){
            int lastIndex=0;
            for(int j=1;j<=m;j++){
                if(seq1[i]==seq2[j]){
                    dp[j]=dp[lastIndex]+1;
                    prev[j]=lastIndex;
                }
                else if(seq1[i]>seq2[j] && dp[lastIndex]<dp[j]){
                    lastIndex=j;
                }
            }
        }
        int x=0;
        for(int i=1;i<=m;i++){
            if(dp[x]<dp[i]) 
                x=i;
        }
        cout<<dp[x]<<'\n';
        printLCS(x,seq2,prev);
        cout<<'\n';
    }
    return 0;
}
//https://codeforces.com/problemset/problem/10/D