#include <bits/stdc++.h>
using namespace std;
bool is_safe(vector<vector<int>>graph,vector<int>color,int v,int c){
	for(auto u:graph[v]){
		if(color[u]==c)
			return false;
	}
	return true;
}
bool graphColoringUtil(vector<vector<int>>graph,vector<int>color,int m,int v){
	if(v==graph.size())
		return true;
	for(int c=1;c<=m;c++){
		if(is_safe(graph,color,v,c)){
			color[v]=c;
			if(graphColoringUtil(graph,color,m,v+1))
				return true;
			color[v]=0;
		}
	}
	return false;
}
bool graphColoring(vector<vector<int>>graph,int m){
	vector<int>color(graph.size(),0);
	return graphColoringUtil(graph,color,m,0);
}
int main(){
	int t=1;
	//cin>>t;
	while(t--){
		int v,e;
		cin>>v>>e;
		vector<vector<int>>graph(v);
		for(int i=0;i<e;i++){
			int x,y;
			cin>>x>>y;
			graph[x].push_back(y);
		    graph[y].push_back(x);
		}
		int mxdg=0;
	    for(auto u:graph){
	    	mxdg=max(mxdg,(int)u.size());
	    }
	    int l=1,r=mxdg,mid;
	    int ans=1e9;
	    while(l<=r){
	    	int mid=l+(r-l)/2;
	    	if(graphColoring(graph,mid)){
	    		ans=min(ans,mid);
	    		r=mid-1;
	    	}
	    	else l=mid+1;
	    }
	    if(ans<=4)
	    	cout<<ans<<'\n';
	    else cout<<"many"<<'\n';
		
	}
}