#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,vector<pair<int,int>>>adj;
    for(int i =0;i<vec.size();i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    set<pair<int,int>>sett;
    vector<int>distance(vertices,INT_MAX);
    
    sett.insert({0,0});
    distance[0]=0;

    while (sett.size()>0){
        auto top = *sett.begin();
        int dis = top.first;
        int node = top.second;
        sett.erase(sett.begin());
        for(auto i:adj[node]){
            if(distance[i.first] > distance[node]+i.second){
                distance[i.first] = distance[node]+i.second;
                sett.insert({distance[i.first],i.first});
            }
        }

    }
    return distance;


}
