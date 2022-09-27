// use a stack and store the i when rec call ends, and return reversed stack values.

#include<bits/stdc++.h>
using namespace std;

void helper(int i , unordered_map<int,vector<int>>&adj,
    stack<int>&ans,vector<bool>&vis){
    vis[i] = true;
    for(auto t: adj[i]){
        if(!vis[t]){
            helper(t,adj,ans,vis);
        }
    }
    ans.push(i);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    vector<bool>vis(v);
    stack<int>ans;
    vector<int>total;
    for(int i =0; i <v;i++){
        if(!vis[i]){
            helper(i,adj,ans,vis);
        }   
    }
    while (!ans.empty()){
        total.push_back(ans.top());
        ans.pop();
    }
    return total;
}
