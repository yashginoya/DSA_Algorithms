// single source shortest path algo
// TC = O(N*M)     or     O(V*E) 
// here for 1 base indexing pass n+1 instead of n while calling function 

void bellmanFord(int source,int n,vector<int> &dist,vector<int> &parent,vector<vector<pair<int,int>>> &adj,set<int> &negCycle){
    // fill(all(dist),INF);
    dist.assign(n,INF);
    parent.assign(n,-1);
    dist[source] = 0;

    vector<pair<int,pair<int,int>>> edges;
    for(int i = 0 ; i<n;i++){
        for(auto j : adj[i]){
            edges.push_back({j.second,{i,j.first}});
        }
    }

    for(int i = 0; i < n-1 ; i++){
        for(auto j : edges){
            if(dist[j.second.second] > dist[j.second.first] + j.first){
                dist[j.second.second] = dist[j.second.first] + j.first;
                parent[j.second.second] = j.second.first;
            }
        }
    }


    // Checking for negative cycle
    for(int i = 0;i<n;i++){
        for(auto j:edges){
            if(dist[j.second.second] > dist[j.second.first] + j.first){
                dist[j.second.second] = dist[j.second.first] + j.first;
                negCycle.insert(j.second.second);
            }
        }
    }
}
