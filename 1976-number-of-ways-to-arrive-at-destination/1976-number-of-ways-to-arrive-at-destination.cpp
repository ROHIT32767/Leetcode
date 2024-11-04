class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9+7;
        vector<vector<pair<long long,long long>>> adj(n,vector<pair<long long ,long long>>());
        for(auto road:roads){
            adj[road[0]].push_back(make_pair(road[1],road[2]));
            adj[road[1]].push_back(make_pair(road[0],road[2]));
        }
        int V = adj.size();
        vector<long long> dist(V,LONG_MAX);
        vector<int> ways(V,0);
        ways[0] = 1;
        dist[0] = 0;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push(make_pair(0,0));
        while(!pq.empty()){
            pair<int,int> P = pq.top();
            pq.pop();
            if(dist[P.second]<P.first){
                continue;
            }
            for(auto node: adj[P.second]){
                if((dist[P.second]+node.second) < dist[node.first]){
                    dist[node.first] = node.second + dist[P.second];
                    pq.push(make_pair(dist[node.first],node.first));
                    ways[node.first] = ways[P.second]%MOD;
                }
                else if((dist[P.second]+node.second) == dist[node.first]){
                    ways[node.first] = (ways[node.first] + ways[P.second])%MOD;
                }
            }
        }
        return ways[V-1]%MOD;
    }
};