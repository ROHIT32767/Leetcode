class Solution {
public:
    bool DFS(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& path_vis){
        vis[node] = 1;
        path_vis[node] = 1;
        for(auto i:adj[node]){
            if(!vis[i]){
                bool flag = DFS(i,adj,vis,path_vis);
                if(!flag){
                    return false;
                }
            }
            else if(vis[i] && path_vis[i]){
                return false;
            }
        }
        path_vis[node] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int size = numCourses;
        vector<vector<int>> adj(size,vector<int>());
        int preq_size = prerequisites.size();
        for(int i=0;i<preq_size;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> prev(size,0);
        vector<int> visited(size,0);
        for(int i=0;i<size;i++){
            if(!visited[i]){
                bool flag = DFS(i,adj,visited,prev);
                if(!flag){
                    return false;
                }
            }
        }
        return true;
    }
};