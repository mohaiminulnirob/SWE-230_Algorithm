#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N=400100;
struct Edge{
	int from,to,weight,index;
	bool operator<(const Edge&x)const{
		return weight<x.weight;
	}
}edges[N];
int isCycleEdge[N],res[N],edgeCount,head[N],adjTo[N],nextEdge[N],parent[N],edgeId[N],sizeComp[N],depthParent[N],depth[N],maxEdge[N],nodes,edgesCount,upperBound[N];

int find(int x){
	return parent[x]==x?x:find(parent[x]);
}
int findRoot(int x){
	return parent[x]==x?x:parent[x]=findRoot(parent[x]);
}
void dfs(int node){
	for(int i=head[node];~i;i=nextEdge[i])
		if(adjTo[i]!=depthParent[node]){
			depthParent[adjTo[i]]=node;maxEdge[adjTo[i]]=edgeId[i];
			depth[adjTo[i]]=depth[node]+1;dfs(adjTo[i]);
		}
}
void addEdge(Edge x){
	nextEdge[edgeCount]=head[x.from];adjTo[edgeCount]=x.to;edgeId[edgeCount]=x.index;head[x.from]=edgeCount++;
	nextEdge[edgeCount]=head[x.to];adjTo[edgeCount]=x.from;edgeId[edgeCount]=x.index;head[x.to]=edgeCount++;
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>nodes>>edgesCount;
	memset(head,-1,sizeof head);
	for(int i=1;i<=edgesCount;i++){
		cin>>edges[i].from>>edges[i].to>>edges[i].weight;
		edges[i].index=i;
	}
	sort(edges+1,edges+edgesCount+1);
	for(int i=1;i<=nodes;i++)
		parent[i]=i,sizeComp[i]=1,upperBound[i]=INT_MAX;
	for(int i=1;i<=edgesCount;i++){
		int x=find(edges[i].from),y=find(edges[i].to);
		if(x!=y){
			if(sizeComp[x]>sizeComp[y])
				swap(x,y);
			parent[x]=y;sizeComp[y]+=sizeComp[x];
			upperBound[x]=edges[i].weight;
			addEdge(edges[i]);
		}else{
			int u=edges[i].from,v=edges[i].to;
			for(;u!=v;u=parent[u]){
				if(upperBound[u]>upperBound[v])swap(u,v);
				res[edges[i].index]=max(res[edges[i].index],upperBound[u]);
			}
			isCycleEdge[i]=1;
		}
	}
	dfs(1);
	for(int i=1;i<=nodes;i++)
		parent[i]=i;
	for(int i=1;i<=edgesCount;i++)
		if(isCycleEdge[i]){
			int x=edges[i].from,y=edges[i].to;
			for(;findRoot(x)!=findRoot(y);){
				if(depth[findRoot(x)]<depth[findRoot(y)])swap(x,y);
				x=findRoot(x);res[maxEdge[x]]=edges[i].weight;
				parent[x]=depthParent[x];
			}
		}
	for(int i=1;i<=edgesCount;i++)
		cout<<res[i]-1<<(i==edgesCount?'\n':' ');
	return 0;
}
//https://codeforces.com/problemset/problem/827/D
