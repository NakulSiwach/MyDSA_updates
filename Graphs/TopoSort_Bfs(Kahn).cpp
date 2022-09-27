// using indegree, when iterating in adj, add those nodes to q whose indegree == 0.(after every visit , indeg--)

#include<bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    unordered_map<int,vector<int>>adj;
    vector<int>ans;
    queue<int>q;
    vector<int>indegree(v);
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]+=1;
        }
    }
    for(int i=0;i<v;i++){
        if (indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int t = q.front();
        ans.push_back(t);
        q.pop();
        for(auto i :adj[t]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
        

    }
    return ans;

}
