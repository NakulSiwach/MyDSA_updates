// using bfs, maintain a parent array of all , then backtrack from dest node to source in parent arr.

#include<bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    unordered_map<int,vector<int>>adj;
    for(int i = 0 ; i <m;i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int>q;
    unordered_map<int,bool>vis;
    unordered_map<int,int>parent;

    q.push(s);
    vis[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(auto i: adj[t]){
            if(!vis[i]){
                q.push(i);
                parent[i] = t;
                vis[i] = true;
            }
        }
    }

    vector<int>ans;
    int d = t;
    while(d!=-1 ){
        ans.push_back(d);
        d = parent[d];
    }
    reverse(ans.begin(),ans.end());
    return ans;



}
