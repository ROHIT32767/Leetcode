class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(auto time:times){
            adj[time[0]-1].push_back(make_pair(time[2],time[1]-1));
        }
        int src = k-1;
        int V = n;
        vector<int> dist(V,1e9);
        dist[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(0,src));
        while(!pq.empty()){
            pair<int,int> P = pq.top();
            pq.pop();
            for(auto node: adj[P.second]){
                if((dist[P.second]+node.first) < dist[node.second]){
                    dist[node.second] = node.first + dist[P.second];
                    pq.push(make_pair(dist[node.second],node.second));
                }
            }
        }
        int max_time = -1;
        for(int i=0;i<V;i++){
            if(i!=k-1){
                max_time = max(max_time,dist[i]);
            }
        }
        return max_time==1e9 ? -1 : max_time;
    }
};