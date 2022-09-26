#include<bits/stdc++.h>


bool bfs(int i,unordered_map<int,int>parent,unordered_map<int,bool>&vis,unordered_map<int,vector<int>>adj){
    parent[i] = -1;
    vis[i] =1;
    queue<int>q;
    q.push(i);
    while (!q.empty()){
        int t = q.front();
        q.pop();
        for(auto j: adj[t]){
            if (vis[j] and parent[t]!=j){
                return true;
            }
            else if(!vis[j]){
                q.push(j);
                parent[j] = t;
                vis[j] = 1;
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
            bool a = bfs(i,parent,vis,adj); 
            if (a){
                return "Yes";
            }
        }
    }
    return "No";
}
