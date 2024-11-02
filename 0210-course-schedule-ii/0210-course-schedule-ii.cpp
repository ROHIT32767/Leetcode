class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int size = numCourses;
        vector<vector<int>> adj(size,vector<int>());
        int preq_size = prerequisites.size();
        for(int i=0;i<preq_size;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> indegree(size,0);
        for(int i=0;i<adj.size();i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int> Q;
        for(int i=0;i<size;i++){
            if(indegree[i]==0){
                Q.push(i);
            }
        }
        vector<int> vect;
        while(!Q.empty()){
            int front = Q.front();
            Q.pop();
            vect.push_back(front);
            for(auto node:adj[front]){
                indegree[node]--;
                if(indegree[node]==0){
                    Q.push(node);
                }
            }
        }
        if(vect.size()!=size){
            return vector<int>();
        }
        reverse(vect.begin(),vect.end());
        return vect;
    }
};