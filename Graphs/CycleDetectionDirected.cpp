// we maintain a dfvis to check instead of parent that we use in a undirected one
#include<bits/stdc++.h>


bool dfs(int i,unordered_map<int,bool>&vis,
    unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&dfsvis){
    
    vis[i] = 1;
    dfsvis[i] = 1;
    for(auto x:adj[i]){
        if (!vis[x]){
            bool ans = dfs(x,vis,adj,dfsvis);
            if (ans){
                return true;
            }
        }
        else if (dfsvis[x]){
            return true;
        }
    }
    dfsvis[i] = 0;
    return false;
}

int detectCycleInDirectedGraph (int n, vector < pair < int, int >> & edges)
{
    unordered_map<int,vector<int>>adj;
    for(int i = 0 ; i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second; 
        // here we add only in one direction
        adj[u].push_back(v);
    }
    unordered_map<int,bool>vis;
    unordered_map<int,bool>dfsvis;
    for(int i =1 ;i<=n;i++){
        if(!vis[i]){
            bool a = dfs(i,vis,adj,dfsvis); 
            if (a){
                return 1;
            }
        }
    }
    return 0;
}
