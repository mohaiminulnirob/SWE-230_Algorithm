#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int mod=1e9+7;
const int N=2e5+9;
int arr[N],dp[N];
int tree[4*N];

void init(int node,int b,int e){
    if(b==e){
        tree[node]=0;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=max(tree[Left],tree[Right]);
}

int query(int node,int b,int e,int i,int j){
    if(i>e||j<b)
        return 0;
    if(b>=i&&e<=j)
        return tree[node];
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    return max(query(Left,b,mid,i,j),query(Right,mid+1,e,i,j));
}

void update(int node,int b,int e,int i,int value){
    if(i>e||i<b)return;
    if(b>=i&&e<=i){
        tree[node]=max(tree[node],value);
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,value);
    update(Right,mid+1,e,i,value);
    tree[node]=max(tree[Left],tree[Right]);
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>sortedArr;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            sortedArr.pb(arr[i]);
        }

        sort(sortedArr.begin(),sortedArr.end());
        sortedArr.erase(unique(sortedArr.begin(),sortedArr.end()),sortedArr.end());
        for(int i=1;i<=n;i++)
            arr[i]=lower_bound(sortedArr.begin(),sortedArr.end(),arr[i])-sortedArr.begin()+1;

        init(1,1,n);
        int ans=0;
        for(int i=1;i<=n;i++){
            dp[i]=1;
            if(arr[i]>1)
                dp[i]=max(dp[i],query(1,1,n,1,arr[i]-1)+1);
            update(1,1,n,arr[i],dp[i]);
            ans=max(ans,dp[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//https://cses.fi/problemset/task/1145