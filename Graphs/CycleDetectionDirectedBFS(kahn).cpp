// if there is valid topo sort of a graph, it is acyclic
// using bfs , we can get it using kahns

#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n,vector < pair < int, int >> & edges){
    unordered_map<int,vector<int>>adj;
    queue<int>q;
    vector<int>indegree(n);
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first-1;
        int v = edges[i].second -1;
        adj[u].push_back(v);
    }
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]+=1;
        }
    }
    int ct=0;
    for(int i=0;i<n;i++){
        if (indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int t = q.front();
        ct ++;
        q.pop();
        for(auto i :adj[t]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
        

    }
    if(ct!=n){
        return true;
    }
    else{
        return false;
    }
    

}
