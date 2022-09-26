// using DFS

#include<bits/stdc++.h>


bool dfs(int i,unordered_map<int,int>&parent,unordered_map<int,bool>&vis,
    unordered_map<int,vector<int>>adj){
    
    vis[i] = 1;
    for(auto x:adj[i]){
        if (vis[x] && parent[i]!=x){
            return true;
        }
        else if (!vis[x]){
            parent[x] = i;
            bool ans = dfs(x,parent,vis,adj);
            if (ans){
                return true;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,vector<int>>adj;
    for(int i = 0 ; i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool>vis;
    unordered_map<int,int>parent;
    for(int i =0 ;i<n;i++){
        if(!vis[i]){
            bool a = dfs(i,parent,vis,adj); 
            if (a){
                return "Yes";
            }
        }
    }
    return "No";
}
