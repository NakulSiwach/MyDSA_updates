
#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, 
    vector<pair<pair<int, int>, int>> &g){

    unordered_map<int,vector<pair<int,int>>>adj;
    for(int i=0;i<g.size();i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int>key(n+1);
    vector<bool>mst(n+1);
    vector<int>parent(n+1);

    for(int i=0;i<=n;i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // prim

    key[1] = 0;
    parent[1] =-1;
    for(int x =1;x<n;x++){
        int mini = INT_MAX;
        int u;
        for(int j=1;j<=n;j++){
            if (mst[j]==false and key[j]<mini){
                mini = key[j];
                u = j;
            }
        }
        mst[u] = true;
        for(auto i:adj[u]){
            int v = i.first;
            int w = i.second;
            if (mst[v] == false && w<key[v]){
                parent[v] =u;
                key[v]=w;
            }
        }
    }

    vector<pair<pair<int,int>,int>>res;

    for(int i =2;i<=n;i++){
        res.push_back({{parent[i],i},key[i]});
    }
    return res;

    

}
