//DFS
void dfs(int i,unordered_map<int,vector<int>>adj,unordered_map<int,bool>&vis){
	vis[i] = 1;
	cout<<i;
	for(auto x:adj[i]){
		if (!vis[x]){
			dfs(x,adj,vis);
		}
	}
	return;
}


// BFS
#include<bits/stdc++.h>
using namespace std;

void helper(unordered_map<int,vector<int>>adj,unordered_map<int,bool>&vis,int i){
	vis[i] = true;
	queue<int>q;
	q.push(i);
	while(!q.empty()){
		int t = q.front();
		cout<<t;
		q.pop();
		for(auto i:adj[t]){
			if (vis[i]!=true){
				q.push(i);
				
				vis[i] = true;
			}
		}
	}
	return;
}

int main(){
	unordered_map<int,vector<int>>adj;
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[1].push_back(0);
	adj[2].push_back(3);
	adj[2].push_back(4);
	adj[3].push_back(4);
	adj[3].push_back(2);
	adj[4].push_back(2);
	adj[4].push_back(3);
	unordered_map<int,bool>vis;
	helper(adj,vis,0);
	
}
