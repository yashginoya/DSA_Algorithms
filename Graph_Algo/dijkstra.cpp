
void dijkstra(int source,int n,vector<int> &dist,vector<int> &parent,vector<vector<pair<int,int>>> &adj){
    dist.assign(n,INF);
    parent.assign(n,-1);
    dist[source] = 0;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
    q.push({0,source});
    while(!q.empty()){
        pair<int,int> thisNode = q.top();
        q.pop();
        int node = thisNode.second;
        int node_dist = thisNode.first;
        if(node_dist != dist[node]) continue;
        for(auto edges:adj[node]){
            if(dist[node] + edges.second < dist[edges.first]){
                dist[edges.first] = dist[node] + edges.second;
                parent[edges.first] = node;
                q.push({dist[edges.first] , edges.first});
            }
        }
    }
}
