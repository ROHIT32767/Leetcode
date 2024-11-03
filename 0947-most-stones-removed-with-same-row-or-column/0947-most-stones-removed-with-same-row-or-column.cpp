class DSU{
        public:
        vector<int> parent,size;
        
        DSU(int n){
            parent.resize(n,0);
            size.resize(n,1);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        
        int find_parent(int x){
            if(parent[x]==x){
                return x;
            }
            return find_parent(parent[x]);
        }
        
        void Union(int x,int y){
            int parent_x = find_parent(x);
            int parent_y = find_parent(y);
            if(parent_x==parent_y){
                return;
            }
            int size_x = size[x];
            int size_y = size[y];
            if(size_x<size_y){
                parent[parent_x] = parent_y;
                size[parent_y] += size[parent_x];
            }
            else{
                parent[parent_y] = parent_x;
                size[parent_x] += size[parent_y];
            }
        }
    
        int get_size(){
            int n = parent.size();
            int count = 0;
            for(int i=0;i<n;i++){
                if(find_parent(i)==i){
                    count++;
                }
            }
            return count;
        }
    
        int max_size(){
            int MAX = 1;
            int n = parent.size();
            int count = 0;
            for(int i=0;i<n;i++){
                if(find_parent(i)==i){
                    MAX = max(MAX,size[i]);
                }
            }
            return MAX;
        }
    
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        map<int,int> x;
        map<int,int> y;
        int n = stones.size();
        DSU DS(n);
        for(int i=0;i<n;i++){
            if(x.find(stones[i][0])==x.end()){
                x[stones[i][0]] = i;
            }
            else{
                DS.Union(x[stones[i][0]],i);
            }
            if(y.find(stones[i][1])==y.end()){
                y[stones[i][1]] = i;
            }
            else{
                DS.Union(y[stones[i][1]],i);
            }
        }
        return n-DS.get_size();
    }
};